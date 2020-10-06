#include "solution.h"
#include <iostream>
using namespace std;

mutex thread_mutex;
condition_variable thread_cv;  

int find_min(int d1,int d2,int d3,int d4,int d5, int d6)
{
	int i;
	int min[] = {d1,d2,d3,d4,d5,d6};
	int x = min[0];
	int pos = 0;
	for(i = 1; i <= 5; i++)
	{
		if(min[i] < x)
		{
		   	x = min[i];
		   	pos = i;
		}
	}
	return pos;
}

int calc_dist(unsigned char b,int c)
{
	return pow(((int)b-c), 2);
}

void Solution::read_image()
{
  	img = new unsigned char[h*w];
  	FILE *fp = nullptr;
	if (!(fp = fopen(input_file,"rb"))) {
		cout << "Cannot open file: " << input_file << endl;
		exit(1);
	}
	fread(img, sizeof(unsigned char), h*w, fp);
	fclose(fp);
  	cout << "File Read Succesfully" << endl;
}

void Solution::write_image()
{
	FILE *fp;
	if (!(fp = fopen(output_file,"wb"))) {
		cout << "Cannot open file: " << output_file << endl;
		exit(1);
	}
	fwrite(img, sizeof(unsigned char), h*w, fp);
	fclose(fp);

	cout << "File Saved Succesfully" << endl;
}

/*dummy function for multithreading*/
void kmeans(thread_data* arg)
{
	int i, j, k, l, d1, d2, d3, d4, d5, d6, min;
	int start_index = (arg->thread_id)*(arg->limit);
	int end_index = ((arg->thread_id)+1)*(arg->limit);
	int s,n;
	for(i = 0 ; i < max_iterations ; i++)
	{
		/*before adding elements, no. of items in a cluster, initialize at the beginning of 
		each iteration to get the correct value of cluster mean at the end of this iteration
		because cluster centroid is freshly calculated for each iteration*/
		for(k = 0 ; k < num_of_clusters; k++)
		{
			arg->sum[i] = 0;
			arg->no[i] = 0;	
		}
		for(j = start_index; j < end_index; j++)
		{	   
				d1 = calc_dist(img[j], cluster_mean[0]);
				d2 = calc_dist(img[j], cluster_mean[1]);
				d3 = calc_dist(img[j], cluster_mean[2]);
				d4 = calc_dist(img[j], cluster_mean[3]);
				d5 = calc_dist(img[j], cluster_mean[4]);
				d6 = calc_dist(img[j], cluster_mean[5]);
				min = find_min(d1,d2,d3,d4,d5,d6);
				arg->sum[min] += img[j];
				arg->no[min]++;
		}
		//this thread has finished clustering its elements for this iteration when it reaches here
		unique_lock<mutex> ul(thread_mutex);
		r++;
		if(r == num_of_threads)//last thread that reaches here for this iteration
		{
			r = 0;
			iteration_complete = true;
			/*get the mean of each cluster for each thread*/
			for(l = 0; l < num_of_clusters ; l++)
     			{	
     				s = n = 0;	
	   			for(j = 0; j < num_of_threads; j++)
	 			{
					s += thread_data_array[j].sum[l];
					n += thread_data_array[j].no[l];
	 		    	}
	 			cluster_mean[l] = s/n;
    			}
			ul.unlock();
    			thread_cv.notify_all(); 
    			ul.lock();
		}
		else if(r == 1)//first thread of this iteration resets this flag before going to wait in queue
		{
			iteration_complete = false;
		}
		// if blocked, ul.unlock() is automatically called.
    		// if unblocked, ul.lock() is automatically called.
    		thread_cv.wait(ul, []() { return iteration_complete; }); //return when flag is true
	}
}

void Solution::do_cluster()
{
	int i, j, d1, d2, d3, d4, d5, d6, min;
	
	r = 0;//goes up to num_of_threads 

	for(i = 0; i < num_of_threads ; i++)
	{
		thread_data_array[i].thread_id = i;
        	thread_data_array[i].limit = ((h*w)/num_of_threads);
		mythreads[i] = thread(kmeans, &thread_data_array[i]); // passing function, thread_parameters
	}
	for(i = 0; i < num_of_threads ; i++)
	{
		mythreads[i].join();	
	}
	for(j = 0; j < (h*w); j++) //copying cluster mean values to output image
	{
		d1 = calc_dist(img[j],cluster_mean[0]);
		d2 = calc_dist(img[j],cluster_mean[1]);
		d3 = calc_dist(img[j],cluster_mean[2]);
		d4 = calc_dist(img[j],cluster_mean[3]);
		d5 = calc_dist(img[j],cluster_mean[4]);
		d6 = calc_dist(img[j],cluster_mean[5]);
		min = find_min(d1,d2,d3,d4,d5,d6);
		img[j] = cluster_mean[min];
	}
}
