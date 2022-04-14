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

void hoares_sort_(int* str1, int* str2) {
    // if (str2 - str1 <= 1) return;
    int z = *(str1 + (str2 - str1) / 2);
    int* sub_str1 = str1, *sub_str2 = str2 - 1;
    while (sub_str1 <= sub_str2) {
        while (*sub_str1 < z) sub_str1++;
        while (*sub_str2 > z) sub_str2--;
        if (sub_str1 <= sub_str2) {
            std::swap(*sub_str1, *sub_str2);
            sub_str1++;
            sub_str2--;
        }
    }
    if (str1 < sub_str2) hoares_sort_(str1, sub_str2 + 1);
    if (sub_str1 < str2) hoares_sort_(sub_str1, str2);
}

void hoares_sort(int* str, int sz) {
    hoares_sort_(str, str + sz / 2);
}
