#include <neon_learn.h>
#include "tools/utils.h"

#define IMAGE_HEIGHT    (360)
#define IMAGE_WIDTH     (640)
#define GRAY_IMG_SIZE   (IMAGE_HEIGHT*IMAGE_WIDTH)
#define W_INC           (8)

// Grey= (R*76 + G*150 + B*30) >> 8

int RGB2Gray_neon(uint8_t * packed, uint8_t* gray, int height, int width)
{
    uint8_t *p_img = (uint8_t*)packed;

    uint8_t *p_o = gray;
    uint8x8_t r_corr = {76,76,76,76,76,76,76,76};
    uint8x8_t g_corr = {150,150,150,150,150,150,150,150};
    uint8x8_t b_corr = {30,30,30,30,30,30,30,30};
    int16x8_t shift_r = {-8,-8,-8,-8,-8,-8,-8,-8};

    for(int i = 0; i<height*width; i+=W_INC)
    {
        uint8x8x3_t vdata = vld3_u8(p_img);
        uint16x8_t vr = vmull_u8(r_corr, vdata.val[0]);
        uint16x8_t vg = vmlal_u8(vr, g_corr, vdata.val[1]);

        uint16x8_t vgray16 = vmlal_u8(vg, b_corr, vdata.val[2]);
        uint16x8_t vgray_8 = vrshlq_u16(vgray16, shift_r);
        uint8x8_t vgray = vqmovn_u16(vgray_8);

        vst1_u8(p_o, vgray);
        p_o += W_INC;
        p_img += W_INC * 3;
    }

    return 0;
}

int RGB2Gray(uint8_t * packed, uint8_t* gray, int height, int width)
{
    uint8_t *p_img = (uint8_t*)packed;

    uint8_t *p_o = gray;

    for(int i = 0; i<height*width; i++)
    {
        uint8_t r = *p_img++;
        uint8_t g = *p_img++;
        uint8_t b = *p_img++;
        *p_o++ = (r*76 + g*150 + b*30 + 128) >> 8;
        // printf("r=%d, g=%d, b=%d, gray=%d, %d\n", r, g, b, (r*76 + g*150 + b*30), (r*76 + g*150 + b*30+128) >> 8);
    }

    return 0;
}

int main()
{
    printf("===========Neon RGB -> Gray===========\n");
    void *img_data = NULL;
    int img_size =0;

    ReadBinaryFile(GetDataPath("images/cat_640x360_rgb_packed.bin").c_str(), &img_data, &img_size);
    printf("img size:%d\n", img_size);

    uint8_t *p_out = (uint8_t*)malloc(GRAY_IMG_SIZE);
    if(!p_out)
    {
        perror("Can't malloc memory\n");
        exit(1);
    }

    TIME_COST(RGB2Gray_neon((uint8_t*)img_data, p_out, IMAGE_HEIGHT, IMAGE_WIDTH), "neon");
    WriteBinaryFile(GetDataPath("images/cat_640x360_gray.bin").c_str(), p_out, GRAY_IMG_SIZE);

    TIME_COST(RGB2Gray((uint8_t*)img_data, p_out, IMAGE_HEIGHT, IMAGE_WIDTH), "C ");
    WriteBinaryFile(GetDataPath("images/cat_640x360_gray_c.bin").c_str(), p_out, GRAY_IMG_SIZE);

    free(p_out);
    free(img_data);
    return 0;
}