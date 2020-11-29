//
// Created by Jason Qin on 2020/11/29.
//

#include <stdio.h>

#define N 10

void print(int a[], int low, int high);
void swap(int a[], int i, int j);
int split(int a[], int low, int high);
void quicksort(int a[], int low, int high);

int main(void)
{
    int a[N], i;

    printf("Enter %d numbers to be sorted: ", N);
    for (i = 0; i < N; i++)
        scanf("%d", &a[i]);

    quicksort(a, 0, N - 1);
    print(a, 0, N - 1);
    printf("\n");

    return 0;
}

void print(int a[], int low, int high)
{
    if (low > high) return;
    for (int i = low; i <= high; i++)
        printf("%d ", a[i]);
}


void quicksort(int a[], int low, int high)
{
    int middle;

    if (low >= high) return;
    middle = split(a, low, high);
    quicksort(a, low, middle - 1);
    quicksort(a, middle + 1, high);
}

int split(int a[], int low, int high)
{
    int part_element = a[low];
    int i = low, j = high + 1;
    while (1) {
        while (i < high && a[++i] < part_element);
        while (j > low && a[--j] >= part_element);
        if (i >= j)
            break;
        swap(a, i, j);
    }
    swap(a, low, j);
    print(a, low, high);
    printf("\n");
    return j;
}

void swap(int a[], int i, int j)
{
    printf("swap %d %d\n", a[i], a[j]);
    if (i == j) return;
    int tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}