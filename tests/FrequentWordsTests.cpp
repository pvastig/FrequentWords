#include "FrequentWords.h"

#include <gtest/gtest.h>

namespace pa {

TEST(FrequentWords, SimpleCases)
{
    {
        const std::string text = "a a a";
        const auto words = getMappedWords(text);
        ASSERT_EQ(words.size(), 1);
        ASSERT_EQ(words.cbegin()->first, "a");
        ASSERT_EQ(words.cbegin()->second, 3);
    }
    {
        const std::string text = "a,a!a";
        const auto words = getMappedWords(text);
        ASSERT_EQ(words.size(), 1);
        ASSERT_EQ(words.cbegin()->first, "a");
        ASSERT_EQ(words.cbegin()->second, 3);
    }
    {
        const std::string text = "!a-a;a";
        const auto words = getMappedWords(text);
        ASSERT_EQ(words.size(), 1);
        ASSERT_EQ(words.cbegin()->first, "a");
        ASSERT_EQ(words.cbegin()->second, 3);
    }
}
TEST(FrequentWords, CamelCases)
{
    {
        const std::string text = "A A A";
        const auto words = getMappedWords(text);
        ASSERT_EQ(words.size(), 1);
        ASSERT_EQ(words.cbegin()->first, "a");
        ASSERT_EQ(words.cbegin()->second, 3);
    }
}

} // namespace pa
