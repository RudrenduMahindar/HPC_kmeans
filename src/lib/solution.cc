#include "solution.h"
#include <iostream>
using namespace std;

mutex m;
condition_variable cv;  

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
void kmeans(int id)
{

}

void Solution::do_cluster()
{
	//reference of creating mutiple threads: https://stackoverflow.com/questions/10661792/how-to-create-an-array-of-thread-objects-in-c11
	thread mythreads[4]; 
	for(int i = 0; i < 4 ; i++)
	{
		mythreads[i] = thread(kmeans, i); // passing function, thread_id
	}
	for(int i = 0; i < 4 ; i++)
	{
		mythreads[i].join();	
	}
}