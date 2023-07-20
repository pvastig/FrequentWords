#include "FrequentWords.h"

#include <regex>

std::string strTolower(std::string s)
{
    std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c) { return std::tolower(c); });

    return s;
}

std::map<std::string, int> pa::getMappedWords(const std::string& words)
{
    std::map<std::string, int> wordsToCount;
    const std::regex regex("\\w+");
    for (std::sregex_iterator it(words.begin(), words.end(), regex), end; it != end; ++it) {
        const auto insertedIt = wordsToCount.emplace(strTolower(std::smatch(*it).str()), 1);
        if (!insertedIt.second) {
            ++insertedIt.first->second;
        }
    }

    return wordsToCount;
}
