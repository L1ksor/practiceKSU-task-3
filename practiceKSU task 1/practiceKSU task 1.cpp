

#include "histogram.h"
#include "practiceKSU task 1.h"
using namespace std;
vector<double> input_numbers(size_t count)
{
    vector<double> result(count);
    for (size_t i = 0; i < count; i++)
        cin >> result[i];

    return result;
}

pair<vector<size_t>, set<double>> make_histogram(const vector<double>& numbers, size_t bin_count)
{
    vector<size_t> bins(bin_count);
    set<double> range_num;
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
            range_num.insert(hi);
        }
        if (!found)
            bins[bin_count - 1]++;
    }
    
    auto res = make_pair(bins, range_num);
    
    return res;
}

void show_histogram_text(const vector<size_t>& bins, set<double> range_num)
{
    size_t max_bins = *max_element(bins.begin(), bins.end());
    size_t bin_count = bins.size();
    auto it = range_num.begin();
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
        if (i != bin_count - 1)
        {
            cout << setprecision(3) << *it << endl;
            it++;
        }
    }
}



int main()
{
    size_t number_count, bin_count;

    cerr << "Enter number count: ";
    cin >> number_count;
    const auto numbers = input_numbers(number_count);

    cerr << "Enter number bins: ";
    cin >> bin_count;

    const pair<vector<size_t>, set<double>> pair = make_histogram(numbers, bin_count);
    auto bins = pair.first;
    auto range_num = pair.second;
    show_histogram_svg(bins, range_num);
}

