#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
	int a;
	int b;
	int c;
};

typedef struct triangle triangle;
void sort_by_area(triangle* tr, int n) {
    double p=0;
    int * s;
    int temp;
    triangle min;
    s=malloc(n * sizeof(double));
    for(int i=0;i<n;i++){
        p=((tr[i].a)+(tr[i].b)+(tr[i].c))/2.0;
        s[i]=p*(p-tr[i].a)*(p-tr[i].b)*(p-tr[i].c);
        
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(s[i]>s[j]){
                min=tr[i];
                tr[i]=tr[j];
                tr[j]=min;
                temp=s[i];
                s[i]=s[j];
                s[j]=temp;
            }
        }
    }
}

int main()
{
	int n;
	scanf("%d", &n);
	triangle *tr = malloc(n * sizeof(triangle));
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
	}
	sort_by_area(tr, n);
	for (int i = 0; i < n; i++) {
		printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
	}
	return 0;
}