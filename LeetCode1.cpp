#include <stdio.h>

int main()
{
    char nums[] = {1, 2, 3, 4, 52, 55, 7, 8, 9};
    int target = 57;
    int left = 0;

    //int right = strlen(nums) / nums[0] - 1;
    int right = sizeof(nums) / nums[0] - 1;
    int x = nums[left] + nums[right];
    int i = 0;
    int o = 0;
    //printf("%d", right);
    for (o = 0; o < right; o++)
    {

        for (i = 1; i < right; i++)
        {
            if (nums[o] + nums[i] == target)
            {
                if (o > i)
                {
                    printf("[%d,%d]\n", o, i);
                    //printf("right");
                    break;
                }
            }
        }
    }
    return 0;
}