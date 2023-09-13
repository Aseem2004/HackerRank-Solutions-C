#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
	
    int n,sum,remainder,tmpDigitNumber;
    scanf("%d", &n);
    sum = 0;
    for(int i=0;i<5;i++){
    remainder = n%10;
    sum+=remainder;
    tmpDigitNumber = (n-remainder)/10;
    n = tmpDigitNumber;
    }
    printf("%d",sum);
    return 0;
}
