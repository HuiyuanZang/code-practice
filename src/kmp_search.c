/**
* Given two strings str1,str2, m = length(str1) < n = length(str2)
* check if str2 contains str1, if so, then output all the start index of posibility
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
* How to generate prefix table
*     assume string = "ABABCABABC"
*            pT[0]: 0
*            PT[1]: 0 substring is "AB"
*            pT[2]: 1 subtring is "ABA"
*            pT[3]: 2 subtring is "ABAB"
*            pT[4]: 0 substing is "ABABC"
*            pT[5]: 1 substing is "ABABCA"
*            pT[6]: 2 substing is "ABABCAB"
*            pT[7]: 3 subtring is "ABABCABA"
*            PT[8]: 4 pT[9]:5
*     if (str[i] == str[pT[i-1]]+1)
*            pT[i] = ++pT[i-1];
*     else
*     {
*        
*     }
*        
*/



static void lpstable(char *str,size_t len, int *lps)
{
    int index = 0;
	int i = 1;
    if(!str || len == 0)
	{
	   printf("ERROR:invalid str!\n");
	   return;
	}
	if(!lps)
	{
	    printf("ERROR:the longest prefix table is NULL!\n");
	    return;
	}
	lps[0] = 0;	
    while( i<len )
	{
        if(str[i] == str[index])
		{
		   lps[i++] = ++index;
		}
		else
		{
		    if(len == 0)
			{
			   lps[i++] = 0;
			}
			else
			{
               index = lps[index -1];
			}
		}
	}

}



static void kmpSearch(char *str, char *pat)
{
    int lenStr,lenPat;
	int i=0,j=0;
	int *lps;
    if(!str || !pat)
	{
	    printf("Error:invalid str or pattarn!\n");
		return;
	}
    lenStr = strlen(str);
	lenPat = strlen(pat);
	lps = (int *)malloc(sizeof(int)*lenPat);
	if(!lps)
	{
	    printf("ERROR: Cannot allocate memory for lps!\n");
	    return;
	}
    lpstable(pat,lenPat,lps);
    while (i<lenStr)
	{
	    if(str[i] == pat[j])
		{
		    i++;
			j++;
		}
		if(j == lenPat)
		{
		    printf("Pattern fond in %d \n",i-j);
			j = lps[j-1];
		}
		else if(i<lenStr && str[i] != pat[j])
		{
            if (j != 0)
			{
			    j = lps[j-1];
			}
			else
			{
			    i++;
			}
		}
	}
}




int main(int argv, char *argv)
{
}
