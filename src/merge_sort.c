#include <stdlib.h>
#include <stdio.h>


#define MAX(a,b) ({   \
        typeof(a) _a = (a);  \
        typeof(b) _b = (b); \
        (void)(&_a == &_b); \
        (_a>_b)?_a:_b;})


#define MIN(a,b) ({   \
        typeof(a) _a = (a);  \
        typeof(b) _b = (b); \
        (void)(&_a == &_b); \
        (_a>_b)?_b:_a;})

//Given sorted array[l...m] and sorted array[m+1, h] 
//merg to array'[l...h]

static void  merge(int array[], int l, int m, int h )
{
    int i = l;
    int j,k;
    //we need tmp array to store original value
    int *tmp1 = (int *)malloc((m-l+1+1)*sizeof(int));
    int *tmp2 = (int *)malloc((h-m+1)*sizeof(int));
    for (int i = 0;i<m-l+1;i++ )
    {
        tmp1[i] = array[l+i];
    }
    for (int i = 0;i<h-m;i++ )
    {
        tmp2[i] = array[m+1+i];
    }
    tmp1[m-l+1] = MAX(array[m],array[h]) + 1;
    tmp2[h-m] = MAX(array[m],array[h]) + 1;
    j = k = 0;
    while(i<=h)
    {
        //array[i] = min { array[k], array[j]} k belong[l...m]  h belong to [m+1 h]
        if(tmp1[j] < tmp2[k])
        {
            array[i] = tmp1[j];
            j++;
        }
        else
        {
            array[i] = tmp2[k];
            k++;
        }
        i++;
    }
    free(tmp1);
    free(tmp2);
}


static void msort_r(int array[], int l, int h)
{
    int m;
    if(!array)
    {
        printf("ERROR: invalid array\n");
        return;
    }
    if (h <= l)
       return;
    m = l + ((h-l)>>1); 
    msort_r(array,l,m);
    msort_r(array,m+1,h);
    merge(array,l,m,h);
}

static void dump(int array[],size_t n)
{
    for (int i = 0;i<n;i++ )
    {
        printf("%d\n",array[i]);
    }
}

static void msort_i(int array[], int n)
{
    if(!array || n == 0)
    {
        printf("ERROR:invalid array!\n");
        return;
    }
    if (n == 1)
    {
        return;
    }
    //i from 1 then 2,4,8,16,......
    //bottom-up
    for(int i = 1;i<n; i<<=1 )
    {
        for (int low = 0; low<n; low += 2*i)
        {
            int mid = MIN(low+i-1,n-1);
            int high   = MIN(low+2*i-1,n-1);
            printf("low=%d,mid=%d,high=%d;",low,mid,high);
            merge(array,low,mid,high);
        }
        printf("\n");
    }
}



int main(int argc, char *argv[])
{
    int arr[] = {-19,-78,10,29,0,2,6,10,19};
    //int arr[] = {-19};
   // msort_r(arr,0,sizeof(arr)/sizeof(arr[0])-1);
    msort_i(arr,sizeof(arr)/sizeof(arr[0]));
    dump(arr,sizeof(arr)/sizeof(arr[0]));
}
