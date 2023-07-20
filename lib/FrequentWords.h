#pragma once

#include <map>
#include <string>

namespace pa {
std::map<std::string, int> getMappedWords(const std::string& words);

std::string sortMappedWords(const std::map<std::string, int>& wordsToCount);

std::string readWordsFromFile(const std::string& file);

void writeToFile(const std::string& file, const std::string& data);

void countFrequentWords(const std::string& inputFile, const std::string& outputFile);

} // namespace pa
