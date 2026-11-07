#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isKeyword(char word[])
{
    char keywords[][10] = {
        "int","char","float","if","else",
        "while","for","return","void"
    };

    int size = sizeof(keywords) / sizeof(keywords[0]);

    for(int i=0; i<size; i++)
    {
        if(strcmp(word, keywords[i]) == 0)
            return 1;
    }
    return 0;
}

int main()
{
    FILE *fp;                   // File pointer
    char word[50];              // Store token
    int ch;                     // Current character
    int i;                      // Index
    int line = 1;               // Line number
    int tokenNo = 1;            // Token number

    fp = fopen("input.txt","r");

    if(fp == NULL)
    {
        printf("File not found");
        return 0;
    }

    printf("%-8s %-8s %-18s %s\n","Line","Token","Type","Lexeme");
    printf("-----------------------------------------------------\n");

    while((ch = fgetc(fp)) != EOF)
    {
        // Count new lines
        if(ch == '\n')
        {
            line++;
            continue;
        }

        // Skip spaces
        if(ch == ' ' || ch == '\t')
            continue;

        // Identifier or Keyword
        if(isalpha(ch))
        {
            i = 0;

            while(isalnum(ch))
            {
                word[i++] = ch;
                ch = fgetc(fp);
            }

            word[i] = '\0';

            if(ch != EOF)
                ungetc(ch, fp);

            if(isKeyword(word))
                printf("%-8d %-8d %-18s %s\n",line,tokenNo++,"Keyword",word);
            else
                printf("%-8d %-8d %-18s %s\n",line,tokenNo++,"Identifier",word);
        }

        // Number
        else if(isdigit(ch))
        {
            i = 0;

            while(isdigit(ch))
            {
                word[i++] = ch;
                ch = fgetc(fp);
            }

            word[i] = '\0';

            if(ch != EOF)
                ungetc(ch, fp);

            printf("%-8d %-8d %-18s %s\n",line,tokenNo++,"Number",word);
        }

        // String Literal
        else if(ch == '"')
        {
            i = 0;
            word[i++] = '"';

            while((ch = fgetc(fp)) != '"' && ch != EOF)
            {
                word[i++] = ch;
            }

            word[i++] = '"';
            word[i] = '\0';

            printf("%-8d %-8d %-18s %s\n",line,tokenNo++,"String Literal",word);
        }

        // Operators
        else if(ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='=')
        {
            printf("%-8d %-8d %-18s %c\n",line,tokenNo++,"Operator",ch);
        }

        // Special Symbols
        else if(ch==';' || ch==',' || ch=='(' || ch==')' ||
                ch=='{' || ch=='}')
        {
            printf("%-8d %-8d %-18s %c\n",line,tokenNo++,"Special Symbol",ch);
        }
    }

    fclose(fp);
    return 0;
}