#include <stdio.h>
#include <stdlib.h>

static void locate(int array[], int )

static int bsearch(int array[], int low, int high, int target)
{
    while(high >= low)
	{
	    int pos =  low + ((high-low)>>1);
		if (array[pos] == target )
		    return pos;
	    if(array[pos]<target)
		    low = pos + 1;
		else
		    high = pos - 1;
	}
	return -1;
}

static int esearch(int array[], int low, int high, int target)
{
   int expon = 1;
   if (!array || high<low )
   {
       printf("ERROR:invalid array!\n");
	   return -2;
   }
   if (target < array[low] || target > array[high])
   {
       return -1;
   }
   while (array[low + expon - 1] < target)
   {
       expon = (low + expon*2 > high)?high:expon*2;
   }
   low = low + expon/2;
   high = low + expon -1;
   return bsearch(array,low,high,target);
}

int main(int argc,char *argv[])
{
}
