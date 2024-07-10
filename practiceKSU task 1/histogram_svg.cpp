

#include "histogram_svg.h"
#include "histogram.h"


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
void svg_rect(double x, double y, double width, double height, string stroke, string fill)
{
    printf("<rect x='%lf' y='%lf' width='%lf' height='%lf' stroke='%s' fill='%s'/>\n", x, y, width, height, stroke.c_str(), fill.c_str());
}

void show_histogram_svg(const vector<size_t>& bins, set<double> range_num)
{

    const auto IMAGE_WIDTH = 400;
    const auto IMAGE_HEIGHT = 300;
    const auto TEXT_BASELINE = 20;
    const auto TEXT_WIDTH = 50;
    const auto BIN_HEIGHT = 30;
    double top = 0;
    auto range = range_num.begin();
    size_t max_bins = *max_element(bins.begin(), bins.end());
    svg_begin(IMAGE_WIDTH, IMAGE_HEIGHT);
    for (int i = 0; i < bins.size(); i++)
    {
        size_t text_left = 30;
        if (bins[i] < 100)
            text_left = 40;
        else if (bins[i] < 10)
            text_left = 50;

        size_t block_width = 10;
        if (max_bins > MAX_ASTERISK)
            block_width = MAX_ASTERISK * (static_cast<double>(bins[i]) / max_bins);

        svg_text(text_left, top + TEXT_BASELINE, to_string(bins[i]));
        const double bin_width = block_width * bins[i];
        svg_rect(TEXT_WIDTH, top, bin_width, BIN_HEIGHT);
        if (i != bins.size() - 1)
        {
            svg_text(text_left - 30, top + TEXT_BASELINE + 13, format_number_svg(*range));
            range++;
        }
        top += BIN_HEIGHT;
    }
    svg_end();
}