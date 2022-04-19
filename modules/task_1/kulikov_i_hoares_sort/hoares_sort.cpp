// Copyright 2021 Kulikov Ilya
#include <mpi.h>
#include <random>
#include "../../../modules/task_1/kulikov_i_hoares_sort/hoares_sort.h"


int* get_random_str(int sz) {
    int* out_str = new int[sz + 1];

    std::random_device dev;
    std::mt19937 gen(dev());

    for (int i = 0; i < sz; i++) { out_str[i] = gen() % 100000; }
    return out_str;
}

void quicksort(int *mas, int first, int last) {
    int mid, count;
    int f = first, l = last;
    mid = mas[(f + l) / 2];
    do {
        while (mas[f] < mid) f++;
        while (mas[l] > mid) l--;
        if (f <= l) {
            count = mas[f];
            mas[f] = mas[l];
            mas[l] = count;
            f++;
            l--;
        }
    } while (f < l);
    if (first < l) quicksort(mas, first, l);
    if (f < last) quicksort(mas, f, last);
}

bool check(int* mas, int size) {
    bool res = true;

    for (int i = 0; i < size - 1; i++) {
        if (mas[i] > mas[i + 1]) {
            res = false;
            break;
        }
    }

    return res;
}
