// Allows the user to view regions of computer memory

#include <ctype.h>
#include <stdio.h>

typedef unsigned char BYTE;

int main(void)
{
    unsigned long addr;
    int i, n;
    BYTE *ptr;

    printf("sizeof unsigned char: %lu\n", sizeof(unsigned char));
    printf("sizeof unsigned int: %lu\n", sizeof(unsigned int));
    printf("sizeof unsigned long: %lu\n", sizeof(unsigned long));
    printf("Address of function: %lx\n", (unsigned long) main);
    printf("Address of variable: %lx\n", (unsigned long) &addr);

    printf("\nEnter a (hex) address: ");
    scanf("%lx", &addr);
    printf("Enter number of bytes to view: ");
    scanf("%d", &n);

    printf("\n");
    printf("     Address                 Bytes              Characters\n");
    printf("---------------- ----------------------------- ----------\n");

    ptr = (BYTE *)addr;
    for (; n > 0; n -= 10) {
        printf("%16lX ", (unsigned long) ptr);
        for (i = 0; i < 10 && i < n; i++) {
            printf("%.2X ", *(ptr + i));
        }
        for (; i < 10; i++)
            printf("   ");
        printf(" ");
        for (i = 0; i < 10 && i < n; i++) {
            BYTE ch = *(ptr + i);
            if (!isprint(ch))
                ch = '.';
            printf("%c", ch);
        }
        printf("\n");
        ptr += 10;
    }

    return 0;
}
