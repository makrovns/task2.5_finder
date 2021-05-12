#include <gtest/gtest.h>
#include "myfind_key_library.hpp"
#include <algorithm>


TEST(my_find_key_test, int_to_string)
{
    my_pair_vector<int,std::string> int_string_vec = { {12,"srt"}, {15,"sada"}, {16,"sada"}, {9,"sddada"}, {7, "Hellow world!"}};
    
    std::sort(int_string_vec.begin(), int_string_vec.end());

    auto answ = myfind::find_key<int,std::string>(int_string_vec, 7);

    ASSERT_EQ(7, answ->first);

    ASSERT_EQ("Hellow world!", answ->second);
}

TEST(my_find_key_test, double_to_string) 
{
    my_pair_vector<double, std::string> double_string_vec = { {12.1,"Nice task"}, {1.5,"sada"}, {0.16,"sada"}, {9.4,"sddada"}, {7.7, "Hellow world!"} };

    std::sort(double_string_vec.begin(), double_string_vec.end());

    auto answ = myfind::find_key<double, std::string>(double_string_vec, 12.1);

    ASSERT_EQ(12.1, answ->first);

    ASSERT_EQ("Nice task", answ->second);
}

TEST(my_find_key_test, int_to_double)
{
    my_pair_vector<int, double> int_double_vec = { {1, 8.44}, {4, 15.9}, {16, 7.15}, {12, 9.1}, {10, 9.7} };

    std::sort(int_double_vec.begin(), int_double_vec.end());

    auto answ = myfind::find_key<int, double>(int_double_vec, 16);

    ASSERT_EQ(16, answ->first);

    ASSERT_EQ(7.15, answ->second);
}

TEST(my_find_key_test, string_to_int)
{
    my_pair_vector<std::string, int> string_int_vec = { {"vasya", 111}, {"petya", 322}, {"vova", 123}, {"kolya", 86}};

    std::sort(string_int_vec.begin(), string_int_vec.end());

    auto answ = myfind::find_key<std::string, int>(string_int_vec, "petya");

    ASSERT_EQ("petya", answ->first);

    ASSERT_EQ(322, answ->second);
}

TEST(my_find_key_test, test_for_unknown_key)
{
    my_pair_vector<int, double> int_double_vec = { {1, 8.44}, {4, 15.9}, {16, 7.15}, {12, 9.1}, {10, 9.7} };

    std::sort(int_double_vec.begin(), int_double_vec.end());

    auto answ = myfind::find_key<int, double>(int_double_vec, 2);

    ASSERT_EQ(answ, int_double_vec.end());
}

TEST(my_find_key_test, test_for_zero_in)
{
    my_pair_vector<int, double> int_double_vec;

    auto answ = myfind::find_key<int, double>(int_double_vec, 2);

    ASSERT_EQ(answ, int_double_vec.end());
}

TEST(my_find_key_test, test_for_value_wich_more_that_last_number_in_vec)
{
    my_pair_vector<int, double> int_double_vec = { {1, 8.44}, {4, 15.9}, {16, 7.15}, {12, 9.1}, {10, 9.7} };

    auto answ = myfind::find_key<int, double>(int_double_vec, 9999);

    ASSERT_EQ(answ, int_double_vec.end());
}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}