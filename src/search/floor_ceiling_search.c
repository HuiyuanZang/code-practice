#include <stdlib.h>
#include <stdio.h>

#define FLOOR_INDEX        0
#define CEILING_INDEX      1
#define RETURN_ARRAY_SIZE  2

static void floor_ceiling_search(int array[], size_t size, int x, int ret[RETURN_ARRAY_SIZE])
{
    int l,h,m;
    if( !array || size == 0 )
	{
	    printf("EROOR:Invilid array!");
		ret[FLOOR_INDEX] = -1;
		ret[CEILING_INDEX] = -1;
		return;
	}
	l = 0;
	h = size - 1;
	while( l<=h )
	{
	    m = l + ((h-l)>>1);
		if ( array[m] > x )
		{
		    h = m - 1;
		}
		else if( array[m] < x )
		{
		    l = m + 1;
		}
		else
		{
		    ret[FLOOR_INDEX] = m;
			ret[CEILING_INDEX] = m;
			return;
		}
	}
	//in this case x < array[0], there is no floor item for x
	if( h < 0 )
	{
	    ret[FLOOR_INDEX] = -1;
		ret[CEILING_INDEX] = 0;
	}
	else if ( l>size-1 )//in this case x > array[n-1], there is no ceiing item for x
	{
	    ret[FLOOR_INDEX] = size - 1;
		ret[CEILING_INDEX] = -1;
	}
	else // in this case array[k] < x < array[k+1], in fact, k == h and k+1 == l now
	{
	    ret[FLOOR_INDEX] = h;
		ret[CEILING_INDEX] = l;
	}
    return;
}


int main (int argc, char *argv[])
{
    int arr[] = {-10,-4,0,3,5,7,10,10,14};
    //int arr[] = {10};
	int x = 8;
    int ret[RETURN_ARRAY_SIZE];
	floor_ceiling_search(arr,sizeof(arr)/sizeof(arr[0]),x, ret);
	printf("the floor index is %d, the ceilling index is %d\n",ret[FLOOR_INDEX], ret[CEILING_INDEX]);
}
