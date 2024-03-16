#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char** scanWords() {
    char** words= ( char**)calloc(1, sizeof(char*)), **tmp;
    int i=0;
    while(1) {
        char buf[81];
        scanf("%80s", buf);
        if(buf[0]=='-') break;
        if(NULL==(tmp = ( char**)realloc(words, sizeof(char*)*(i+2)))) {
            printf("out of memory");
            break;
        }
        words=tmp;
        words[i] = ( char*)calloc(strlen(buf)+1, sizeof(char));
        strcpy(words[i], buf);
        i++;
    }
    words[i]=( char*)calloc(1,sizeof(char));
    return words;
}

int countWord(char *text, char* word) {
    int count = 0;
    char *pos = text;

    while ((pos = strstr(pos, word)) != NULL) {
        count++;
        pos += strlen(word);
    }

    return count;
}

void freeAll(char** strngs) {
    // Durchlaufen Sie das Array und geben Sie den Speicher für jedes Wort frei
    for (int i = 0; strngs[i][0] != '\0'; i++) {
        free(strngs[i]);
    }

    // Freigeben Sie den Speicher für das Array selbst
    free(strngs);
}

int main() {

    char text[1001];
    printf("text: ");
    scanf("%1000[^\n]s", text);

    char** searchWords = scanWords();

    // Ermitteln Sie die Länge des Arrays
    int arrayLength = 0;
    while (searchWords[arrayLength][0] != '\0') {
        arrayLength++;
    }

    // Durchsuchen Sie den Text für jedes Suchwort und geben Sie das Ergebnis aus
    printf("words: \n");
    for (int i = 0; i < arrayLength; i++) {
        int result = countWord(text, searchWords[i]);
        printf("%s: %d\n", searchWords[i], result);
    }

    // Freigeben Sie den Speicher für das String-Array
    freeAll(searchWords);

    return 0;
}
