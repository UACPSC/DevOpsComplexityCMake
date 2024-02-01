/*
    srcComplexity.cpp

    Calculates the cyclomatic complexity of a source code function/method.

    Input source code must be in srcML format.
*/

#include <iostream>
#include <string_view>

#include "srcMLXPathCount.hpp"

int main(int argc, const char* argv[]) {

    // number of arguments is 0..1
    if (argc > 2) {
        std::cerr << "Usage: " << argv[0] << " <srcML_filename>" << '\n'
                  << "       " << argv[0] << '\n';
        return 1;
    }

    // input is filename, or stdin as "-"
    std::string_view filename = argc == 2 ? argv[1] : "-";

    // The cyclomatic complexity for a single function/method is the number of conditions + 1,
    // e.g., f() has 2 conditions (and complexity 3), and g() has 3 conditions (and complexity 4).
    // For multiple functions/methods, count the conditions and the number of functions,
    // e.g., for f() and g() the count of conditions is 2 + 3 = 5 and the count of functions is 2.
    int complexity = srcMLXPathCount(filename, "count(//src:condition | //src:function)");
    if (complexity < 0) {
        std::cerr << "Error in applying xpath\n";
        return 1;
    }

    // output the cyclomatic complexity
    std::cout << complexity << '\n';

    return 0;
}
