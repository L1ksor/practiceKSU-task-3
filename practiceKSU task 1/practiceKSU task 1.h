#pragma once
using namespace std;
vector<double> input_numbers(size_t count);

void find_minmax(const vector<double>& numbers, double& min, double& max);

pair<vector<size_t>, set<double>> make_histogram(const vector<double>& numbers, size_t bin_count);

void show_histogram_text(const std::vector<size_t>& bins, const size_t& bin_count);

void svg_begin(double width, double height);

void svg_end();

void svg_text(double left, double baseline, string text);

void show_histogram_svg(const vector<size_t>& bins, set<double> range_num);

void svg_rect(double x, double y, double width, double height, string stroke, string fill);

string format_number(double num);