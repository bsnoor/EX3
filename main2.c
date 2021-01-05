#include <stdio.h>
#include <string.h>
#include "interface.h"
#include "txtfind.c"
#define LINE 256 
#define WORD 30


int main() {
    int i = 0;
    char line[LINE];
    char str[WORD];
    char op;
    int size=getLine(line);
    op = line[i];
    while (op != ' ') {
        *(str + i) = op;
        op = line[++i];
    }
    *(str + i) = '\0';
    op = *(line + i + 1);
    if (op != 'a' && op != 'b') {
        printf("Wrong Input\n");
        return 0;
    }
    if (op == 'a') {
        printf("Option 'a' Selected:\n");
        print_lines(str);
    }
    else {
        printf("Option 'b' Selected:\n");
        print_similar_words(str);
    }
	return 0;
}
