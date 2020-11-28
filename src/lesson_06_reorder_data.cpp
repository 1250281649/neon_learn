#include <neon_learn.h>

int main()
{
    printf("===========Neon Get & Set Instructions===========\n");
    int8_t  data8[16] = TEST_DATA;
    {
        int8x8_t s8_1 = vld1_s8(data8);
        print_neon<int8x8_t, int8_t>(s8_1, "vdata1:");
        int8x8_t s8_2 = vld1_s8(&data8[8]);
        print_neon<int8x8_t, int8_t>(s8_2, "vdata2:");

        int8x8_t s8_reorder = vext_s8(s8_1, s8_2, 3);
        print_neon<int8x8_t, int8_t>(s8_reorder, "vdata3:");
    }

    return 0;
}