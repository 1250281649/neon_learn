#include <neon_learn.h>
#include "tools/utils.h"

#define IMAGE_HEIGHT (360)
#define IMAGE_WIDTH  (640)
#define W_INC        (8)

int RGB_Packed2Planar_neon(uint8_t * packed, uint8_t* planar, int height, int width)
{
    uint8_t *p_img = (uint8_t*)packed;

    uint8_t *p_r = planar;
    uint8_t *p_g = planar + height*width;
    uint8_t *p_b = planar + height*width * 2;

    for(int i = 0; i<height*width; i+=W_INC)
    {
        uint8x8x3_t vdata = vld3_u8(p_img);

        vst1_u8(p_r, vdata.val[0]);
        p_r += W_INC;
        vst1_u8(p_g, vdata.val[1]);
        p_g += W_INC;
        vst1_u8(p_b, vdata.val[2]);
        p_b += W_INC;
        p_img += W_INC * 3;
    }

    return 0;
}

int RGB_Packed2Planar_neonq(uint8_t * packed, uint8_t* planar, int height, int width)
{
    uint8_t *p_img = (uint8_t*)packed;

    uint8_t *p_r = planar;
    uint8_t *p_g = planar + height*width;
    uint8_t *p_b = planar + height*width * 2;
    const int inc = W_INC*2;

    for(int i = 0; i<height*width; i+=inc)
    {
        uint8x16x3_t vdata = vld3q_u8(p_img);

        vst1q_u8(p_r, vdata.val[0]);
        vst1q_u8(p_g, vdata.val[1]);
        vst1q_u8(p_b, vdata.val[2]);
        p_r += inc;
        p_g += inc;
        p_b += inc;
        p_img += inc * 3;
    }

    return 0;
}

int RGB_Packed2Planar(uint8_t * packed, uint8_t* planar, int height, int width)
{
    uint8_t *p_img = (uint8_t*)packed;

    uint8_t *p_r = planar;
    uint8_t *p_g = planar + height*width;
    uint8_t *p_b = planar + height*width * 2;

    for(int i = 0; i<height*width; i++)
    {
        *p_r++ = *p_img++;
        *p_g++ = *p_img++;
        *p_b++ = *p_img++;
    }

    return 0;
}

int main()
{
    printf("===========Neon RGB Packed -> RGB Planar===========\n");
    void *img_data = NULL;
    int img_size =0;

    ReadBinaryFile(GetDataPath("images/cat_640x360_rgb_packed.bin").c_str(), &img_data, &img_size);
    printf("img size:%d\n", img_size);

    uint8_t *p_out = (uint8_t*)malloc(img_size);
    if(!p_out)
    {
        perror("Can't malloc memory\n");
        exit(1);
    }

    TIME_COST(RGB_Packed2Planar_neon((uint8_t*)img_data, p_out, IMAGE_HEIGHT, IMAGE_WIDTH), "neon");
    WriteBinaryFile(GetDataPath("images/cat_640x360_rgb_planar.bin").c_str(), p_out, img_size);

    TIME_COST(RGB_Packed2Planar_neonq((uint8_t*)img_data, p_out, IMAGE_HEIGHT, IMAGE_WIDTH), "neonq");
    WriteBinaryFile(GetDataPath("images/cat_640x360_rgb_planar_q.bin").c_str(), p_out, img_size);

    TIME_COST(RGB_Packed2Planar((uint8_t*)img_data, p_out, IMAGE_HEIGHT, IMAGE_WIDTH), "C ");
    WriteBinaryFile(GetDataPath("images/cat_640x360_rgb_planar_c.bin").c_str(), p_out, img_size);

    free(p_out);
    free(img_data);
    return 0;
}