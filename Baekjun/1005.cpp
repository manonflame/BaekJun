//
//  1005.cpp
//  Baekjun
//
//  Created by 민경준 on 2017. 12. 14..
//  Copyright © 2017년 민경준. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int DFS(int purpose, vector<int> time, int n, vector<int> &cache, vector< vector<bool> > &cond){
    int max = 0;
    int res = 0;
    int answer;
    
    if(cache[purpose] != 0){
        return cache[purpose];
    }
    
    for(int i = 1; i <= n; i++){
        if(cond[i][purpose] == true){
            res = DFS(i, time, n, cache, cond);
            if(max < res){
                max = res;
            }
        }
    }
    
    answer = time[purpose] + max;
    if(cache[purpose] < answer){
        cache[purpose] = answer;
    }
    
    return answer;
}


int main(){
    
    int testcase;
    cin >> testcase;
    
    for (int i = 0 ; i < testcase; i++){
        
        int n;
        int k;
        
        cin >> n;
        cin >> k;
        
        //건물당 만드는 시간
        vector<int> time(n+1);
        for(int j = 1 ; j <= n; j++){
            cin >> time[j];
        }
        
        vector<int> cache(n+1, 0);
        vector< bool> inner(n+1, false);
        vector< vector<bool> >cond(n+1, inner);

        //선행 건물
        for(int j = 0; j < k ; j++){
            int pre;
            int post;
            
            cin >> pre;
            cin >> post;
            
            cond[pre][post] = true;
        }

        int purpose;
        cin >> purpose;
        cout << DFS(purpose, time, n, cache, cond)<<endl;

    }
    

    return 0;
}
