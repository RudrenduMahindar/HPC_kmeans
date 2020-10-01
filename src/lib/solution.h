#ifndef TEMPLATE_SOLUTION_H
#define TEMPLATE_SOLUTION_H

#include <string>
#include <vector>
#include <cmath>
#include <mutex>
#include <fstream>
using namespace std;

#define h 800
#define w 800
#define input_file  "input.raw"
#define output_file "output.raw"
#define num_of_clusters 6

struct thread_data{
  int	thread_id;
  int k;  // no. of elements for this thread
  int sum[6];
  int no[6];
};

class Solution {
public:
  void* kmeans(void*);
  void read_image();
  void write_image();
  void do_cluster();
  unsigned char *img;
  int num_of_threads;
};

#endif