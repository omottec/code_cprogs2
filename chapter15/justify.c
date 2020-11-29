//
// Created by Jason Qin on 2020/11/29.
// Formats a file of text
//

#include <string.h>
#include "word.h"
#include "line.h"

#define MAX_WORD_LEN 20

/*
 *  gcc -o justify justify.c line.c word.c
 *  ./justify < data/quote > data/newquote
 *  cat -e -t -v makefile
 *  make
 */
int main(void)
{
    char word[MAX_WORD_LEN + 2];
    int word_len;

    clear_line();
    for (;;) {
        read_word(word, MAX_WORD_LEN+1);
        word_len = strlen(word);
        if (word_len == 0) {
            flush_line();
            return 0;
        }
        if (word_len > MAX_WORD_LEN)
            word[MAX_WORD_LEN] = '*';
        if (word_len + 1 > space_remaining()) {
            write_line();
            clear_line();
        }
        add_word(word);
    }
}
