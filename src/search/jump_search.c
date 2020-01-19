#include <stdlib.h>
#include <stdio.h>
#include <math.h>
static jsearch(int array[],size_t n, int target);

static int jsearch (int array[],size_t n, int target)
{
    int step;
	int i;
    if(!array || n == 0)
	{
        printf("ERROR:the array is invalid!\n");
		return;
	}
    step = sqrt(n);
    i = step;
 
	while (array[i-1]<target)
	{
        if (i == n)
		   return -1;
		i = (i+step>n)?n:i+step;
	}

    for ( int j = i-step; j<=i-1; j++ )
	{
	    if (array[j] == target)
		{
		    return j;
		}
		if (array[j] > target)
		{
		    return -1;
		}
	}
    return -1;
}







int main(int argc,char *argv[])
{
}
