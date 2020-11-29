//
// Created by Jason Qin on 2020/11/29.
// Reverses a series of numbers (pointer version)
//

#include <stdio.h>

#define N 10

int main(void)
{
    int a[N], *p;

    printf("Enter %d numbers: ", N);
    for (p = a; p < a + N; p++)
        scanf("%d", p);

    printf("In reverse order: ");
    for (p = a + N - 1; p >= a; p--)
        (" %d", *p);
    printf("\n");

    return 0;
}

