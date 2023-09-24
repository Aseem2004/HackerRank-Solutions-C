#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int count_uniq_chars(const char* string) {          
    size_t string_len     = strlen(string);
    size_t uniq_chars_count = 0;
    
    char uniq_chars[string_len+1];
    memset(uniq_chars, 0, sizeof(uniq_chars));
    
    for (int idx=0; idx < string_len; idx++) {
        if (!strchr(uniq_chars, string[idx])) {
            uniq_chars[uniq_chars_count] = string[idx];
            uniq_chars_count++;
        }
    }
    
    return uniq_chars_count;
}

int lexicographic_sort(const void* a, const void* b) {
    return strcmp(*(const char**)a, *(const char**)b);
}

int lexicographic_sort_reverse(const void* a, const void* b) {
    return -lexicographic_sort(a, b);
}

int sort_by_number_of_distinct_characters(const void* a, const void* b) {
    return count_uniq_chars(*(const char**)a) > count_uniq_chars(*(const char**)b);
}

int sort_by_length(const void* a, const void* b) {
    return strlen(*(const char**)a) > strlen(*(const char**)b);
}

void string_sort(char** arr,const int len,int (*cmp_func)(const void* a, const void* b)) {
    qsort(arr, len, sizeof(char*), lexicographic_sort);
    qsort(arr, len, sizeof(char*), cmp_func);
}


int main() 
{
    int n;
    scanf("%d", &n);
  
    char** arr;
	arr = (char**)malloc(n * sizeof(char*));
  
    for(int i = 0; i < n; i++){
        *(arr + i) = malloc(1024 * sizeof(char));
        scanf("%s", *(arr + i));
        *(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
    }
  
    string_sort(arr, n, lexicographic_sort);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, lexicographic_sort_reverse);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");

    string_sort(arr, n, sort_by_length);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);    
    printf("\n");

    string_sort(arr, n, sort_by_number_of_distinct_characters);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");
}