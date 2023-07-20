#include <FrequentWords.h>

#include <iostream>

int main(const int argc, char** argv)
{
    if (argc != 3) {
        std::cerr << "Incorrect input arguments, please type input and output file names";
        return 1;
    }

    pa::countFrequentWords(argv[1], argv[2]);

    return 0;
}
