#include <stdio.h>
#include <arm_neon.h>
#include <neon_learn.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>

#define LENGTH  64
void print_array(int *data, int len)
{
    for(int i=0; i<len; i++)
    {
        printf("%4d  ", data[i]);
        if(i%16==15)
            printf("\n");
    }
    printf("\n");
}

typedef struct DATA_INDEX
{
    int32_t index;
    int32_t data;
}DATA_INDEX;

int compare(const void *a, const void *b)
{
    return ((DATA_INDEX*)a)->data - ((DATA_INDEX*)b)->data;
}

int main()
{
    int32_t data[LENGTH] = {0};
    int32_t *p = data;
    for(int i=0; i<LENGTH; i++)
    {
        data[i] = rand()%255;
    }
    print_array(data, LENGTH);

    int32_t *data_index = (int32_t*)malloc(LENGTH*sizeof(DATA_INDEX));
    if(!data_index)
    {
        perror("can't alloc memory\n");
    }

    int32x4_t vdata;
    int32x4_t vindex;
    int32x4_t vindex_base = {0,1,2,3};
    int32x4_t int32_one = {1,1,1,1};
    int32_t index = 0;
    const int w_i = LENGTH/sizeof(int32x4_t);
    p = data;
    int32_t *p_out = data_index;
    for(int h=0; h<LENGTH; h+=4)
    {
        vdata = vld1q_s32(p);
        // printf("data :");
        // print_neon<int32x4_t, int32_t>(vdata);
        vindex = vmlaq_n_s32(vindex_base, int32_one, h);
        // printf("index:");
        // print_neon<int32x4_t, int32_t>(vindex);

        int32x4x2_t vout_data;
        vout_data.val[0] = vindex;
        vout_data.val[1] = vdata;
        p+= 4;
        vst2q_s32(p_out, vout_data);
        p_out+=8;
    }
    std::vector<DATA_INDEX> data_vec((DATA_INDEX*)data_index, (DATA_INDEX*)data_index+LENGTH);
    printf("data_vec size:%d\n", data_vec.size());
    std::qsort(data_vec.data(), data_vec.size(), sizeof(DATA_INDEX), compare);
    for(int i=0; i<LENGTH; i++)
    {
        printf("(%d, %d) ", data_vec[i].index, data_vec[i].data);
    }

    free(data_index);
    return 0;
}