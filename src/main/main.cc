#include <iostream>
#include "src/lib/solution.h"

int main()
{
    Solution solution ;
    string input="abc ef 12 g e rt";
    string output;
    output=solution.rearrange(input);
    cout << output <<endl;

    return EXIT_SUCCESS;
}