#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define MAX_CHARACTERS 1005
#define MAX_PARAGRAPHS 5

struct word {
    char* data;
};

struct sentence {
    struct word* data;
    int word_count;//denotes number of words in a sentence
};

struct paragraph {
    struct sentence* data  ;
    int sentence_count;//denotes number of sentences in a paragraph
};

struct document {
    struct paragraph* data;
    int paragraph_count;//denotes number of paragraphs in a document
};
struct document get_document(char* text) {
    int i; //To be used to iterate when adding words
    int iIter = 0; //General full length iterator
    int iParaCount = 1; //Count the paragraphs. Starts at 1 since last paragraph does not have \n
    int iWordCount = 0; //Count words in each sentence
    int iSentCount = 0; //Count sentences in each paragraphs
    int iStart, iEnd; //Start and finish for word length
    int iWordSize; //Length of words extracted
    int iSentenceCount[MAX_PARAGRAPHS] = {0, 0, 0, 0, 0}; //Number of sentences in each paragraph
    
    //First iteration to get number of paragraphs and number of sentences in each paragraph
    while(text[iIter] != '\0'){
        if(text[iIter] == '.'){ //End of sentence
            iSentenceCount[iParaCount - 1]++;
        }
        else if(text[iIter] == '\n'){ //End of paragraph
            iParaCount++;
        }
        iIter++;
    }

    struct document *doc = (struct document *) malloc(sizeof(struct document));   
    doc->paragraph_count = iParaCount;
    doc->data = (struct paragraph *) malloc(iParaCount * sizeof(struct paragraph));
    for(iIter = 0; iIter < iParaCount; iIter++){
        doc->data[iIter].sentence_count = iSentenceCount[iIter];
        doc->data[iIter].data = (struct sentence *) malloc(iSentenceCount[iIter] * sizeof(struct sentence));
    }

    iEnd = 0;
    iIter = 0;
    iStart = 0;
    iWordCount = 0;
    iParaCount = 0;
    iSentCount = 0;
    while(text[iIter] != '\0'){
        if(text[iIter] == ' '){ //End of word
            iWordCount++;
        }
        else if(text[iIter] == '.'){ //End of word AND sentence
            iWordCount++;
            doc->data[iParaCount].data[iSentCount].word_count = iWordCount;
            doc->data[iParaCount].data[iSentCount].data = (struct word *) malloc(iWordCount * sizeof(struct word));
            //Iterate again from the beginning of the sentence to find words and save them
            for(i = 0; i < iWordCount; i++){
                iEnd = iStart;
                while((text[iEnd] != ' ') && (text[iEnd] != '.')){ //End of word
                    iEnd++;
                }
                iWordSize = iEnd - iStart;
                doc->data[iParaCount].data[iSentCount].data[i].data = (char *) malloc((iWordSize + 1) * sizeof(char)); //Plus 1 for null character
                memcpy(doc->data[iParaCount].data[iSentCount].data[i].data, &text[iStart], iWordSize * sizeof(char));
                doc->data[iParaCount].data[iSentCount].data[i].data[iWordSize] = '\0';
                //Start is next of end. If new paragraph, add one more
                iStart = iEnd + 1;
                if(text[iStart] == '\n'){
                    iStart++;
                }
            }
            iSentCount++;
            iWordCount = 0;
        }
        else if(text[iIter] == '\n'){
            iParaCount++;
            iSentCount = 0;
            iWordCount = 0;
        }
        iIter++;
    }
    return *doc;
}

struct word kth_word_in_mth_sentence_of_nth_paragraph(struct document Doc, int k, int m, int n) {
    return Doc.data[n - 1].data[m - 1].data[k - 1];
}

struct sentence kth_sentence_in_mth_paragraph(struct document Doc, int k, int m) { 
    return Doc.data[m - 1].data[k - 1];
}

struct paragraph kth_paragraph(struct document Doc, int k) {
    return Doc.data[k - 1];
}


void print_word(struct word w) {
    printf("%s", w.data);
}

void print_sentence(struct sentence sen) {
    for(int i = 0; i < sen.word_count; i++) {
        print_word(sen.data[i]);
        if (i != sen.word_count - 1) {
            printf(" ");
        }
    }
}

void print_paragraph(struct paragraph para) {
    for(int i = 0; i < para.sentence_count; i++){
        print_sentence(para.data[i]);
        printf(".");
    }
}

void print_document(struct document doc) {
    for(int i = 0; i < doc.paragraph_count; i++) {
        print_paragraph(doc.data[i]);
        if (i != doc.paragraph_count - 1)
            printf("\n");
    }
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

int main() 
{
    char* text = get_input_text();
    struct document Doc = get_document(text);

    int q;
    scanf("%d", &q);

    while (q--) {
        int type;
        scanf("%d", &type);

        if (type == 3){
            int k, m, n;
            scanf("%d %d %d", &k, &m, &n);
            struct word w = kth_word_in_mth_sentence_of_nth_paragraph(Doc, k, m, n);
            print_word(w);
        }

        else if (type == 2) {
            int k, m;
            scanf("%d %d", &k, &m);
            struct sentence sen= kth_sentence_in_mth_paragraph(Doc, k, m);
            print_sentence(sen);
        }

        else{
            int k;
            scanf("%d", &k);
            struct paragraph para = kth_paragraph(Doc, k);
            print_paragraph(para);
        }
        printf("\n");
    }     
}