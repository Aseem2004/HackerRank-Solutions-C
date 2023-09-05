#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{

    char ch, s[100], sen[101];
    scanf("%c", &ch);
    scanf("%s\n", s);
    scanf("%[^\n]%*c", sen);
    printf("%c\n%s\n%s", ch, s, sen);  
    return 0;
}
