#include <stdio.h>

void br(void);
void ic(void);

int main(void)
{
    br();
    printf(", ");
    ic();
    printf("\n");
    ic();
    printf("\n");
    br();

    return 0;
}

void ic(void)
{
    printf("India, China");
}

void br(void)
{
    printf("Brazil, Russia");
}