#include <stdio.h>
#define MAXLINE 1000

int getline(char line[], int maxline,FILE *fp);
void copy(char to[], char from[]);

int main()
{
    FILE *fp;
    char line[MAXLINE];
    char longest[MAXLINE];
    int len;
    int max = 0;
    fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }
    while ((len = getline(line, MAXLINE, fp)) > 0) {
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    }
    if (max > 0) {
        printf("Longest line: %s", longest);
    }
    fclose(fp);
    return 0;
}

int getline(char s[], int lim, FILE *fp)
{
    int c, i;
    for (i = 0; i < lim-1 && (c=fgetc(fp))!=EOF && c!='\n'; i++)
        s[i] = c;
    if (c == '\n')
        {
        s[i] = '\0';
    }
    return i;
}

void copy(char to[], char from[])
{
    int i;
    i = 0;
    while ((to[i] = from[i]) != '\0')
        i++;
}
