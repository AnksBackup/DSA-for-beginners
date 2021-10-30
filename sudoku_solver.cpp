// Leetcode 37. Sudoku Solver (https://leetcode.com/problems/sudoku-solver/)

class Solution {
public:
    void solveSudoku(vector<vector<char>>& a) {
        solvesudoku(a);
    }
private:  
    bool solvesudoku(vector<vector<char>>& a)
    {
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(a[i][j]=='.')
                {
                    for(char c='1';c<='9';c++)
                    {
                        if(solve(i,j,c,a))
                        {
                            a[i][j] = c;
                            if(solvesudoku(a))
                            {
                                return true;
                            }
                            a[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
private:
    bool solve(int row,int col,char c,vector<vector<char>>& a)
    {
        for(int i=0;i<9;i++)
        {
            if(a[i][col]==c) return false;
            if(a[row][i]==c) return false;
            if(a[3*(row/3) + (i/3)][3*(col/3) + (i%3)]==c) return false;
        }
        return true;
    }
};
