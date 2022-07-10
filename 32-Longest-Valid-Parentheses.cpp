#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s){
        int len = s.length();
        if(len == 0){
            return 0;
        }
        int res = 0; int counter = 0;
        int arr[len];
        stack<int> leftpos;
        for(int i = 0; i<len; i++){
            if(s[i] == '('){
                leftpos.push(i);
                arr[i] = 0;
            }
            else{
                if(!leftpos.empty()){
                    arr[leftpos.top()] = 1;
                    arr[i] = 1;
                    leftpos.pop();
                }
                else{
                    arr[i] = 0;
                }
            }
        }
        for(int i = 0; i < len; i++){
            if(arr[i] == 1){
                counter +=1 ;
                if(counter%2 == 0){
                    res = res > counter ? res : counter;
                }
            }
            else{
                counter = 0;
            }
        }
        return res;
    }
};

int main(){
    Solution solution;
    string input = "()()()()";
    cout << solution.longestValidParentheses(input);
    return 0;
}