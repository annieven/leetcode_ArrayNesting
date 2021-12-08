#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int subTest(int* nums, int numsSize, unsigned char* invalid, int indexStart){
    int result[numsSize];
	int index = indexStart;
    int i = 0;

	memset(result, 0, sizeof(result));

	result[0] = nums[index];
	invalid[nums[index]] = 1;

	for (i = 1; i < numsSize; i ++)
	{
		index = nums[result[i-1]];

		if (invalid[index] == 1)
			break;
		else
			invalid[index] = 1;
		
		result[i] = nums[result[i-1]];
	}

	return i;
}

int arrayNesting(int* nums, int numsSize){
	unsigned char invalid[numsSize];
    int i, size, longest;
	int index = 0;
	
	memset(invalid, 0, sizeof(invalid));
	longest = subTest(nums, numsSize, invalid, index);

	while (index < numsSize)
	{
		for (i = index; i < numsSize; i ++)
		{
			if (invalid[i] == 0)
				break;
		}
		
		if (i >= numsSize)
			break;

		index = i;		
		size = subTest(nums, numsSize, invalid, index);
		if (longest < size)
			longest = size;
	}

	return longest;
}

int main(int argc, char **argv)
{
	int array1[] = {5, 4, 0, 3, 1, 6, 2};
	printf("len1 = %d\n", arrayNesting(array1, sizeof(array1) / sizeof(int)));

	printf("--------\n");

	int array2[] = {0, 1, 2};
	printf("len2 = %d\n", arrayNesting(array2, sizeof(array2) / sizeof(int)));

	printf("--------\n");

	int array3[] = {0, 2, 1};
	printf("len3 = %d\n", arrayNesting(array3, sizeof(array3) / sizeof(int)));

	return 0;
}
