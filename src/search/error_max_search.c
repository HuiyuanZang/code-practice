/*
*Given an array of integers which is initially increasing and then decreasing, find the maximum value* in the array.
* This is example you cannot use binary search to locate max in the array non-distinct number
*/



#include <stdlib.h>
#include <stdio.h>


static int rightmost_max_search(int array[], size_t n)
{
    int l,h,m;
	l = 0;
	h = n-1;
    while ( h >= l )
	{
	    m = l + ((h-l)>>1);
        //m is already the end of array
		if ( m == n-1 && array[m] >= array[m-1] )
		   return n-1;
		//if m is not end of array, but we find decreasing turn point as m
		if ( array[m] >= array[m-1] && array[m] > array[m+1] )
		   return m;
        
		if ( array[m] >= array[m-1] )
		{
		   l = m+1;
		}
		else
		   h = m;
	}
	return m;
}


static int leftmost_max_search(int array[], size_t n)
{
    int l,h,m;
	l = 0;
	h = n-1;
    while ( h >= l )
	{
	    m = l + ((h-l)>>1);
		printf("l=%d;m=%d;h=%d \n",l,m,h);
        //m is already the end of array
		if ( m == 0 && array[m] >= array[m+1] )
		   return 0;
		//if m is not end of array, but we find increasing turn point as m
		if ( array[m] >= array[m+1] && array[m] > array[m-1] )
		   return m;
        
		if ( array[m] >= array[m+1] )
		{
		   h = m-1;
		}
		else
		   l = m;
	}
	return m;
}




static int  max_search(int array[],size_t n)
{
    int right, left;
    if( !array || n == 0 )
	{
	    printf("ERROR:Invalid array!\n");
		return -1;
	}
    if ( n == 1 )
	   return 0;
	if ( n == 2 )
	   return array[0]>=array[1]?0:1;
    left = leftmost_max_search(array,n);
	right = rightmost_max_search(array,n);
	printf("max from %d to %d\n",left,right);
	return left;
}



int main(int argc,char *argv[])
{
    int arr[] = {-9,-9,-6,-5,0,4,7,9,9,8,6,6,4,3,0};
	max_search(arr,sizeof(arr)/sizeof(arr[0]));
}
