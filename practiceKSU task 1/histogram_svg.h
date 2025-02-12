#pragma once
#include <iostream>
#include <vector>
#include <set>
#include <iomanip>
#include <sstream>

const size_t SCREEN_WIDTH = 80;
const size_t MAX_ASTERISK = SCREEN_WIDTH - 3 - 1;

using namespace std;

void svg_begin(double width, double height);

void svg_end();

void svg_text(double left, double baseline, string text);

void svg_rect(double x, double y, double width, double height, string stroke = "black", string fill = "orange");

void show_histogram_svg(const vector<size_t>& bins, set<double> range_num);

