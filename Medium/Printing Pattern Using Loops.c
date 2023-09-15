#include <stdio.h>
int main()
{

int n;
scanf("%d", &n);

int change = 0;
int threshhold = 0;

for(int i=0; i<n*2-1; i++){
    change=0;
    for(int j=0; j<n*2-1; j++){
        printf("%d ", n-change);
        if(threshhold>change && j<n) change++;
        if(change>0 && j>=n*2-2-threshhold) change--;
    }
    if(i<n-1) threshhold++;
    if (i>=n-1) threshhold--;
    printf("\n");
        }

return 0;
}
