#include "FrequentWords.h"

#include <fstream>
#include <regex>
#include <set>

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

std::string pa::sortMappedWords(const std::map<std::string, int>& wordsToCount)
{
    std::multimap<int, std::string> countToWords;
    std::set<int, std::greater<>> wordCount;
    for (const auto& item : wordsToCount) {
        countToWords.emplace(item.second, item.first);
        wordCount.emplace(item.second);
    }

    using MapIterator = std::multimap<int, std::string>::iterator;
    std::vector<std::pair<MapIterator, MapIterator>> iters;

    for (auto num : wordCount) {
        auto iterator = countToWords.equal_range(num);
        iters.push_back(std::move(iterator));
    }

    std::string output;
    output.reserve(wordsToCount.size());
    for (const auto& item : iters) {
        for (auto it = item.first; it != item.second; ++it) {
            output += std::string(std::to_string(it->first) + " - " + it->second + '\n');
        }
    }

    return output;
}

std::string pa::readWordsFromFile(const std::string& file)
{
    std::ifstream ifs(file);
    if (!ifs) {
        return {};
    }

    return std::string{std::istreambuf_iterator<char>(ifs), std::istreambuf_iterator<char>()};
}

void pa::writeToFile(const std::string& file, const std::string& data)
{
    std::ofstream ofs(file);
    std::copy(data.begin(), data.end(), std::ostreambuf_iterator<char>(ofs));
}

void pa::countFrequentWords(const std::string& inputFile, const std::string& outputFile)
{
    const auto words = pa::readWordsFromFile(inputFile);
    const auto mappedWords = pa::getMappedWords(words);
    const auto sortedWords = pa::sortMappedWords(mappedWords);
    pa::writeToFile(outputFile, sortedWords);
}
