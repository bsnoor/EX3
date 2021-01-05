#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interface.h"
#define LINE 256 
#define WORD 30

int getLine(char s[])
{
    int i = 0;
    char ch = getchar();
    // get input until get '\n' or EOF
    while (ch != '\n' && ch != EOF) {
        *(s + i++) = ch;
        ch = getchar();
    }
    // put ending to the string line
    s[i] = '\0';
    if (ch == EOF) {
        return EOF;
    }
    return i;
}

int getword(char w[]) {
    int i = 0;
    char ch = getchar();
    // get input until get '\n' or '\t' or ' ' or EOF
    while (ch != '\n' && ch != '\t' && ch != ' ' && ch != EOF) {
        *(w + i++) = ch;
        ch = getchar();
    }
    // put ending to the string word
    w[i] = '\0';
    if (ch == EOF) {
        return EOF;
    }
    return i;
}

int substring(char* str1, char* str2) {
    int i, j = 0, l1, l2;
    l1 = strlen(str1);
    l2 = strlen(str2);
    /* two loops inside each other ,
        start from the beginning of the second String
            keep moving on while both indexes in both Strings EQUALS
            otherwise check if j == length of Second Str , else start over again */ 
    for (i = 0; i <= l1 - l2; i++) {
        while (j<l2 && *(str1 + i + j) == *(str2 + j))
        {
            j++;
        }
        if (j == l2)
            return 1;
        j = 0;
    }
    return 0;
}

int similar(char* s, char* t, int n) {
    int i = 0, j = 0;
    while (*(s + i) != '\0' || *(t + j) != '\0') {
        if (*(s + i) == *(t + j)) { //until now both Strings Equals
            i++;
            j++;
        }
        else { // char in index i in both Strings Not EQUAL -> increase 1 step on pointer in String s 
            i++;
            n--; //decrease n every time we move over index
        }
    }
    /* check if deleted n characters ,
          if its true we return 1 ,
             otherwise return 0  */
    if (n == 0) 
        return 1;
    return 0;
}

void print_lines(char* str) {
    int count = 0, j = 0;
    char s[LINE];
    char arr[100][LINE];
    while (getLine(s) != EOF && strcmp(s,"stop")!=0) {
        if (substring(s, str)) {
            //arr[j++][0] = s;
            printf("%s\n", s);
        }
    }
    //for (int i = 0; i < j; i++)
    //    printf("%s\n", arr+i);
}

void print_similar_words(char* str) {
    char w[WORD];
    while (getword(w) != EOF) {

        if (similar(w, str, 1)) {
            printf("%s\n", w);
        }
        else {
            if (similar(w, str, 0)) {
                printf("%s\n", w);
            }
        }
    }
}


