#include <cassert>
#include "..\practiceKSU task 1\histogram.h"

using namespace std;

void test_numbers_3()
{
    double min = 0, max = 0;
    find_minmax({ 1,2,3 }, min, max);
    assert(min == 1);
    assert(max == 3);
}

void test_num()
{
    double min = 0, max = 0;
    find_minmax({ 1 }, min, max);
    assert(min == 1);
    assert(max == 1);
}

void test_numbers_equal()
{
    double min = 0, max = 0;
    find_minmax({ 1, 1, 1 }, min, max);
    assert(min == 1);
    assert(max == 1);
}

void test_empty()
{
    double min = 0, max = 0;
    find_minmax({}, min, max);
    assert(min == 0);
    assert(max == 0);
}

void test_format_num_double()
{
    double num = 3.141592;
    string s = format_number_svg(num);
    assert(s == "3.14");
}

void test_format_num_int()
{
    double num = 5;
    string s = format_number_svg(num);
    assert(s == "5");
}

int main() 
{
    test_numbers_3();
    test_num();
    test_numbers_equal();
    test_empty();
    test_format_num_int();
    test_format_num_double();
}