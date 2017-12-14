//
//  main.cpp
//  9012
//
//  Created by 민경준 on 2017. 11. 13..
//  Copyright © 2017년 민경준. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution{
public:
    string input;
    int count = 0;
    
    Solution(string inputString){
        input = inputString;
    }
    
    void solving(){
        
        
        for(int i = 1 ; i < input.length(); i++){
            if(input[i] == '('){
                count++;
            }
            else if(input[i] == ')'){
                count--;
            }
            else{
                cout << "-1" << endl;
                return;
            }
            if(count < 0){
                cout << "NO" << endl;
                return;
            }
        }
        if(count == 0){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
        return;
    }
};

int main(int argc, const char * argv[]) {
    string input;
    cin >> input;
    
    Solution s1(input);
    s1.solving();
    
    return 0;
}
