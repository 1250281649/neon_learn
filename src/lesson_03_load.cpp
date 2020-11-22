#include <neon_learn.h>

int main()
{
    printf("===========Neon Load Instructions===========\n");
    int8_t data[32] = {
        0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,
        16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31};
    {
        printf("vld[x]_type(Scalar_t *N) x=1\n");
        int8x8_t s8_1 = vld1_s8(data);
        print_neon_valude<int8x8_t>(s8_1);
        
        int8x16_t s8_2 = vld1q_s8(data);
        print_neon_valude<int8x16_t>(s8_2);
    }

    {
        printf("vld[x]_type(Scalar_t *N) x=2\n");
        int8x8x2_t s8_1 = vld2_s8(data);
        print_neon_valude<int8x8x2_t>(s8_1);
        
        int8x16x2_t s8_2 = vld2q_s8(data);
        print_neon_valude<int8x16x2_t>(s8_2);
    }

    {
        printf("vld[x]_lane_type(Scalar_t *N Vector_t M, int n)\n");
        int8x8_t s8_lane_1;
        vld1_lane_s8(data, s8_lane_1, 1);
        print_neon_valude<int8x8_t>(s8_lane_1);

        int8x8x2_t s8_lane_2;
        vld2_dup_s8(data);
        print_neon_valude<int8x8x2_t>(s8_lane_2);
    }

    return 0;
}