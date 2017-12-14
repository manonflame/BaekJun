//
//  FA.cpp
//  Baekjun
//
//  Created by 민경준 on 2017. 12. 15..
//  Copyright © 2017년 민경준. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int F(string input){
    int ret;
    int first = input[0] - '0';
    ret = first * input.length();
    return ret;
}

int main(){
    
    string str;
    
    cin >> str;
    
    
    bool isFA = false;
    
    for(int i = 0 ; i < 1000; i++){
        int input = stoi(str);
        int result = F(str);
        
        if(input == result){
            i = 1000;
            isFA = true;
        }
        else{
            str = to_string(result);
        }
        
    }
    
    if (isFA) {
        cout << "FA" << endl;
    }
    else{
        cout << "NFA" << endl;
    }
    
    return 0;
}
