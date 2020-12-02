#include <stdio.h>
#include <arm_neon.h>
#include <neon_learn.h>

int main()
{
    printf("===========Neon Basic Instructions===========\n");
    {
        printf("Result_t vcreate_type(Scalar_t N)\n");
        int8x8_t s8_8 = vcreate_s8(5);
        print_neon_value_hex<int8x8_t>(s8_8);
        int16x4_t s16_4 = vcreate_s16(0x0102030405060708);
        print_neon_value_hex<int16x4_t>(s16_4);
        int32x2_t s32_2 = vcreate_s32(7);
        print_neon_value_hex<int32x2_t>(s32_2);
    }

    {
        printf("Result_t vdup_n_type(Scalar_t N)\n");
        int8x8_t s8_8_d = vdup_n_s8(8);
        print_neon_value_hex<int8x8_t>(s8_8_d);
        int16x4_t s16_4_d = vdup_n_s16(9);
        print_neon_value_hex<int16x4_t>(s16_4_d);
        int32x2_t s32_2_d = vdup_n_s32(10);
        print_neon_value_hex<int32x2_t>(s32_2_d);

        int8x8_t vdata={0,1,2,3,4,5,6,7};
        int8x8_t s8_8_lane = vdup_lane_s8(vdata, 3);
        print_neon<int8x8_t, int8_t>(s8_8_lane, "vdup_lane:");
    }

    {
        printf("Result_t vmov_n_type(Scalar_t N)\n");
        int8x8_t s8_8_m = vmov_n_s8(11);
        print_neon<int8x8_t, int8_t>(s8_8_m);
        int16x4_t s16_4_m = vmov_n_s16(12);
        print_neon<int16x4_t, int16_t>(s16_4_m);
        int32x2_t s32_2_m = vmov_n_s32(13);
        print_neon<int32x2_t, int32_t>(s32_2_m);
    }

    return 0;
}