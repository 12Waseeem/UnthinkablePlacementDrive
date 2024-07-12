#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        int m = words1.size();
        int n = words2.size();
        vector<int> alphabets(26, 0);

        // Calculate the maximum frequency for each letter in all words of words2
        for(int i = 0; i < n; i++) {
            vector<int> temp(26, 0);
            for(int j = 0; j < words2[i].length(); j++) {
                temp[words2[i][j] - 'a']++;
            }
            for(int j = 0; j < 26; j++) {
                alphabets[j] = max(alphabets[j], temp[j]);
            }
        }

        // Debug: print the required max frequencies
        cout << "Max frequencies required: ";
        for(int j = 0; j < 26; j++) {
            if (alphabets[j] > 0) {
                cout << char('a' + j) << ":" << alphabets[j] << " ";
            }
        }
        cout << endl;

        vector<string> ans;

        // Check each word in words1
        for(int i = 0; i < m; i++) {
            vector<int> freq(26, 0);
            for(int j = 0; j < words1[i].length(); j++) {
                freq[words1[i][j] - 'a']++;
            }

            bool valid = true;
            for(int j = 0; j < 26; j++) {
                if (freq[j] < alphabets[j]) {
                    valid = false;
                    break;
                }
            }

            if (valid) {
                ans.push_back(words1[i]);
            }
        }

        return ans;
    }
};
