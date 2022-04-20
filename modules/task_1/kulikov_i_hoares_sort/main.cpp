// Copyright 2021 Kulikov Ilya
#include <mpi.h>
#include <gtest/gtest.h>
#include <vector>
#include <gtest-mpi-listener.hpp>
#include "../../../modules/task_1/kulikov_i_hoares_sort/hoares_sort.h"

TEST(MPI_1root, Test_10) {
    int* string1 = get_random_str(10);

    quicksort(string1, 0, 10);

    bool res;
    res = check(string1, 10);

    EXPECT_EQ(res, true);

    delete[] string1;
}

TEST(MPI_1root, Test_25) {
    int* string1 = get_random_str(25);

    quicksort(string1, 0, 25);

    bool res;
    res = check(string1, 25);

    EXPECT_EQ(res, true);

    delete[] string1;
}

TEST(MPI_1root, Test_50) {
    int* string1 = get_random_str(50);

    quicksort(string1, 0, 50);

    bool res;
    res = check(string1, 50);

    EXPECT_EQ(res, true);

    delete[] string1;
}

TEST(MPI_1root, Test_100) {
    int* string1 = get_random_str(100);

    quicksort(string1, 0, 100);

    bool res;
    res = check(string1, 100);

    EXPECT_EQ(res, true);

    delete[] string1;
}

TEST(MPI_1root, Test_110) {
    int* string1 = get_random_str(110);

    quicksort(string1, 0, 110);

    bool res;
    res = check(string1, 110);

    EXPECT_EQ(res, true);

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
