#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
//Complete the following function.


void calculate_the_maximum(int n, int k) {
    int a=0,b=0,c=0,p=0,q=0,r=0;
    for(int i=1;i<=k;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
           p = i&j;
           if((p<k) && (a<p))
           a=p;
           
          q = i|j;
           if(q<k && b<q)
           b=q;
           
           r = j^i;
           if(r<k && c<r)
           c=r;
        }}
  printf("%d",a);
  printf("\n%d",b);
  printf("\n%d",c);
}

int main() {
    int n, k;
  
    scanf("%d %d", &n, &k);
    calculate_the_maximum(n, k);
 
    return 0;
}
