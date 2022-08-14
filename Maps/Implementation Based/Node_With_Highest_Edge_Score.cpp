//Que Link: https://leetcode.com/contest/weekly-contest-306/problems/node-with-highest-edge-score/

/*
Steps:

1.Create a map to store the score for each index
2. Iiterate over the array and calculate score for indexes
2. Whenever we get an index with greater score update the answer variable
3. If we get a score equal to current maxScore , check if the index is smaller or not, if its smaller update the answer to this index

*/
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int edgeScore(vector<int>& edges) {
        int n=edges.size();
        
        //Step 1
        map<int,long long> mp;
        int ans=edges[0];
        int maxScore=0;
        
        for(int i=0;i<n;i++){
            //Step 2
            mp[edges[i]]+=i;
            
            //Step 3
            if(mp[edges[i]] > maxScore){
                ans=edges[i];
                maxScore=mp[edges[i]];
            }
            
            //Step 4
            else if(mp[edges[i]] == maxScore and edges[i]<ans){
                ans=edges[i];
            }
        }
        
        return ans;
    }
};

int main(){
    Solution obj;

    vector<int> edges={1,0,0,0,0,7,7,5};
    cout<<obj.edgeScore(edges);

}