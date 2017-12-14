

#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Solution{
public:
    string input;
    vector<char> operater = {'+', '-', '*', '/', '(', ')'};
    vector<char> operaterStack;
    bool isBeforeOperater = false;
    
    Solution(string inputString){
        input = inputString;
    }
    
    void solve(){
        vector<char> output;
    
        
        for(int i = 0 ; i < input.length(); i++){
            if( i == 0){
                if(isCharacter(input[i])){
                    output.push_back(input[i]);
                }
                else if(input[i] == '('){
                    operaterStack.push_back('(');
                }
                else{
                    cout << "첫 문자 오류"<<endl;
                    return;
                }
            }
            else{
                if(isCharacter(input[i])){
                    isBeforeOperater = false;
                    output.push_back(input[i]);
                    if(operaterStack.size() != 0){
                        char operaterToInput = operaterStack.back();
                        operaterStack.pop_back();
                        if( operaterToInput != '('){
                            output.push_back(operaterToInput);
                        }
                    }
                    else{
                        cout <<i <<" : 연속된 문자 있음"<<endl;
                        return;
                    }
                }
                else if(isOperater(input[i])){
                    if(input[i] == ')'){
                        char operaterToInput = operaterStack.back();
                        operaterStack.pop_back();
                        output.push_back(operaterToInput);
                    }
                    else{
                        if(isBeforeOperater){
                            cout << "연속된 연산자 있음"<<endl;
                            return;
                        }
                        isBeforeOperater = true;
                        operaterStack.push_back(input[i]);
                    }
                    
                }else{
                    cout << "허용된 인풋이 아님"<<endl;
                    return;
                }
            }
        }
        for(int i = 0 ; i < output.size(); i++)
            cout << output[i];
        cout << endl;
        return;
    }
    
    bool isCharacter(char character){
        if(character >= 65 &&  character <= 90){
            return true;
        }
        else{
            return false;
        }
    }
    
    bool isOperater(char charector){
        for(int i = 0 ; i < operater.size(); i++){
            if(charector == operater[i]){
                return true;
            }
        }
        return false;
    }
    
};

int main(){
    string input;
    cin >> input;
    while(input.compare("ABCDE") != 0){
        Solution s1(input);
        s1.solve();
        cin >> input;
    }
    
    return 0;
}
