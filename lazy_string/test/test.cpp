#include <iostream>
#include <vector>
#include <string>
#include <cstring>

#include "lazy_string.h"

void test(const char *what, bool result)
{
    if (result)
        return;
    std::cerr << "Test failed: " << what << std::endl;
    exit(-1);
}

void test_lazy_string_size()
{
#define CMP_STR_SIZES (str_ref.size() == str_test.get_size())
    std::string str_ref("");
    lazy::lazy_string str_test("");
    test("lazy_string size() is valid on empty string", CMP_STR_SIZES);

    str_ref = "1";
    str_test = "1";
    test("lazy_string size() is valid on 1 char string after assignment", CMP_STR_SIZES);

    str_ref = "12345";
    str_test = "12345";
    test("lazy_string size() is valid on non-empty string after assignment", CMP_STR_SIZES);
#undef CMP_STR_SIZES
}

void test_lazy_string_empty()
{
#define CMP_STR_EMPTY (str_ref.empty() == str_test.empty())
    std::string str_ref("");
    lazy::lazy_string str_test("");
    test("lazy_string empty() is valid on empty string", CMP_STR_EMPTY);

    str_ref = "1";
    str_test = "1";
    test("lazy_string empty() is valid on 1 char string after assignment", CMP_STR_EMPTY);

    str_ref = "12345";
    str_test = "12345";
    test("lazy_string empty() is valid on non-empty string after assignment", CMP_STR_EMPTY);
#undef CMP_STR_SIZES
}

void test_lazy_string_get_at()
{
    std::string str_ref = "12345";
    lazy::lazy_string str_test = "12345";

    for (size_t i = 0; i < str_ref.size(); ++i)
    {
        test("lazy_string get_at(i) character is the same as at() of ref string",
            str_ref.at(i) == str_test.get_at(i));
    }
}

void test_lazy_string_c_str()
{
    std::string str_ref = "12345";
    lazy::lazy_string str_test = "12345";
    const char *str_ref_cstr = str_ref.c_str();
    const char *str_test_cstr = str_test.c_str();

    test("lazy_string get_at(i) character is the same as at() of ref string",
        !strcmp(str_ref_cstr, str_test_cstr));
}

void test_lazy_string_memory_intensive()
{
    lazy::lazy_string str_src("foobar");
    std::vector<lazy::lazy_string> strings(10000, str_src);
    str_src.set_at(2, '0');
}

int main()
{
    test_lazy_string_size();
    test_lazy_string_empty();
    test_lazy_string_get_at();
    test_lazy_string_c_str();
    test_lazy_string_memory_intensive();
    return 0;
}
