// Que Link: https://leetcode.com/contest/weekly-contest-306/problems/largest-local-values-in-a-matrix/

/*
Steps:

1. Creating answer variable to store the result
2. Create a function "getMax()" to find max element from the given 3x3 matrix
3. Loop through the grid and find max for each 3x3 matrix using "getMax"

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    //Function to find max element from the given 3x3 matrix
    int getMax(vector<vector<int>>& grid, int l, int r){
        int ma=0;
        for(int i=l;i<l+3;i++){
            for(int j=r;j<r+3;j++){
                ma=max(ma,grid[i][j]);
            }
        }
        return ma;
    }
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n=grid.size();

        //Creating answer variable to store the result
        vector<vector<int>> ans(n-2,vector<int>(n-2));
        
        //Finding max for each 3x3 matrix
        for(int i=0;i<n-2;i++){
            for(int j=0;j<n-2;j++){
                ans[i][j]=getMax(grid,i,j);
            }
        }
        
        return ans;
    }
};

//driver code
int main()
{
    Solution obj;

    vector<vector<int>> grid={{9,9,8,1},{5,6,2,6},{8,2,6,4},{6,2,2,2}};

    vector<vector<int>> ans=obj.largestLocal(grid);
    //printing answer
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[0].size();j++){
            cout<< ans[i][j]<<" ";
        }
        cout<<endl;
    }
}