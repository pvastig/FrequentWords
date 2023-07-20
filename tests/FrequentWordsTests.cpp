#include "FrequentWords.h"

#include <gtest/gtest.h>

namespace pa {

TEST(FrequentWords, SimpleCases)
{
    {
        const std::string text;
        const auto words = getMappedWords(text);
        ASSERT_EQ(words.size(), 0);
    }
    {
        const std::string text = "a";
        const auto words = getMappedWords(text);
        ASSERT_EQ(words.size(), 1);
        ASSERT_EQ(words.cbegin()->first, "a");
        ASSERT_EQ(words.cbegin()->second, 1);
    }
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
    {
        const std::string text = "A A A";
        const auto words = getMappedWords(text);
        ASSERT_EQ(words.size(), 1);
        ASSERT_EQ(words.cbegin()->first, "a");
        ASSERT_EQ(words.cbegin()->second, 3);
    }
}
TEST(FrequentWords, ComplexCases)
{
    {
        std::map<std::string, int> refWords{
            {"come", 1},
            {"has", 1},
            {"many", 1},
            {"of", 1},
            {"sad", 1},
            {"talk", 1},
            {"the", 2},
            {"things", 1},
            {"time", 1},
            {"to", 1},
            {"warlis", 1},

        };
        const std::string text = "The time has come, the Warlis sad to talk of many things...";
        const auto words = getMappedWords(text);
        ASSERT_EQ(words.size(), 11);
        auto refIt = refWords.cbegin();
        auto it = words.cbegin();
        for (; refIt != refWords.cend(); ++refIt, ++it) {
            ASSERT_EQ(refIt->first, it->first);
            ASSERT_EQ(refIt->second, it->second);
        }
    }
}

} // namespace pa
