﻿/*
Добавьте на ось подписей границы столбцов. 
Например, если в первый столбец отнесены элементы от наименьшего до 1,23, 
во второй — от 1,23 до 2,34 и т. д., желаемый результат:

     8|********
1.23
    11|***********
2.34
     6|******

     
*/
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include "practiceKSU task 1.h"
using namespace std;

const size_t SCREEN_WIDTH = 80;
const size_t MAX_ASTERISK = SCREEN_WIDTH - 3 - 1;

vector<double> input_numbers(size_t count) 
{
    vector<double> result(count);
    for (size_t i = 0; i < count; i++) 
        cin >> result[i];
    
    return result;
}

void find_minmax(const vector<double>& numbers, double& min, double& max) 
{
    min = numbers[0];
    max = numbers[0];
    for (double x : numbers)
    {
        if (x < min)
            min = x;
        else if (x > max)
            max = x;
    }
}

vector<size_t> make_histogram(const vector<double>& numbers, size_t bin_count)
{
    vector<size_t> bins(bin_count);

    double min, max;
    find_minmax(numbers, min, max);

    double bin_size = (max - min) / bin_count;

    int cnt = 0;
    for (size_t i = 0; i < numbers.size(); i++)
    {
        bool found = false;
        for (size_t j = 0; (j < bin_count - 1) && !found; j++)
        {
            auto lo = min + j * bin_size;
            auto hi = min + (j + 1) * bin_size;
            if ((lo <= numbers[i]) && (numbers[i] < hi))
            {
                bins[j]++;
                found = true;
            }
        }
        if (!found)
            bins[bin_count - 1]++;
    }
    return bins;
}

void show_histogram_text(const std::vector<size_t>& bins, const size_t& bin_count)
{
    size_t max_bins = *max_element(bins.begin(), bins.end());

    for (int i = 0; i < bin_count; i++)
    {

        size_t height = 1 * bins[i];
        if (max_bins > MAX_ASTERISK)
            height = MAX_ASTERISK * (static_cast<double>(bins[i]) / max_bins);

        string stars(height, '*');

        if (bins[i] < 100)
            cout << " ";
        if (bins[i] < 10)
            cout << " ";

        cout << bins[i] << '|' << stars << endl;
    }
}

int main()
{
    size_t number_count, bin_count;

    cerr << "Enter number count: ";
    cin >> number_count ; 
    const auto numbers = input_numbers(number_count);

    cerr << "Enter number bins: ";
    cin >> bin_count;

    const auto bins = make_histogram(numbers, bin_count);
    
    show_histogram_text(bins, bin_count);
}






