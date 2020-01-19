/*
*Given an array of n distict integer number and sorted in the acending order, try to find 
*array[i]  == i; otherwise return -1
*/




#include <stdlib.h>
#include <stdio.h>



static int fixpoint_search(int array[], size_t n)
{
    int l, h, m;
	if ( !array || n == 0 )
	{
	    printf("ERROR:Invalid array!\n");
		return -1;
	}
    l = 0;
	h = n-1;
	while( l<=h )
	{
        m = l+((h-l)>>1);
		if ( array[mid] == mid )
		{
		    return mid;
		}
		if ( array[mid] > mid )
		{
		     h = m-1;
		}
		else 
		{
		     l = m+1;
		}
	}
	return -1;
}



int main(int argc, char *argv[])
{
}
