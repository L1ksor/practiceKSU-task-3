
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <string>
using namespace std;

#include "practiceKSU task 1.h"

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

void show_histogram_text(const std::vector<size_t>& bins)
{
    size_t max_bins = *max_element(bins.begin(), bins.end());
    size_t bin_count = bins.size();
    for (int i = 0; i < bin_count; i++)
    {

        size_t height = bins[i];
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

void svg_begin(double width, double height) 
{
    cout << "<?xml version='1.0' encoding='UTF-8'?>\n";
    cout << "<svg ";
    cout << "width='" << width << "' ";
    cout << "height='" << height << "' ";
    cout << "viewBox='0 0 " << width << " " << height << "' ";
    cout << "xmlns='http://www.w3.org/2000/svg'>\n";
}

void svg_end() 
{
    cout << "</svg>\n";
}

void svg_text(double left, double baseline, string text)
{
    cout << "<text x='" << left << "' y='" << baseline << "'>" << text << "</text>" << '\n';
}
void svg_rect(double x, double y, double width, double height, string stroke = "black", string fill = "orange")
{
    printf("<rect x='%lf' y='%lf' width='%lf' height='%lf' stroke='%s' fill='%s'/>\n", x, y, width, height, stroke.c_str(), fill.c_str());
}

void show_histogram_svg(const vector<size_t>& bins) 
{
    
    const auto IMAGE_WIDTH = 400;
    const auto IMAGE_HEIGHT = 300;
    const auto TEXT_BASELINE = 20;
    const auto TEXT_WIDTH = 50;
    const auto BIN_HEIGHT = 30;
    double top = 0;
    size_t max_bins = *max_element(bins.begin(), bins.end());
    svg_begin(IMAGE_WIDTH, IMAGE_HEIGHT);
    for (auto bin : bins) 
    {
        size_t text_left = 30;
        if (bin < 100)
            text_left = 40;
        else if (bin < 10) 
            text_left = 50;

        size_t block_width = 10;
        if (max_bins > MAX_ASTERISK)
            block_width = MAX_ASTERISK * (static_cast<double>(bin) / max_bins);

        svg_text(text_left, top + TEXT_BASELINE, to_string(bin));

        const double bin_width = block_width * bin;
        svg_rect(TEXT_WIDTH, top, bin_width, BIN_HEIGHT);
        top += BIN_HEIGHT;
    }
    svg_end();
}



int main()
{
    size_t number_count, bin_count;

    cerr << "Enter number count: ";
    cin >> number_count;
    const auto numbers = input_numbers(number_count);

    cerr << "Enter number bins: ";
    cin >> bin_count;

    const auto bins = make_histogram(numbers, bin_count);

    show_histogram_svg(bins);
}

