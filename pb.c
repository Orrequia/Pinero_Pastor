#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LUCKY_NUMBER 7
#define MAX_WHITE_BALL 59
#define MAX_POWER_BALL 39
static int my_sort_func(const void* p1, const void* p2)
{
int v1 = *((int *) p1);
int v2 = *((int *) p2);
if (v1 < v2)
{
return -1;
}
else if (v1 > v2)
{
return 1;
}
else
{
return 0;
}
}
int calculate_result(int white_balls[5], int power_ball)
{
for (int i=0; i<5; i++)
{
...
return -1;
}
qsort(white_balls, 5, sizeof(int), my_sort_func);
return 0;
}

int main(int argc, char** argv)
{
	int balls[6];
	int count_balls = 0;
	int favorite = 0;

	for (int i=1; i<argc; i++)
	{

		const char* arg = argv[i];
		if ('-' == arg[0])
		{
			if (0 == strcmp(arg, "-favorite"))
			{
				favorite = 1;
			}
			else
			{
				goto usage_error;
			}
		}
		else
		{
			char* endptr = NULL;
			long val = strtol(arg, &endptr, 10);
			if (*endptr)
			{
				goto usage_error;
			}
			balls[count_balls++] = (int) val;
		}
	}

	if (6 != count_balls)
	{
		goto usage_error;
	}

	int power_ball = balls[5];

	int result = calculate_result(balls, power_ball);

	if (result < 0)
	{
		goto usage_error;
	}

	if (LUCKY_NUMBER == power_ball)
	{
		result = result * 2;
	}

	if (favorite)
	{
		result = result * 2;
	}

	printf("%d percent chance of winning\n", result);

	return 0;

usage_error:
	fprintf(stderr, "Usage: %s [-favorite] (5 white balls)
power_ball\n", argv[0]);
	return -1;
}
