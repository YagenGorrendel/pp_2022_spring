// Copyright 2021 Kulikov Ilya
#include <mpi.h>
#include <gtest/gtest.h>
#include <vector>
#include <gtest-mpi-listener.hpp>
#include "../../../modules/task_1/kulikov_i_hoares_sort/hoares_sort.h"

int sz = 1000;

TEST(MPILexicalOrdering, IdenticalTest) {
    int* string1 = get_random_str(sz);

    hoares_sort(string1, sz);

    for (int i = 0; i < sz; i++) {
        int result = 0;
        if (string1[i] < string1[i + 1]) {
            result++;
        }
        EXPECT_EQ(result, 1);
    }
    delete[] string1;
}

TEST(MPILexicalOrdering1, IdenticalTest) {
    int* string1 = get_random_str(sz);

    hoares_sort(string1, sz);

    for (int i = 0; i < sz; i++) {
        int result = 0;
        if (string1[i] < string1[i + 1]) {
            result++;
        }
        EXPECT_EQ(result, 1);
    }
    delete[] string1;
}

TEST(MPILexicalOrdering2, IdenticalTest) {
    int* string1 = get_random_str(sz);

    hoares_sort(string1, sz);

    for (int i = 0; i < sz; i++) {
        int result = 0;
        if (string1[i] < string1[i + 1]) {
            result++;
        }
        EXPECT_EQ(result, 1);
    }
    delete[] string1;
}

TEST(MPILexicalOrdering3, IdenticalTest) {
    int* string1 = get_random_str(sz);

    hoares_sort(string1, sz);

    for (int i = 0; i < sz; i++) {
        int result = 0;
        if (string1[i] < string1[i + 1]) {
            result++;
        }
        EXPECT_EQ(result, 1);
    }
    delete[] string1;
}

TEST(MPILexicalOrdering4, IdenticalTest) {
    int* string1 = get_random_str(sz);

    hoares_sort(string1, sz);

    for (int i = 0; i < sz; i++) {
        int result = 0;
        if (string1[i] < string1[i + 1]) {
            result++;
        }
        EXPECT_EQ(result, 1);
    }
    delete[] string1;
}


int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    MPI_Init(&argc, &argv);

    ::testing::AddGlobalTestEnvironment(new GTestMPIListener::MPIEnvironment);
    ::testing::TestEventListeners& listeners =
        ::testing::UnitTest::GetInstance()->listeners();

    listeners.Release(listeners.default_result_printer());
    listeners.Release(listeners.default_xml_generator());

    listeners.Append(new GTestMPIListener::MPIMinimalistPrinter);
    return RUN_ALL_TESTS();
}
