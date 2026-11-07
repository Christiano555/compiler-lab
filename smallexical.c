```c
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isKeyword(char s[])
{
    char kw[34][12] = {
        "auto","break","case","char","const","continue",
        "default","do","double","else","enum","extern",
        "float","for","goto","if","int","long","register",
        "return","short","signed","sizeof","static","struct",
        "switch","typedef","union","unsigned","void","volatile",
        "while","include","define"
    };

    int i;
    for(i=0; i<34; i++)
        if(strcmp(s,kw[i])==0)
            return 1;

    return 0;
}

int main()
{
    FILE *fp;
    int c, quote, line=1, tokenNo=1, i;
    char lexeme[100], token[20];

    fp=fopen("input.txt","r");

    if(fp==NULL)
    {
        printf("File not found");
        return 0;
    }

    printf("Line No  Token No  Token              Lexeme\n");

    while((c=getc(fp))!=EOF)
    {
        if(c=='\n')
        {
            line++;
            continue;
        }

        if(isspace(c))
            continue;

        i=0;

        if(isalpha(c) || c=='_')
        {
            while(isalnum(c) || c=='_')
            {
                lexeme[i++]=c;
                c=getc(fp);
            }

            lexeme[i]='\0';

            if(c!=EOF)
                ungetc(c,fp);

            if(isKeyword(lexeme))
                strcpy(token,"Keyword");
            else
                strcpy(token,"Identifier");
        }

        else if(isdigit(c))
        {
            while(isdigit(c))
            {
                lexeme[i++]=c;
                c=getc(fp);
            }

            lexeme[i]='\0';

            if(c!=EOF)
                ungetc(c,fp);

            strcpy(token,"Number");
        }

        else if(c=='"' || c=='\'')
        {
            quote=c;
            lexeme[i++]=c;

            while((c=getc(fp))!=quote && c!=EOF)
                lexeme[i++]=c;

            if(c!=EOF)
                lexeme[i++]=c;

            lexeme[i]='\0';

            strcpy(token,"Literal");
        }

        else if(c=='/')
        {
            c=getc(fp);

            if(c=='/')
            {
                while((c=getc(fp))!='\n' && c!=EOF);

                if(c=='\n')
                    line++;

                continue;
            }
            else
            {
                if(c!=EOF)
                    ungetc(c,fp);

                lexeme[0]='/';
                lexeme[1]='\0';
                strcpy(token,"Operator");
            }
        }

        else if(strchr("+-*%=<>!",c)!=NULL)
        {
            lexeme[0]=c;
            lexeme[1]='\0';
            strcpy(token,"Operator");
        }

        else if(strchr("(){}[];,.",c)!=NULL)
        {
            lexeme[0]=c;
            lexeme[1]='\0';
            strcpy(token,"Special Symbol");
        }

        else
        {
            lexeme[0]=c;
            lexeme[1]='\0';
            strcpy(token,"Unknown");
        }

        printf("%-9d %-10d %-18s %s\n",
               line,tokenNo++,token,lexeme);
    }

    fclose(fp);
    return 0;
}