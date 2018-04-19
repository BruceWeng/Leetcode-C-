/*
Implement strStr().

Return the index of the first occurrence of needle in haystack, or -1 if needle
is not part of haystack.

Example 1:

Input: haystack = "hello", needle = "ll"
Output: 2
Example 2:

Input: haystack = "aaaaa", needle = "bba"
Output: -1
Clarification:

What should we return when needle is an empty string? This is a great question to
ask during an interview.

For the purpose of this problem, we will return 0 when needle is an empty string.
This is consistent to C's strstr() and Java's indexOf().
*/
/*
Algorithm:
1. Traverse all the possible starting points of haystack (from 0 to haystack.length() - needle.length()),
see if the following characters in haystack match match those in needle.

*/
#include <iostream>

int strStr(std::string haystack, std::string needle) {
  int m = haystack.length();
  int n = needle.length();
  if (n == 0) return 0;
  // The upper bound sets to m - n + 1 for comparing the case i == j
  for (int i = 0; i < m - n + 1; i++) {
    int j = 0;
    for (; j < n; j++) {
      if (haystack[i + j] != needle[j]) {
        break;
      }
    }

    if (j == n) {
      return i;
    }
  }

  return -1;
}
int main() {
  std::string haystack1 = "hello";
  std::string needle1 = "ll";
  std::cout << strStr(haystack1, needle1) << std::endl; // 2
}
