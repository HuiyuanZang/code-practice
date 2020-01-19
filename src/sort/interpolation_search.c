#include <stdlib.h>
#include <stdio.h>

static int interpolation(int array[], int low, int high, int target)
{
    return low + (target - array[low])*((double)(high - low)/(array[hight] - array[low]));
}

static int isearch_r(int array[],int low, int high, int target)
{
    if (!array)
	if (hight >= low)
	{
	     int pos = interpolation(array,low,high,target);
		 if(array[pos] == target)
		    return pos;
		 if(array[pos]< target)
		    return isearch(array,pos+1, high, target);
		 return isearch(array,low,pos-1);
	}
	return -1;
}


static int isearch_i(int array[], int low, int high, int target)
{
    if (!array || high < low )
    {
	    printf("ERROR:array is invalid\n");
		return -1;
	}
	while(high>=low)
	{
	    int pos = interpolation(array,low,high,target);
		if(array[pos] == target)
		  return pos;
		else if (array[pos] < target)
		    low = pos + 1;
		else
		    high = pos - 1;
	}
	return -1;
}


int main(int argc, char *argv[])
{

}
