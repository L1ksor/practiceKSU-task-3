#pragma once
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <string>
#include <set>
const size_t SCREEN_WIDTH = 80;
const size_t MAX_ASTERISK = SCREEN_WIDTH - 3 - 1;

vector<double> input_numbers(size_t count);

void find_minmax(const vector<double>& numbers, double& min, double& max);

pair<vector<size_t>, set<double>> make_histogram(const vector<double>& numbers, size_t bin_count);

void show_histogram_text(const std::vector<size_t>& bins, const size_t& bin_count);

void show_histogram_svg(const vector<size_t>& bins, set<double> range_num);

