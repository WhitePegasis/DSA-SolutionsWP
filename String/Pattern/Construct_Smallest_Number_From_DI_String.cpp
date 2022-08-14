// Problem link: https://leetcode.com/contest/weekly-contest-306/problems/construct-smallest-number-from-di-string/

/*
Steps:

1. Create an "ans" variable to store the result 
2. Store numbers from 1 to n+1 in "ans" (where n= size of pattern string)
3. Check for the group of similar letters , for ex: In the string "IIIIDDD" "IIII" can be termed as one group and "DDD" can be termed as another group
4. If the current group is a "D" group reverse the "ans" for that group index.
*/
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string smallestNumber(string pattern) {
        
        int n=pattern.length();
        
        //Step 1
        string ans="";
        
        //Step 2
        for(int i=0;i<n+1;i++){
            ans+='1'+i;
        }
        
        for(int i=0;i<n;i++){
            
            int start=i;
            //Step 3
            while(i<n and pattern[i]==pattern[i+1]){
                i++;
            }
            
            //Step 4
            if(pattern[start]=='D'){
                reverse(ans.begin()+start, ans.begin()+i+2);
            }
        }

        return ans;
    }
};

//driver code
int main(){
    Solution obj;
    cout<<obj.smallestNumber("IIIDIDDD");
}