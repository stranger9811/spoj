#include<stdio.h>
#include<string.h>
int main(void)
{
        char words[2000000];
        char tofind;
        
        int i,count,j;
        i=0;
        while(scanf("%s", words) == 1)
        {
                          count=0;
           tofind='1';
           i++;
           for(j=0;j<strlen(words);j++)
           {
                if(words[j]==tofind)
                {
                count++;
                if(tofind=='1')
                               tofind='0';
                else
                               tofind='1';
                               
                               }            
                               }                    
           printf("Game #%d: %d\n",i,count);
        }
        return 0;
}


