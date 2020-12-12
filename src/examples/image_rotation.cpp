#include <neon_learn.h>
#include "tools/utils.h"

#define IMAGE_HEIGHT    (360)
#define IMAGE_WIDTH     (640)
#define IMG_SIZE        (IMAGE_HEIGHT*IMAGE_WIDTH)
#define W_INC           (8)

int GrayRotation90_NEON(uint8_t * in, uint8_t* out, int height, int width)
{
    uint8x8_t vone = {1,1,1,1,1,1,1,1};
    uint8x8_t index_0 = {28, 20, 12, 4, 24, 16, 8, 0};
    uint8x8_t index_1 = vadd_u8(index_0, vone);
    uint8x8_t index_2 = vadd_u8(index_1, vone);
    uint8x8_t index_3 = vadd_u8(index_2, vone);
    uint8x8_t index_4 = {12, 13, 14, 15, 4, 5, 6 ,7};
    uint8x8_t index_5 = {8, 9, 10, 11, 0, 1, 2, 3};
    uint8x8x4_t mat0;
    uint8x8x4_t mat1;
    uint8x8x4_t temp0;
    uint8x8x4_t temp1;
    uint8x8x2_t out0;
    uint8x8x2_t out1;
    uint8x8x2_t out2;
    uint8x8x2_t out3;

    int x = 0, y = 0;
    for(y=0; y<height; y+=8)
    {
        for(x=0; x<width; x+=8)
        {
            mat0.val[0] = vld1_u8(in + y*width+x);
            mat0.val[1] = vld1_u8(in + (y+1)*width+x);
            mat0.val[2] = vld1_u8(in + (y+2)*width+x);
            mat0.val[3] = vld1_u8(in + (y+3)*width+x);
            mat1.val[0] = vld1_u8(in + (y+4)*width+x);
            mat1.val[1] = vld1_u8(in + (y+5)*width+x);
            mat1.val[2] = vld1_u8(in + (y+6)*width+x);
            mat1.val[3] = vld1_u8(in + (y+7)*width+x);

            temp0.val[0] = vtbl4_u8(mat0, index_0);
            temp0.val[1] = vtbl4_u8(mat0, index_1);
            temp0.val[2] = vtbl4_u8(mat0, index_2);
            temp0.val[3] = vtbl4_u8(mat0, index_3);

            temp1.val[0] = vtbl4_u8(mat1, index_0);
            temp1.val[1] = vtbl4_u8(mat1, index_1);
            temp1.val[2] = vtbl4_u8(mat1, index_2);
            temp1.val[3] = vtbl4_u8(mat1, index_3);

            out0.val[0] = temp0.val[0];
            out0.val[1] = temp1.val[0];
            out1.val[0] = temp0.val[1];
            out1.val[1] = temp1.val[1];
            out2.val[0] = temp0.val[2];
            out2.val[1] = temp1.val[2];
            out3.val[0] = temp0.val[3];
            out3.val[1] = temp1.val[3];
            mat0.val[0] = vtbl2_u8(out0, index_4); // line 0
            mat0.val[1] = vtbl2_u8(out0, index_5); // line 4
            mat0.val[2] = vtbl2_u8(out1, index_4); // line 1
            mat0.val[3] = vtbl2_u8(out1, index_5); // line 5

            mat1.val[0] = vtbl2_u8(out2, index_4); // line 2
            mat1.val[1] = vtbl2_u8(out2, index_5); // line 6
            mat1.val[2] = vtbl2_u8(out3, index_4); // line 3
            mat1.val[3] = vtbl2_u8(out3, index_5); // line 7

            // store out data in order: 0, 4, 1, 5, 2, 6, 3, 7
            vst1_u8(out + (x + 0) * height + height-8 - y, mat0.val[0]); // line 0
            vst1_u8(out + (x + 1) * height + height-8 - y, mat0.val[2]); // line 1
            vst1_u8(out + (x + 2) * height + height-8 - y, mat1.val[0]); // line 2
            vst1_u8(out + (x + 3) * height + height-8 - y, mat1.val[2]); // line 3
            vst1_u8(out + (x + 4) * height + height-8 - y, mat0.val[1]); // line 4
            vst1_u8(out + (x + 5) * height + height-8 - y, mat0.val[3]); // line 5
            vst1_u8(out + (x + 6) * height + height-8 - y, mat1.val[1]); // line 6
            vst1_u8(out + (x + 7) * height + height-8 - y, mat1.val[3]); // line 7
        }
    }

    return 0;
}

int GrayImageRotation90(uint8_t * in, uint8_t* out, int height, int width)
{
    uint8_t *p_img = (uint8_t*)in;
    uint8_t *p_o = out;

    for(int h=0; h<height; h++)
    {
        for(int w=0; w<width; w++)
        {
            *(p_o + w*height + height-1-h) = *p_img++;
        }
    }

    return 0;
}

int main()
{
    printf("===========Neon RGB Packed Rotation===========\n");
    void *img_data = NULL;
    int img_size =0;

    ReadBinaryFile(GetDataPath("images/cat_640x360_gray.bin").c_str(), &img_data, &img_size);
    printf("img size:%d\n", img_size);
    if(IMG_SIZE != img_size)
    {
        perror("image format error!\n");
        return -1;
    }

    uint8_t *p_c = (uint8_t*)malloc(IMG_SIZE);
    uint8_t *p_n = (uint8_t*)malloc(IMG_SIZE);
    if((!p_c) || (!p_n))
    {
        perror("Can't malloc memory\n");
        exit(1);
    }

    TIME_COST(GrayRotation90_NEON((uint8_t*)img_data, p_n, IMAGE_HEIGHT, IMAGE_WIDTH), "neon");
    WriteBinaryFile(GetDataPath("output/cat_640x360_R90_n.bin").c_str(), p_n, IMG_SIZE);

    TIME_COST(GrayImageRotation90((uint8_t*)img_data, p_c, IMAGE_HEIGHT, IMAGE_WIDTH), "C ");
    WriteBinaryFile(GetDataPath("output/cat_640x360_R90_c.bin").c_str(), p_c, IMG_SIZE);

    free(p_c);
    free(p_n);
    free(img_data);
    return 0;
}