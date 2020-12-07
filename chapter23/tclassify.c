// Tests the character-classification functions

#include <ctype.h>
#include <stdio.h>

#define TEST(f) printf("   %c   ", f(*p) ? 'y' : 'n')

int main(void)
{
    char *p;

    printf("     alnum  cntrl  graph  print  space  xdigit  alpha  digit  lower  punct  upper\n");

    for (p = "azAZ0 !\t"; *p != '\0'; p++) {
        if (iscntrl(*p))
            printf("\\x%02x:", *p);
        else
            printf("  %c:", *p);
        TEST(isalnum);
        TEST(iscntrl);
        TEST(isgraph);
        TEST(isprint);
        TEST(isspace);
        TEST(isxdigit);
        TEST(isalpha);
        TEST(isdigit);
        TEST(islower);
        TEST(ispunct);
        TEST(isupper);
        printf("\n");
    }

    return 0;
}
