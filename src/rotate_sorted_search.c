/*
* Given a ascending sorted array, then rotate the array , try to find where is the smallest element
* e.g 6 7 8 2 4 5     ===> array[3] is the smallest  
*/

#include <stdlib.h>
#include <stdio.h>

static int search_rarray(int array[],size_t n)
{
   int h, l, cur;
   if (!array || n == 0 )
   {
       printf("Error:array is invalid!\n");
	   return -1;
   }
   if( array[n-1] > array[0] )
   {
       return 0;
   }
   l = 0;
   h = n - 1;
   while(h>l)
   {
       cur = l + ((h-l) >> 1); 
     //  printf("l=%d,cur=%d,h=%d \n",l,cur,h);
       /*
       if ( array[cur] >= array[l] )
	   {  
	      l = cur + 1;
	   }
	   else
	   {
	      h = cur;
	   }
       */
       if ( array[cur] <= array[h] )
       {
           h = cur;
       }
       else
       {
           l = cur + 1;
       }
   }
   return l; 
}
static int binary_search(int array[],int l, int h, int key)
{
    int mid;
    if (!array)
    {
        printf("ERROR: invalid array\n");
        return -1;
    }
    if (h == l)
    {
        return l;
    }
    while (h >= l)
    {
        mid = l + ((h-l)>>1);
        if (array[mid] == key)
            return mid;
        if (array[mid] < key)
            l = mid + 1;
        else  
            h = mid - 1;
    }
    return -1;
}

static int find_key(int array[], size_t n, int key)
{
    int begin;
    if (!array || n == 0 )
    {
        printf("Error:array is invalid!\n");
	    return -1;
    }
    //array[] is rotated sorted array
    //so find starting index first, then bsearch(array,0,begin -1) and bsearch(array,begin,n-1)
    begin = search_rarray(array,n);
    if (key>= array[0] && key<=array[begin-1])
        return binary_search(array,0,begin-1,key);
    if (key>= array[begin] && key<=array[n-1])
        return binary_search(array,begin,n-1,key);
    return -1;
}
int main(int argc,char *argv[])
{
    int array[] = {6,7,10,34,2,4,5,5,6};
    int key = 4;
    printf("the array rotated to %d\n",search_rarray(array,sizeof(array)/sizeof(array[0])));
    printf("find the key %d in the %d\n",key, find_key(array,sizeof(array)/sizeof(array[0]),key));
}
