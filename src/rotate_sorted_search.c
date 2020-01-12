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
   if( array[n-1] >= array[0] )
   {
       return 0;
   }
   l = 0;
   h = n - 1;
   while(h>l)
   {
       cur = l + ((h-l) >> 1); 
       if ( array[cur] >= array[l] )
	   {  
	      l = cur;
	   }
	   else
	   {
	      h = cur;
	   }
   }
   return l; 
}




int main(int argc,char *argv[])
{

}
