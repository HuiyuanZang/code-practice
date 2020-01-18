/*
 * Given an array of intergers, try to find two elements such that their sum is closest to zero
 * The fisrt step, we sort array, then the issue become how to find the two element such that their sum is closest to zero O(nlgn)
 * check arr[0]>= 0 and arr[n-1]<=0
 * othewise  
 */

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#define abt(x) (x)>=0?(x):-(x)

//Given array is sorted by natual comparation
//then array[ret[0]] and array[ret[1]] is what we want
static void min_sum_1(int array[], int n, int ret[2])
{
    int l, r;
    int minSum;
    l = 0;
    r = n-1;
    minSum = abt(array[l] + array[r]);
    while(l<r)
    {
        int sum = array[l] + array[r];
        if(abt(sum)<minSum)
        {
            minSum = abt(sum);
            ret[0] = l;
            ret[1] = r;
            if (minSum == 0)
               break;
        }
        if( sum > 0 )
            r--;
        else
            l++;
    }
    return;
}


//Givern array is sorted by their absolute values
//then compary all array[i-1] + array[i]
static void min_sum_2(int array[], int n, int ret[2])
{
    int minSum = INT_MAX;
    for(int i = 1; i < n; i++)
    {
        if( abt(array[i-1]+array[i]) < minSum )
        {
            minSum = abt(array[i-1]+array[i]);
            ret[0] = i-1;
            ret[1] = i;
            if (minSum == 0)
                break;
        }
    }
    return;
}





int main(int argc, char *argv[])
{
    int ret[2];
    int arr1[] = {-80,-28,-10,1,60,85};
    int arr2[] = {1,-10,-28,60,-80,85};
    min_sum_1(arr1,sizeof(arr1)/sizeof(arr1[0]),ret);
    printf("array[%d](%d) +array[%d](%d) near to zero \n", ret[0],arr1[ret[0]],ret[1],arr1[ret[1]]);
    min_sum_2(arr2,sizeof(arr2)/sizeof(arr2[0]),ret);
    printf("array[%d](%d) +array[%d](%d) near to zero \n", ret[0],arr2[ret[0]],ret[1],arr2[ret[1]]);



}
