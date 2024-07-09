#pragma once

vector<double> input_numbers(size_t count);

void find_minmax(const vector<double>& numbers, double& min, double& max);

vector<size_t> make_histogram(const vector<double>& numbers, size_t bin_count);

void show_histogram_text(const std::vector<size_t>& bins, const size_t& bin_count);

void svg_begin(double width, double height);

void svg_end();

void svg_text(double left, double baseline, string text);

void show_histogram_svg(const vector<size_t>& bins);

void show_histogram_svg(const vector<size_t>& bins);

void svg_rect(double x, double y, double width, double height, string stroke, string fill);