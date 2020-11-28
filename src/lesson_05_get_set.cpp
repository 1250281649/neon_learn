#include <neon_learn.h>

int main()
{
    printf("===========Neon Get & Set Instructions===========\n");
    int8_t  data8[16] = TEST_DATA;
    {
        printf("vget_lane_s8(Vector M):\n");
        int8x16_t s8_1 = vld1q_s8(data8);
        print_neon<int8x16_t, int8_t>(s8_1, "int8x16_t:");

        // vgetq_lane_s3(int8x16_t, int lane)
        int8_t int8_lane3 = vgetq_lane_s8(s8_1, 3);
        printf("int8x16_t 3 lanel:%d\n", int8_lane3);

        int8x8_t s8_low = vget_low_s8(s8_1);
        print_neon<int8x8_t, int8_t>(s8_low, "s8_low:");

        int8x8_t s8_high = vget_high_s8(s8_1);
        print_neon<int8x8_t, int8_t>(s8_high, "s8_high:");

        int8x8_t s8_set = vset_lane_s8((int8_t)21, s8_high, 3);
        print_neon<int8x8_t, int8_t>(s8_set, "s8_set:");
    }

    return 0;
}