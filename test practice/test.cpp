#include <cassert>
#include "..\practiceKSU task 1\histogram.h"

using namespace std;

void test_three_num() {
    double min = 0, max = 0;
    find_minmax({ 1,2,3 }, min, max);
    assert(min == 1);
    assert(max == 3);
}

void test_one_num() {
    double min = 0, max = 0;
    find_minmax({ 1 }, min, max);
    assert(min == 1);
    assert(max == 1);
}

void test_three_similar() {
    double min = 0, max = 0;
    find_minmax({ 1, 1, 1 }, min, max);
    assert(min == 1);
    assert(max == 1);
}

void test_zero_num() {
    double min = 0, max = 0;
    find_minmax({}, min, max);
    assert(min == 0);
    assert(max == 0);
}

int main() {
    test_three_num();
    test_one_num();
    test_three_similar();
    test_zero_num();
}