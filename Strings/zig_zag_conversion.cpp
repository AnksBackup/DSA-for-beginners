/*

6. ZigZag Conversion

The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: 
(you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);
 

Example 1:

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string convert(string s, int r) {
        if (r == 1)
            return s;
        
        int n = s.length();
        int c = n;
        vector<vector<char>> arr(r, vector<char>(c, '0'));
        
        int i = 0;
        int j = 0;
        int k = 0;
        
        while (k < n) {
            if (i != (r - 1)) {
                while (k < n && i < (r - 1)) {
                    arr[i][j] = s[k];
                    k++;
                    i++;
                }
            }
            else {
                while (k < n && i > 0) {
                    arr[i][j] = s[k];
                    k++;
                    i--;
                    j++;
                }
            }
        }
        
        string result;
        
        for (int l = 0; l < r; l++) {
            for (int m = 0; m < c; m++) {
                if (arr[l][m] != '0') {
                    result += arr[l][m];
                }
            }
        }
        
        return result;
    }
};