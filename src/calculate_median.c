/**
* Given two sorted arrays with same size, calculate the median value after merging two arrays into one array
*/

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>



#define MAX(a,b)   ({  \
    typeof(a) _a = (a); \
	typeof(b) _b = (b); \
	(void) (&_a == &_b);   \
    (_a > _b)?_a:_b;    \
    })
#define MIN(a,b)  ({   \
    typeof(a) _a = (a);  \
	typeof(b) _b = (b);  \
	(void) (&_a == &_b);   \
	( _a>_b )?_b:_a;    \
})

static int get_median(int array[],size_t n)
{
    return (n&0x01)?array[n>>1]:(array[(n>>1) -1] +array[n>>1]) >> 1;
}

static int calculate_median_easy(int array1[],int array2[],size_t n)
{
   int median1, median2;
   int pos1 = 0, pos2 = 0;
   // arr1 = {1,3,4,6,8,9}
   // arr2 = {2,4,5,7,9,10}
   if(!array1 || !array2 || n==0)
   {
       printf("ERROR: invalid array!\n");
	   return INT_MIN;
   }
   if (n == 1)
   {
       return (array1[0]+array2[0])>>1;
   }
   for (int i = 0; i<n-1; i++ )
   {
        if(array1[pos1]<array2[pos2])
		    pos1++;
	    else 
		    pos2++;
   }
   median1 = (array1[pos1]<array2[pos2])?array1[pos1++]:array2[pos2++];
   median2 = (array1[pos1]<array2[pos2])?array1[pos1]:array2[pos2];
   printf("median1 = %d;median2=%d \n",median1,median2);
   return (median1+median2)>>1;
}
// Divide and conqure
static int calculate_median_advanced(int array1[],int array2[],size_t n)
{
   int m1,m2; 
   if(!array1 || !array2 || n==0)
   {
       printf("ERROR: invalid array!\n");
	   return INT_MIN;
   }
   if (n == 1)
   {
       return (array1[0]+array2[0])>>1;
   }
   if (n == 2)
   {
       return (MIN(array1[1],array2[1]) + MAX(array1[0],array2[0])) >> 1;    
   }
   m1 = get_median(array1,n);
   m2 = get_median(array2,n);
   if(m1 == m2)
       return m1;
   if(m1>m2)
   {
       if(n&0x01)
	      return calculate_median_advanced(array1,array2+n/2,n-n/2);
	   return calculate_median_advanced(array1,array2+n/2-1,n-n/2+1);
   }
   if(n&0x01)
       return calculate_median_advanced(array2,array1+n/2,n-n/2);
   return calculate_median_advanced(array2,array1+n/2-1,n-n/2+1);

}


int main(int argc,char *argv[])
{
    int arr1[] = {1,12,15,26,38};
	int arr2[] = {2,13,17,30,45};
    int a=0, b=1;
    //	(void) (&a == &b);
	printf("the median of new array is %d\n",calculate_median_easy(NULL,NULL,0));
	printf("the median of new array is %d\n",calculate_median_easy(arr1,arr2,sizeof(arr1)/sizeof(arr1[0])));
	printf("the median of new array is %d\n",calculate_median_advanced(arr1,arr2,sizeof(arr1)/sizeof(arr1[0])));
}
