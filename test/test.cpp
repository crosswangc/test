#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include <iostream>
#include <vector>
#include <algorithm>

#include "common/common.h"
// #include "datastructure/trie.h"
#include "datastructure/trie.h"

using namespace testing;
using namespace std;
// using namespace std::placeholders;

TEST(trim_test, trim_space)
{
    string str = "hello world";
    string s = trim(str);
    EXPECT_EQ(s, "helloworld"); // string cmp, not c-string
}

TEST(Add_test, functor)
{
    vector<int> coll = {11, 12, 13};
    for_each(coll.begin(), coll.end(), Add<int>(*coll.begin()));
    EXPECT_THAT(coll, ElementsAre(22, 23, 24));
}
// for_each
TEST(MeanValue_test, for_each_return)
{
    vector<int> nums = {1, 2, 3, 4, 5};
    double mean = for_each(nums.begin(), nums.end(), MeanValue<int>());
    EXPECT_EQ(mean, 3) << "The actual mean is " << mean << ".";
}
// count_if and find_if
TEST(count_find_test, count_find_if)
{
    vector<int> nums = {1, 2, 2, 4, 5};
    EXPECT_EQ(count(nums.cbegin(), nums.cend(), 2), 2);
    EXPECT_EQ(count_if(nums.cbegin(), nums.cend(), [](int elem)
                       { return elem % 2 == 0; }), 3);
    auto pos = find_if(nums.begin(), nums.end(), bind(greater<int>(), placeholders::_1, 4));
    EXPECT_EQ(*pos, 5);
}
// min_element
TEST(min_test, min_element)
{
    vector<int> nums = {1, -2, -3, 4, -5};
    auto mm = min_element(nums.cbegin(), nums.cend(), absLess<int>);
    EXPECT_EQ(*mm, 1);
}

TEST(trie_test, trie)
{
    Trie t;
    vector<string> words = {"Rachit", "Ramesh", "Ankit", "Ankita", "Rachit1"};
    sort(words.begin(), words.end());
    for (auto w : words)
    {
        t.insert(w);
    }

    EXPECT_THAT(t.autoComplete(""), words);
    EXPECT_THAT(t.autoComplete("Ra"), ElementsAre("Rachit", "Rachit1", "Ramesh"));
    EXPECT_THAT(t.autoComplete("Rachit"), ElementsAre("Rachit", "Rachit1"));
    EXPECT_THAT(t.autoComplete("Rachit1"), ElementsAre("Rachit1"));
    EXPECT_THAT(t.autoComplete("Rachit12"), ElementsAre());

    EXPECT_TRUE(t.hasPrefix(""));
    EXPECT_FALSE(t.hasPrefix("Racht"));
    EXPECT_TRUE(t.hasPrefix("Rachit"));
    EXPECT_TRUE(t.hasPrefix("Rachit1"));
    EXPECT_FALSE(t.hasPrefix("Rachit12"));

    EXPECT_EQ(t.matchLength("Ract"), 3);
    EXPECT_EQ(t.matchLength(""), 0);

    EXPECT_TRUE(t.search(string("Rachit")));
    EXPECT_FALSE(t.search(string("hello")));
    EXPECT_TRUE(t.startsWith(string("Rach")));
    EXPECT_FALSE(t.startsWith(string("hel")));
    // t.remove(string("Rachit"));
    // EXPECT_THAT(t.getAllWords(), ElementsAre("Ramesh", "Ankit", "Ankita", "Rachit1"));
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}