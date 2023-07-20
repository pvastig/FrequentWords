#pragma once

#include <map>
#include <string>

namespace pa {
std::map<std::string, int> getMappedWords(const std::string& words);

std::string sortMappedWords(const std::map<std::string, int>& wordsToCount);

} // namespace pa
