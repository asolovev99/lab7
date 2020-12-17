#define _CRT_SECURE_NO_WARNINGS
#define length_array 10

#include<stdio.h>
//#include<time.h>

int main()
{
	int numbers[length_array];
	int index_min;
	int i = 0;

	//srand(time(0));
	for (i = 0; i < length_array; i++)
	{
		//numbers[i] = (int)rand();
		scanf("%d", &numbers[i]);
	}

	printf("Current permutation:\n");
	for (i = 0; i < length_array; i++)
	{
		//numbers[i] = (int)rand();
		printf("%d: %d\n", i, numbers[i]);
	}

	for (i = length_array - 2; (i >= 0) && (numbers[i] > numbers[i + 1]); i--);
	if (i < 0) 
	{
		printf("No next permutation");
	}
	else
	{
		index_min = i + 1;
		for (int j = i + 2; j < length_array; j++)
		{
			if ((numbers[index_min] > numbers[j]) && (numbers[j] > numbers[i]))
			{
				index_min = j;
			}
		}

		int temp = numbers[index_min];
		numbers[index_min] = numbers[i];
		numbers[i] = temp;

		for (int j = 0; j < (length_array - i - 1) / 2; j++)
		{
			int temp = numbers[j + i + 1];
			numbers[j + i + 1] = numbers[length_array - j - 1];
			numbers[length_array - j - 1] = temp;
		}

		printf("Next permutation:\n");
		for (i = 0; i < length_array; i++)
		{
			printf("%d: %d\n", i, numbers[i]);
		}
	}

	return 0;
}