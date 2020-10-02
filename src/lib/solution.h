#ifndef TEMPLATE_SOLUTION_H
#define TEMPLATE_SOLUTION_H

#include <string>
#include <vector>
#include <cmath>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <fstream>
using namespace std;

#define h 800
#define w 800
#define input_file  "input.raw"
#define output_file "output.raw"
#define num_of_clusters 6
#define max_iterations 50
#define num_of_threads 4

unsigned char *img;
int* cluster_mean;
thread* mythreads;
struct  thread_data  *thread_data_array;
int r; //count of threads which have completed work in this iteration
bool iteration_complete = false;

struct thread_data{
  int	thread_id; //get this thread id 
  int limit;  // no. of elements for this thread
  int sum[num_of_clusters]; //added matrix element to this cluster
  int no[num_of_clusters]; //number of elements added to this cluster
};

class Solution {
public:
  void read_image();
  void write_image();
  void do_cluster();
  //int num_of_threads;
};

#endif