/*
 * @lc app=leetcode.cn id=819 lang=cpp
 *
 * [819] 最常见的单词
 */

// @lc code=start
#include <string>
#include <vector>
#include <unordered_map>
#include <cstdint>
#include <cctype>
#include <iostream>
using namespace std;

class Solution {
public:
    inline bool isSynbol(uint8_t c) {
        return (c == ' ' || c == '!' || c == '?' || c == '\'' || c == ',' || c == ';' || c == '.');
    }

    inline bool isBanned(string& s, vector<string>& banned) {
        for (string t: banned) {
            if (s == t)
                return false;
        }
        return true;
    }

    // inline string& toLower(string& s) {
    //     for (uint16_t i = 0; i < s.size(); ++i) {
    //         if (isupper(s.at(i)))
    //             s.at(i) = tolower(s.at(i));
    //     }
    //     return s;
    // }

    inline string& toLower(string& s) {
        for (auto i = s.begin(); i < s.end(); ++i) {
            if (isupper(*i))
                (*i) = static_cast<uint8_t>(tolower(*i));
        }
        return s;
    }

    // string mostCommonWord(string paragraph, vector<string>& banned) {
    //     unordered_map<string, uint16_t> Map;
    //     uint16_t i, j, max;
    //     string strMax, strTemp;
    //     for (i = 0, j = 0, max = 0; i <= paragraph.size(); ++i) {
    //         if (i == paragraph.size() || isSynbol(paragraph.at(i))) {
    //             if (i != j) { // Not adjacent symbols
    //                 strTemp = paragraph.substr(j, i - j);
    //                 toLower(strTemp);
    //                 if (isBanned(strTemp, banned)) {
    //                     if (Map.find(strTemp) == Map.end()) {
    //                         Map[strTemp] = 1;
    //                     } else {
    //                         ++Map[strTemp];
    //                     }
    //                     if (Map[strTemp] > max) {
    //                         strMax = strTemp;
    //                         max = Map[strMax];
    //                     }
    //                 }
    //             }
    //             j = i + 1;
    //         }
    //     }
    //     return strMax;
    // }

    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_map<string, uint16_t> Map;
        auto i(paragraph.begin()), j(paragraph.begin());
        string strMax, strTemp;
        for (uint16_t max = 0; i <= paragraph.end(); ++i) {
            if (i == paragraph.end() || isSynbol(*i)) {
                if (i != j) { // Not adjacent symbols
                    strTemp = paragraph.substr(j - paragraph.begin(), i - j);
                    toLower(strTemp);
                    if (isBanned(strTemp, banned)) {
                        if (Map.find(strTemp) == Map.end()) {
                            Map[strTemp] = 1;
                        } else {
                            ++Map[strTemp];
                        }
                        if (Map[strTemp] > max) {
                            strMax = strTemp;
                            max = Map[strMax];
                        }
                    }
                }
                j = i + 1;
            }
        }
        return strMax;
    }
};
// @lc code=end
int main() {
    Solution s;
    string paragraph = "Bob hit a ball, the hit BALL flew far after it was hit.";
    vector<string> banned = {"hit"};
    cout << s.mostCommonWord(paragraph, banned) << '\n';
    return 0;
}
