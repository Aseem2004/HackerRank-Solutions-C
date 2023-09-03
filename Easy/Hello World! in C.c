#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
	
    printf("Hello, World!\n");
    char s[100];
    scanf("%[^\n]%*s", &s);
    printf(s);
       
    return 0;
}