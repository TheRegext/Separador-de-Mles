#include <locale>
#include <iostream>
#include <iomanip>

struct locate_miles : std::numpunct<char> {
     char_type do_thousands_sep() const override { return ','; }
    char_type do_decimal_point() const override { return '.'; }
    string_type do_grouping() const override { return "\3"; }
};

int main()
{
    std::cout.imbue(std::locale(std::cout.getloc(), new locate_miles));
    std::cout << std::fixed << std::setprecision(2) << 1985.67 << '\n'<< 30568526.22;

    return 0;
}