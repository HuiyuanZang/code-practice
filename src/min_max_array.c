/*
*  find minmum and maxmum elements in a given array with minmum comparision
*/



#include <stdlib.h>
#include <stdio.h>

#define MAX(a,b)   ({   \
       typeof(a) _a = (a);   \
	   typeof(b) _b = (b);   \
	   (void) (_a == _b);    \
	   _a>_b?_a:_b; })


#define MIN(a,b)   ({   \
       typeof(a) _a = (a);   \
	   typeof(b) _b = (b);   \
	   (void) (_a == _b);    \
	   _a>_b?_b:_a; })

/*
*   Time complexity is Theta(n)
*   the comparision number is 2 + 2(n-2) in the worst case and 2 +(n-2) in the best case
*/

static void min_max_method1(int array[], size_t n,int peak[2])
{
    if( !array || n == 0 )
	{
	    printf("ERROR:invalid array!\n");
		return;
	}
	if( !peak )
	{
	   printf("ERROR: invalid output array");
	   return;
	}
	if ( n == 1 )
	{
	    peak[0] = peak[1] = array[0];
		return;
	}
	
    peak[0] = MIN(array[0],array[1]);
    peak[1] = MAX(array[0],arary[1]);
	
    for( int i=2,i<n; i++ )
	{
	    if(array[i]>peak[1])
		    peak[1] = array[i];
		else if(array[i]<peak[0])
		    peak[0] = array[i];
	}
}











int main (int argc, char *argv[])
{
}
