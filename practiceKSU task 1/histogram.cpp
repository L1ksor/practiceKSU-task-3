

#include "histogram.h"

void find_minmax(const vector<double>& numbers, double& min, double& max)
{
    if (!numbers.empty())
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
}

string format_number_svg(double num)
{
    ostringstream stream;
    stream << setprecision(3) << num;
    return stream.str();
}
