#include <iostream>
#include "src/lib/solution.h"

int main()
{
    Solution s;
    s.read_image();
    cluster_mean = new int[num_of_clusters]; //0 -- (num_of_cluster-1) indices
    //reference of creating mutiple threads: https://stackoverflow.com/questions/10661792/how-to-create-an-array-of-thread-objects-in-c11
	mythreads = new thread[num_of_threads]; //handle to each thread object
	thread_data_array = new thread_data[num_of_threads];//holds parameters for each thread

    //setting initial cluster mean values
    cluster_mean[0] = 0;
	cluster_mean[1] = 65;
	cluster_mean[2] = 100;
	cluster_mean[3] = 125;
	cluster_mean[4] = 190;
	cluster_mean[5] = 255;
    
    s.do_cluster();
    s.write_image();
    
    delete(cluster_mean);
    delete(mythreads);
    delete(thread_data_array);

    return EXIT_SUCCESS;
}