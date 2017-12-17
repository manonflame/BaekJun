//
//  14939.cpp
//  Baekjun
//
//  Created by 민경준 on 2017. 12. 17..
//  Copyright © 2017년 민경준. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;



void toggle(int i, int j, vector< vector<int> > &bulb){
    int is[5] = {i, i, i-1, i, i+1};
    int js[5] = {j, j+1, j, j-1, j};
    
    for(int i = 0; i < 5; i++){
        if(is[i]>=0 && is[i] <= 9 && js[i]>=0 && js[i] <= 9){
            if(bulb[is[i]][js[i]] != 0){
                bulb[is[i]][js[i]] = 1;
            }
            else{
                bulb[is[i]][js[i]] = 0;
            }
        }
    }
}


bool isAllOff(vector<vector<int> > bulb){
    for(int i = 0 ; i < 10; i++){
        for(int j = 0; j < 10; j++){
            if (bulb[i][j] != 0)
                return false;
        }
    }
    return true;
}

int solution(vector<vector<int> > &input, int count){
    int ret = count;
    if(ret == 999999999){
        return 
    }
    
    if(isAllOff(input)){
        return ret;
    }
    
    int min = 987654321;
    for(int i = 0 ; i < 10 ; i ++){
        for(int j = 0 ; j < 10; j++){
            toggle(i, j, input);
            if(isAllOff(input)){
                return ret+1;
            }
            int next = solution(input, count + 1);
            if(min > next){
                min = next;
            }
            toggle(i, j, input);
        }
    }
    
    return ret + min;
}


int main(){
    
    
    vector< vector<int>> bulb;
    for(int i = 0 ; i < 10 ; i ++){
        string input;
        cin >> input;
        for(int j = 0 ; j < 10; j++){
            if(input[j] == '0'){
                bulb[i][j] = 1;
            }
        }
    }
    
    cout << solution(bulb, 0);
    
    return 0;
}
