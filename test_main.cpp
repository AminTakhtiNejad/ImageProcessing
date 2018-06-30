#include <iostream>
#include <iomanip>
using namespace std;

#include <stdio.h>
#include <string.h>

#include <hls_opencv.h> // header file of OpenCV I/O
#include "main.h"

int main() {

	IplImage* src = cvLoadImage("C:\\Users\\Amin\\Desktop\\face_fhd.jpg");
	IplImage* dst = cvCreateImage(cvGetSize(src), src->depth, src->nChannels);

	AXI_STREAM src_axi, dst_axi;
	IplImage2AXIvideo(src, src_axi);
	pixelq_op(src_axi, dst_axi, src->height, src->width);
	AXIvideo2IplImage(dst_axi, dst);

	cvSaveImage("C:\\Users\\Amin\\Desktop\\result_1080p.bmp", dst);
	cvReleaseImage(&src);
	cvReleaseImage(&dst);

	return (1);

}
