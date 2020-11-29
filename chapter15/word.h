//
// Created by Jason Qin on 2020/11/29.
//

#ifndef WORD_H
#define WORD_H
/*
 * Reads the next word from the input and
 * stores it in word. Makes word empty if no
 * word could be read because of end-of-line.
 * Truncates the word if its length exceeds len.
 */
void read_word(char *word, int len);
#endif //WORD_H
