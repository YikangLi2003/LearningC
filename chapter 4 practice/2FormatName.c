#include <stdio.h>
#include <string.h>

void main(void)
{
    char name[10];

    printf("Please enter your first name: ");
    scanf("%s", name);
    printf("\"%s\"\n", name);
    printf("\"%20s\"\n", name);
    printf("\"%-20s\"\n", name);
    printf("\"%*s\"\n", strlen(name) + 3, name);
}