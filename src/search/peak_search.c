/*
*@Brief: using divide and conquer to find peak in the array
* Definition: peak of array  array[i-1] <= array[i] >= array[i+1] if there exists i, and  i>0 && i < sizeof(array) - 1
*                            array[0] >= array[1]  array[0] is peak
*                            array[n-1]>= array[n-2] array[n-1] is peak
*/

#include <stdlib.h>
#include <stdio.h>



static int peak(int array[], int l, int h)
{
    int m;
	int n = h - l + 1;
	while ( h >= l )
	{
	    m = l + ((h-l)>>1);
		printf("l=%d;m=%d;h=%d\n",l,m,h);
	    if( m == 0 && array[0] >= array[1] )
		{
		    return 0;
		}
		if ( m == n-1 && array[n-1] >= array[n-2] )
		{
		    return n-1;
		}
		if  ( array[m] >= array[m-1] && array[m] >= array[m+1] )
		{
		    return m;
		}

		if ( array[m] < array[m-1] )
		{
		    h = m - 1;
		}
		else if ( array[m] < array[m+1] )
		{
		    l = m + 1;
		}
	}
	return -1;//never be herer
}





int main (int argc, char *argv[])
{
    int arr1[] = {-8,7,12,30,11,8,9,10,2};
	int arr2[] = {-8,2,7,8,9,10,11,12,30};
	int arr3[] = {30,12,11,10,9,8,7,2,-8};
	int arr4[] = {-8,7,7,4,30,42,42,12,9};
    printf("peak of arr1 in the array[%d]=%d\n",peak(arr1,0,sizeof(arr1)/sizeof(arr1[0])-1), arr1[peak(arr1,0,sizeof(arr1)/sizeof(arr1[0])-1)]);
    printf("peak of arr2 in the array[%d]=%d\n",peak(arr2,0,sizeof(arr2)/sizeof(arr2[0])-1), arr2[peak(arr2,0,sizeof(arr2)/sizeof(arr2[0])-1)]);
    printf("peak of arr3 in the array[%d]=%d\n",peak(arr3,0,sizeof(arr3)/sizeof(arr3[0])-1), arr3[peak(arr3,0,sizeof(arr3)/sizeof(arr3[0])-1)]);
    printf("peak of arr4 in the array[%d]=%d\n",peak(arr4,0,sizeof(arr4)/sizeof(arr4[0])-1), arr4[peak(arr4,0,sizeof(arr4)/sizeof(arr4[0])-1)]);
    return 0;
}
