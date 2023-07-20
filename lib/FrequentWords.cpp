#include "FrequentWords.h"

#include <regex>

std::map<std::string, int> pa::getMappedWords(const std::string& words)
{
    std::map<std::string, int> wordsToCount;
    const std::regex regex("\\w+");
    for (std::sregex_iterator it(words.begin(), words.end(), regex), end; it != end; ++it) {
        std::smatch match(*it);
        const auto insertedIt = wordsToCount.emplace(match.str(), 1);
        if (!insertedIt.second) {
            ++insertedIt.first->second;
        }
    }

    return wordsToCount;
}
