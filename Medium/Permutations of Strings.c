#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int next_permutation(int n, char **s) {
  int i = n - 2;
  while (i >= 0 && strcmp(s[i], s[i + 1]) >= 0) {
    i--;
  }

  if (i < 0) {
    return 0;
  }

  int j = n - 1;
  while (j > i && strcmp(s[j], s[i]) <= 0) {
    j--;
  }

  char *tmp = s[i];
  s[i] = s[j];
  s[j] = tmp;

  for (int p = i + 1, q = n - 1; p < q; p++, q--) {
    tmp = s[p];
    s[p] = s[q];
    s[q] = tmp;
  }

  return 1;
}

int main()
{
	char **s;
	int n;
	scanf("%d", &n);
	s = calloc(n, sizeof(char*));
	for (int i = 0; i < n; i++)
	{
		s[i] = calloc(11, sizeof(char));
		scanf("%s", s[i]);
	}
	do
	{
		for (int i = 0; i < n; i++)
			printf("%s%c", s[i], i == n - 1 ? '\n' : ' ');
	} while (next_permutation(n, s));
	for (int i = 0; i < n; i++)
		free(s[i]);
	free(s);
	return 0;
}