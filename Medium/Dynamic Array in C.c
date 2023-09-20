#include <stdio.h>
#include <stdlib.h>

int* total_number_of_books;
int** total_number_of_pages;

#define MAX_BOOKS_ON_SHELF 1100

int** create_shelves(int shelves_number) {
    
    int** shelves = (int**)malloc(shelves_number * sizeof(int*));
    
    for (int shelf=0; shelf < shelves_number; shelf++) {
        shelves[shelf] = (int*)calloc(MAX_BOOKS_ON_SHELF, sizeof(int));
    }

    return shelves;
}

void push_book_at_shelf(int** shelves, int shelf, int book_pages) {

    for (int book=0; book < MAX_BOOKS_ON_SHELF; book++) {
        if (!shelves[shelf][book]) {
            shelves[shelf][book] = book_pages;
            break;
        }
    }
}


int main() {
    
    int total_number_of_shelves;
    int total_number_of_queries;
    int type_of_query;
    int shelves, book_pages;
    
    scanf("%d", &total_number_of_shelves);
    scanf("%d", &total_number_of_queries);
    
    int** total_number_of_pages = create_shelves(total_number_of_shelves);
    int* total_number_of_books = (int*)calloc(shelves, sizeof(int));
    
    while (total_number_of_queries--) {
        scanf("%d", &type_of_query);
        
        if (type_of_query == 1) {
            scanf("%d %d", &shelves, &book_pages);
            
            push_book_at_shelf(total_number_of_pages, shelves, book_pages);
            total_number_of_books[shelves]++;
        } else if (type_of_query == 2) {
            int x, y;
            scanf("%d %d", &x, &y);
            printf("%d\n", *(*(total_number_of_pages + x) + y));
        } else {
            int x;
            scanf("%d", &x);
            printf("%d\n", *(total_number_of_books + x));
        }
    }

    if (total_number_of_books) {
        free(total_number_of_books);
    }
    
    for (int i = 0; i < total_number_of_shelves; i++) {
        if (*(total_number_of_pages + i)) {
            free(*(total_number_of_pages + i));
        }
    }
    
    if (total_number_of_pages) {
        free(total_number_of_pages);
    }
    
    return 0;
}