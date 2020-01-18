#include <stdlib.h>
#include <stdio.h>


/*@Brief: find second smallest and smallest element in given array
 *@Param[in] array: given array
 *@Param[in] n: the size of array
 *@Param[out] ret[2]: ret[0] is the index of second smallest element 
 *                    ret[1] is the index of smallest element 
 *
 */


static void two_smallest(int array[],size_t n, int ret[2])
{
    ret[0] = ret[1] = 0;
    for (int i; i<n; i++)
    {
        if (array[i] <= array[ret[1]])
        {
            ret[0] = ret[1];
            ret[1] = i;
        }
        else if(array[i]>array[ret[1]] && array[i]<= array[ret[0]])
        {
            ret[0] = i;
        }
    }

}


int main(int argc,char *argv[])
{
    int arr[] = {10,-20,-234,0,10,8,20,6};
    int ret[2];
    two_smallest(arr,sizeof(arr)/sizeof(arr[0]),ret);
    printf("array[%d]=%d,array[%d]=%d \n",ret[0],arr[ret[0]],ret[1],arr[ret[1]]);

}
