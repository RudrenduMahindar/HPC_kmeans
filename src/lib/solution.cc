#include "solution.h"
#include <iostream>
using namespace std;

std::mutex m;

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

void Solution::do_cluster()
{

//TODO: for each thread do kmeans on assigned elements


}