#include <neon_learn.h>
#include <string.h>

int main()
{
    printf("===========Neon Store Instructions===========\n");
    int8_t data[16] = {0};
    {
        printf("vst[x]_type(Scalar_t *N) x=1\n");
        int8x8_t s8_1 = vdup_n_s8(5);
        vst1_s8(data, s8_1);
        print_neon_value_hex<int8x8_t>(s8_1);
        print_array<int8_t>(data, sizeof(data));
    }

    {
        printf("vst[x]_lane_type(Scalar_t *N, Scalar_t *M, int lane) x=1\n");
        memset(data, 0, sizeof(data));
        int8x8_t s8_2 = vdup_n_s8(6);
        vst1_lane_s8(data, s8_2, 2);
        print_neon_value_hex<int8x8_t>(s8_2);
        print_array<int8_t>(data, sizeof(data));       
    }

    return 0;
}