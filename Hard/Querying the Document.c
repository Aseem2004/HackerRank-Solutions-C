#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<assert.h>
#define MAX_CHARACTERS 1005
#define MAX_PARAGRAPHS 5

char* kth_word_in_mth_sentence_of_nth_paragraph(char**** document, int k, int m, int n) {
    return document[n-1][m-1][k-1];
}

char** kth_sentence_in_mth_paragraph(char**** document, int k, int m) {
    return document[m-1][k-1];
}


char*** kth_paragraph(char**** document, int k) {
    
    return document[k-1];
}

char**** get_document(char* text) {
    int IDletter = 0, IDword = 0, IDsentence = 0, IDparagraph = 0;

    char ****document = (char****) calloc(1, sizeof(char*)); // pointer to array of paragraphs pointers
    document[0] = (char***) calloc(1, sizeof(char*));        // pointers to arrays of sentences pointers
    document[0][0] = (char**) calloc (1, sizeof(char*));     // pointers to arrays of words pointers
    document[0][0][0] = (char*) calloc (1, sizeof(char));    // pointer to arrays of chars

    int i = 0;
    while(text[i] != '\0')
    {
        if( (text[i] != ' ') && (text[i] != '.') && (text[i] != '\n') )
        {
            document[IDparagraph][IDsentence][IDword][IDletter] = text[i];
            IDletter++;
            document[IDparagraph][IDsentence][IDword] = (char*)realloc(document[IDparagraph][IDsentence][IDword], (IDletter +  1) * sizeof(char));
        }
        else if(text[i] == ' ')
        {
            IDletter = 0;
            IDword++;
            document[IDparagraph][IDsentence] = (char**) realloc(document[IDparagraph][IDsentence], (IDword +  1) * sizeof(char*));
            document[IDparagraph][IDsentence][IDword] = (char*) calloc(1,  sizeof(char*));

            
        }
        else if(text[i] == '.')
        {
            IDletter = 0;
            IDword = 0;
            IDsentence++;
            document[IDparagraph] = (char***) realloc(document[IDparagraph], (IDsentence +  1) * sizeof(char*));
            document[IDparagraph][IDsentence] = (char**) calloc(1, sizeof(char*));
            document[IDparagraph][IDsentence][IDword] = (char*) calloc(1, sizeof(char*));
        }
        else if(text[i] == '\n')
        {
            IDletter = 0;
            IDword = 0;
            IDsentence = 0;
            IDparagraph++;
            document = (char****) realloc(document, (IDparagraph +  1) * sizeof(char*));
            document[IDparagraph] = (char***) calloc((IDparagraph +  1), sizeof(char*));
            document[IDparagraph][IDsentence] = (char**) calloc(1, sizeof(char*));
            document[IDparagraph][IDsentence][IDword] = (char*) calloc(1, sizeof(char*));
        }
        i++;
    }
    return document;
}

char* get_input_text() {	
    int paragraph_count;
    scanf("%d", &paragraph_count);

    char p[MAX_PARAGRAPHS][MAX_CHARACTERS], doc[MAX_CHARACTERS];
    memset(doc, 0, sizeof(doc));
    getchar();
    for (int i = 0; i < paragraph_count; i++) {
        scanf("%[^\n]%*c", p[i]);
        strcat(doc, p[i]);
        if (i != paragraph_count - 1)
            strcat(doc, "\n");
    }

    char* returnDoc = (char*)malloc((strlen (doc)+1) * (sizeof(char)));
    strcpy(returnDoc, doc);
    return returnDoc;
}

void print_word(char* word) {
    printf("%s", word);
}

void print_sentence(char** sentence) {
    int word_count;
    scanf("%d", &word_count);
    for(int i = 0; i < word_count; i++){
        printf("%s", sentence[i]);
        if( i != word_count - 1)
            printf(" ");
    }
} 

void print_paragraph(char*** paragraph) {
    int sentence_count;
    scanf("%d", &sentence_count);
    for (int i = 0; i < sentence_count; i++) {
        print_sentence(*(paragraph + i));
        printf(".");
    }
}

int main() 
{
    char* text = get_input_text();
    char**** document = get_document(text);

    int q;
    scanf("%d", &q);

    while (q--) {
        int type;
        scanf("%d", &type);

        if (type == 3){
            int k, m, n;
            scanf("%d %d %d", &k, &m, &n);
            char* word = kth_word_in_mth_sentence_of_nth_paragraph(document, k, m, n);
            print_word(word);
        }

        else if (type == 2){
            int k, m;
            scanf("%d %d", &k, &m);
            char** sentence = kth_sentence_in_mth_paragraph(document, k, m);
            print_sentence(sentence);
        }

        else{
            int k;
            scanf("%d", &k);
            char*** paragraph = kth_paragraph(document, k);
            print_paragraph(paragraph);
        }
        printf("\n");
    }     
}