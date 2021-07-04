#include <locale>
#include <iostream>
#include <iomanip>

// Este se va a encargar de manejar el separador de miles y el separador de decimales
struct locate_miles : std::numpunct<char> {
     char_type do_thousands_sep() const override { return ','; }
    char_type do_decimal_point() const override { return '.'; }
    string_type do_grouping() const override { return "\3"; }
};

int main()
{
    double number;
    // Aca le asignamos el nuevo manejador al cout
    std::cout.imbue(std::locale(std::cout.getloc(), new locate_miles));

    std::cout << "Number: ";

    std::cin >> number;
   
    //Simplemente lo usamos y listo, aca le agrege ademas para que me muestre solo 2 decimales usando fixed y setprecision
    std::cout << std::endl  << "Output: " << std::fixed << std::setprecision(2) << number << std::endl;

    std::cout << std::endl << std::endl << std::endl << std::endl;

    return 0;
}