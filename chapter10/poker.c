//
// Created by Jason Qin on 2020/11/29.
// Classifier a poker hand
//

#include <stdio.h>
#include <stdlib.h>

#define NUM_RANKS 13
#define NUM_SUITS 4
#define NUM_CARDS 5

// external variables
int num_in_rank[NUM_RANKS];
int num_in_suit[NUM_SUITS];
int straight, flush, four, three; // 0 or 1
int pairs;// can be 0, 1, or 2

// prototypes
void read_cards(void);
void analyze_hand(void);
void print_result(void);

int main(void)
{
    for (;;) {
        read_cards();
        analyze_hand();
        print_result();
    }
}

/*
 * Reads the cards into the external variables num_in_rank and num_in_suit;
 * checks for bad cards and duplicate cards
 */
void read_cards(void)
{
    int card_exits[NUM_RANKS][NUM_SUITS];
    char ch, rank_ch, suit_ch;
    int rank, suit;
    int bad_card;
    int cards_read = 0;

    for (rank = 0; rank < NUM_RANKS; rank++) {
        num_in_rank[rank] = 0;
        for (suit = 0; suit < NUM_SUITS; suit++)
            card_exits[rank][suit] = 0;
    }
    for (suit = 0; suit < NUM_SUITS; suit++)
        num_in_suit[suit] = 0;

    while (cards_read < NUM_CARDS) {
        bad_card = 0;

        printf("Enter a card: ");

        rank_ch = getchar();
        switch (rank_ch) {
            case '0':                   exit(EXIT_SUCCESS);
            case '2':                   rank = 0; break;
            case '3':                   rank = 1; break;
            case '4':                   rank = 2; break;
            case '5':                   rank = 3; break;
            case '6':                   rank = 4; break;
            case '7':                   rank = 5; break;
            case '8':                   rank = 6; break;
            case '9':                   rank = 7; break;
            case 't': case 'T':         rank = 8; break;
            case 'j': case 'J':         rank = 9; break;
            case 'q': case 'Q':         rank = 10; break;
            case 'k': case 'K':         rank = 11; break;
            case 'a': case 'A':         rank = 12; break;
            default:                    bad_card = 1;
        }

        suit_ch = getchar();
        switch (suit_ch) {
            case 'c': case 'C':         suit = 0; break;
            case 'd': case 'D':         suit = 1; break;
            case 'h': case 'H':         suit = 2; break;
            case 's': case 'S':         suit = 3; break;
            default:                    bad_card = 1;
        }

        while ((ch = getchar()) != '\n')
            if (ch != ' ')
                bad_card = 1;

        if (bad_card == 1)
            printf("Bad card; ignored.\n");
        else if (card_exits[rank][suit] == 1)
            printf("Duplicate card; ignored.\n");
        else {
            num_in_rank[rank]++;
            num_in_suit[suit]++;
            card_exits[rank][suit] = 1;
            cards_read++;
        }
    }
}

void analyze_hand(void)
{
    int num_consec = 0;
    int rank, suit;

    straight = 0;
    flush = 0;
    four = 0;
    three = 0;
    pairs = 0;

    for (suit = 0; suit < NUM_SUITS; suit++)
        if (num_in_suit[suit] == NUM_CARDS)
            flush = 1;

    rank = 0;
    while (num_in_rank[rank] == 0) rank++;
    for (; rank < NUM_RANKS && num_in_rank[rank] > 0; rank++)
        num_consec++;
    if (num_consec == NUM_CARDS) {
        straight = 1;
        return;
    }

    for (rank = 0; rank < NUM_RANKS; rank++) {
        if (num_in_rank[rank] == 4) four = 1;
        if (num_in_rank[rank] == 3) three = 1;
        if (num_in_rank[rank] == 2) pairs++;
    }
}

void print_result(void)
{
    if (straight == 1 && flush == 1) printf("Straight flush");
    else if (four == 1) printf("Four of a kind");
    else if (three == 1 && pairs == 1) printf("Full house");
    else if (flush == 1) printf("Flush");
    else if (straight == 1) printf("Straight");
    else if (three == 1) printf("Three of a kind");
    else if (pairs == 2) printf("Two pairs");
    else if (pairs == 1) printf("Pair");
    else printf("High card");

    printf("\n\n");
}