#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

#include "gtest/gtest.h"
#include "q.h"

TEST(FindAllPasswords, Test1) {
  std::unordered_set<std::string> dictionary = {"ab", "cd"};
  std::unordered_set<std::string> valid_passwords = {"abb", "cdd", "aa", "j"};

  BlackBox blackbox(valid_passwords, dictionary);

  std::unordered_set<std::string> expected = {"aa", "j"};
  auto actual = FindAllPasswords(blackbox, 3);

  EXPECT_EQ(actual, expected);
}

// TODO: Add more tests below!

TEST(FindAllPasswords, AllFilteredOut) {
  std::unordered_set<std::string> dictionary = {"a", "b"};
  std::unordered_set<std::string> valid_passwords = {"aa", "ab", "ba", "bbb"};

  BlackBox blackbox(valid_passwords, dictionary);

  std::unordered_set<std::string> expected = {};
  auto actual = FindAllPasswords(blackbox, 3);

  EXPECT_EQ(actual, expected);
}


TEST(FindAllPasswords, NoDictionaryWords) {
  std::unordered_set<std::string> dictionary = {};
  std::unordered_set<std::string> valid_passwords = {"abc", "xyz", "hi"};

  BlackBox blackbox(valid_passwords, dictionary);

  std::unordered_set<std::string> expected = {"abc", "xyz", "hi"};
  auto actual = FindAllPasswords(blackbox, 3);

  EXPECT_EQ(actual, expected);
}


TEST(FindAllPasswords, LengthLimit) {
  std::unordered_set<std::string> dictionary = {"zz"};
  std::unordered_set<std::string> valid_passwords = {"a", "ab", "abc", "abcd"};

  BlackBox blackbox(valid_passwords, dictionary);

  std::unordered_set<std::string> expected = {"a", "ab"};  // "abc", "abcd" 太长
  auto actual = FindAllPasswords(blackbox, 2);

  EXPECT_EQ(actual, expected);
}


TEST(FindAllPasswords, DictionarySubstringInMiddle) {
  std::unordered_set<std::string> dictionary = {"dg"};
  std::unordered_set<std::string> valid_passwords = {"mdgs", "yodg", "nope", "god"};

  BlackBox blackbox(valid_passwords, dictionary);

  std::unordered_set<std::string> expected = {"nope", "god"};
  auto actual = FindAllPasswords(blackbox, 4);

  EXPECT_EQ(actual, expected);
}

TEST(FindAllPasswords, EmptyValidPasswords) {
  std::unordered_set<std::string> dictionary = {"bad"};
  std::unordered_set<std::string> valid_passwords = {};

  BlackBox blackbox(valid_passwords, dictionary);

  std::unordered_set<std::string> expected = {};
  auto actual = FindAllPasswords(blackbox, 4);

  EXPECT_EQ(actual, expected);
}

//************************************************************ */
template <class T>
void PrintCollection(T& input) {
  std::cout << "{ ";
  unsigned int count = 0;
  for (auto n : input) {
    count++;
    std::cout << n;
    if (count < input.size()) std::cout << ", ";
  }
  std::cout << " }" << std::endl;
}

TEST(FindAllPasswords, AllPasswordsContainAWordInTheDictionary) {
  std::unordered_set<std::string> valid_passwords = {"aa", "bad", "sad", "aa",
                                                     "bbb"};

  std::unordered_set<std::string> dictionary = {"a", "b"};

  std::cout << "valid_passwords:" << std::endl;
  PrintCollection(valid_passwords);
  std::cout << "dictionary:" << std::endl;
  PrintCollection(dictionary);

  BlackBox blackbox(valid_passwords, dictionary);

  std::unordered_set<std::string> expected = {};
  auto actual = FindAllPasswords(blackbox, 3);

  EXPECT_EQ(actual, expected);
}

TEST(FindAllPasswords, NoValidPasswordExists) {
  std::unordered_set<std::string> dictionary = {"a", "b"};

  std::unordered_set<std::string> valid_passwords = {};
  BlackBox blackbox(valid_passwords, dictionary);

  std::unordered_set<std::string> expected = {};

  auto actual = FindAllPasswords(blackbox, 3);

  EXPECT_EQ(actual, expected);
}

TEST(FindAllPasswords, SimplePasswords0) {
  std::unordered_set<std::string> dictionary = {"ab", "cd"};
  std::unordered_set<std::string> valid_passwords = {"abb", "cdd", "aa", "j"};
  BlackBox blackbox(valid_passwords, dictionary);

  std::unordered_set<std::string> expected = {"aa", "j"};

  auto actual = FindAllPasswords(blackbox, 3);

  EXPECT_EQ(actual, expected);
}


TEST(FindAllPasswords, SimplePasswords2) {
  std::unordered_set<std::string> dictionary = {"c", "d", "e", "f"};
  std::unordered_set<std::string> valid_passwords = {"abc", "tin", "aa", "j"};
  BlackBox blackbox(valid_passwords, dictionary);

  std::unordered_set<std::string> expected = {"aa", "j", "tin"};

  auto actual = FindAllPasswords(blackbox, 3);

  EXPECT_EQ(actual, expected);
}

TEST(FindAllPasswords, SimplePasswords5) {
  std::unordered_set<std::string> dictionary = {"bad", "sad", "f", "t"};

  std::unordered_set<std::string> valid_passwords = {
      "asad", "bada", "zz", "aa", "bbbbb", "bcdef", "jklmn", "trojan", "apple"};

  BlackBox blackbox(valid_passwords, dictionary);
  std::unordered_set<std::string> expected = {"aa", "bbbbb", "zz", "jklmn",
                                              "apple"};

  auto actual = FindAllPasswords(blackbox, 5);

  EXPECT_EQ(actual, expected);
}