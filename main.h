#ifndef _PIXEL_OP_H_
#define _PIXEL_OP_H_

#include "ap_int.h"
#include "hls_video.h"

#define MAX_HEIGHT 1080
#define MAX_WIDTH 1920

typedef ap_axiu<24, 1, 1, 1> PIXEL;
typedef hls::stream<PIXEL> AXI_STREAM;
typedef hls::Scalar<3, unsigned char> RGB_PIXEL;
typedef hls::Mat<MAX_HEIGHT, MAX_WIDTH, HLS_8UC3> RGB_IMAGE;

void pixelq_op(AXI_STREAM& src_axi, AXI_STREAM& dst_axi, int rows, int cols);

#endif // _PIXEL_OP_H_
