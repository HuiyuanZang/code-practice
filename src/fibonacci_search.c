#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>


typedef unsigned long long uint64_t;

#define MIN(a,b)  ({       \
     typeof((a)) _a = (a); \
	 typeof((b)) _b = (b); \
	 (void)(&_a == &_b);   \
	 _a<_b?_a:_b;})

/**
*@Brief: find the smallest fibonacci number greater than or equal to a
* param  a [in] : the target number 
* param  fib2 [out]: the smallest fibonacci number greater than a or equal with a
* param  fib1 [out]: fib2 = fib1+fib0    fib1 = F(n-1)
* param  fib0 [out]: fib2 = fib1+fib0    fib0 = F(n)
* return: the serial index number n of fibonacci fib2 = F(n)
*/
static unsigned int minfib(uint64_t a, uint64_t *fib2, uint64_t *fib1, uint64_t *fib0)
{
    unsigned int index = 1;
	*fib0 = 0,*fib1 = 1 *fib2= 1;
	if (a == 0)
	   return 0;
	if (a == 1)
	   return 1;

	while (fib2<a)
	{
	   *fib0 = *fib1;
	   *fib1 = *fib2; 
	   *fib2 = *fib1 + *fib0;
       index++;
	}
	return index;
}

static int fsearch(int array[],size_t n, int target)
{
    unsigned fib0,fib1,fib2;
	int offset = -1;
	minfib(n,&fib2,&fib1,&fib0);

	while(fib2>1)
	{
	    int index = MIN(offset+fib0,n-1);
		if(array[index] == target)
		    return index;
	    fib2 = fib1;
		fib1 = fib0;
		fib0 = fib2 - fib1;
		if (array[index]<target)
		{
		   offset = index;
		}
		else 
		{
           //do noting but reduce fibonacci number
		}

	}
	//it is possible to lefe one element needing to check
    if(fib1 == 1&&array[offset+1] == target)
	   return offset+1;
	return -1;
}



int main(int argc, char *argv[])
{

}
