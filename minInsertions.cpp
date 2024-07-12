#include <string>
using namespace std;

class Solution {
public:
    int minInsertions(string s) {
        int count = 0;  // to count the number of insertions needed
        int balance = 0;  // to keep track of the balance of parentheses

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                balance += 2;  // each '(' expects two ')'
                if (balance % 2 == 1) {  // if balance is odd
                    count++;  // we need one more ')'
                    balance--;  // decrease the balance
                }
            } else {
                balance--;  // for each ')', decrease the balance
                if (balance == -1) {  // if balance goes negative
                    count++;  // we need one more '('
                    balance = 1;  // reset balance to 1 (one '(' expecting one ')')
                }
            }
        }

        return count + balance;  // add remaining balance to count
    }
};
