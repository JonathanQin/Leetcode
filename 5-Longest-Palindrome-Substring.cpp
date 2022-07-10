#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s){
        int len = s.length();
        int pairs[len][len];
        //precompute equal pairs, n^2 time
        for(int i = 0; i < len; i++){
            for(int j = i; j < len; j++){
                pairs[i][j] = (s[i]==s[j]);
                pairs[j][i] = (s[j]==s[i]);
            }
        }
        //finding palindromes, starting with largest possible
        //n^2 time
        string res = "";
        bool check;
        
        for(int i = len; i > 0; i--){
            if(res != ""){
                cout<<res<<"\n";
                break;
            }
            for(int j = 0; j < len-i+1; j++){
                //j gives the starting point
                check = true;
                for(int k = 0; k < i+1/2; k++){
                    if(pairs[j+k][j+i-k-1] == 0){
                        check = false;
                        break;
                    }
                }
                if(check == true){
                    res = s.substr(j, i);
                    break;
                }
            }
        }
        return res;
    }
};

int main(){
    Solution solution;
    string input = "tennis";
    cout<<solution.longestPalindrome(input)<<"\n";
    return 0;
}