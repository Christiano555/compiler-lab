```c
#include<stdio.h>
#include<string.h>
#include<ctype.h>

int isKeyword(char s[])
{
    char kw[34][12]={"auto","break","case","char","const","continue",
    "default","do","double","else","enum","extern","float","for","goto","if",
    "int","long","register","return","short","signed","sizeof","static",
    "struct","switch","typedef","union","unsigned","void","volatile","while",
    "include","define"};

    int i;
    for(i=0;i<34;i++)
        if(strcmp(s,kw[i])==0)
            return 1;

    return 0;
}

void printProgram(FILE *fp)
{
    char line[200];
    int n=1;

    printf("Original Program\n----------------\n");

    while(fgets(line,sizeof(line),fp)!=NULL)
        printf("%3d: %s",n++,line);
}

int main()
{
    FILE *fp;
    int c,next,line=1,tokenNo=1,i;
    char lexeme[100],token[20];

    fp=fopen("input.txt","r");

    if(fp==NULL)
    {
        printf("Cannot open input.txt\n");
        return 0;
    }

    printProgram(fp);
    rewind(fp);

    printf("\n\nToken Table\n-----------\n");
    printf("%-10s %-10s %-18s %s\n","Line no","Token no","Token","Lexeme");
    printf("%-10s %-10s %-18s %s\n","-------","--------","-----","------");

    while((c=getc(fp))!=EOF)
    {
        if(c=='\n')
        {
            line++;
            continue;
        }

        if(c==' ' || c=='\t')
            continue;

        if(isalpha(c) || c=='_')
        {
            i=0;

            while(isalnum(c) || c=='_')
            {
                lexeme[i++]=c;
                c=getc(fp);
            }

            lexeme[i]='\0';

            if(c!=EOF)
                ungetc(c,fp);

            strcpy(token,isKeyword(lexeme)?"Keyword":"Identifier");
        }

        else if(isdigit(c))
        {
            i=0;

            while(isdigit(c) || c=='.')
            {
                lexeme[i++]=c;
                c=getc(fp);
            }

            lexeme[i]='\0';

            if(c!=EOF)
                ungetc(c,fp);

            strcpy(token,"Numeric Literal");
        }

        else if(c=='"' || c=='\'')
        {
            int quote=c;
            i=0;
            lexeme[i++]=c;

            while((c=getc(fp))!=quote && c!=EOF)
                lexeme[i++]=c;

            if(c!=EOF)
                lexeme[i++]=c;

            lexeme[i]='\0';

            strcpy(token,quote=='"'?"String Literal":"Character Literal");
        }

        else if(c=='/')
        {
            strcpy(lexeme,"/");
            strcpy(token,"Operator");
        }

        else if(strchr("+-*%=<>!&|",c)!=NULL)
        {
            lexeme[0]=c;
            next=getc(fp);

            if(((c=='=' || c=='!' || c=='<' || c=='>') && next=='=') ||
               (c=='+' && next=='+') || (c=='-' && next=='-') ||
               (c=='&' && next=='&') || (c=='|' && next=='|'))
            {
                lexeme[1]=next;
                lexeme[2]='\0';
            }
            else
            {
                lexeme[1]='\0';

                if(next!=EOF)
                    ungetc(next,fp);
            }

            strcpy(token,"Operator");
        }

        else
        {
            lexeme[0]=c;
            lexeme[1]='\0';

            if(strchr("(){}[];,.#@",c)!=NULL)
                strcpy(token,"Special Symbol");
            else
                strcpy(token,"Unknown");
        }

        printf("%-10d %-10d %-18s %s\n",line,tokenNo++,token,lexeme);
    }

    fclose(fp);
    return 0;
}
