//
//  14938.cpp
//  Baekjun
//
//  Created by 민경준 on 2017. 12. 17..
//  Copyright © 2017년 민경준. All rights reserved.
//

#include <iostream>
#include <vector>
//지역의 개수
int n;
//수색 가능 범위
int m;
//길의 개수
int r;

int item[101] = {0};
int load[101][101] = {0};

using namespace std;

int searching(int area, int last, vector<bool> &visited){
    int ret = 0;
    if(visited[area] == false){
        ret += item[area];
        visited[area] = true;
    }
    for(int i = 1; i <= n; i++){
        int areaToi= load[area][i];
        if(last >= areaToi && areaToi != 0){
            ret += searching(i, last - load[area][i], visited);
        }
    }
    return ret;
}


int solution(int l){
    int max = 0;
    
    //1번 - 마지막번까지 순서대로 반복
    for(int i = 1 ; i <= n ; i++){
        vector<bool> visited(n+1, false);
        int cal = searching(i, l, visited);
        if(max < cal){
            max = cal;
        }
    }
    return max;
}

int main(){
    cin >> n;
    cin >> m;
    cin >> r;
    
    //지역별 아이템 개수 입력
    for(int i = 1 ; i <= n; i++){
        cin >> item[i];
    }
    
    
    int l;
    //길의 입력
    for(int i = 0; i < r;i++){
        int a;
        int b;
        
        cin >> a;
        cin >> b;
        cin >> l;
        
        load[a][b] = l;
        load[b][a] = l;
    }
    
    cout << solution(m) << endl;

    return 0;
}
