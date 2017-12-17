#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int n, a[11][11], b[11][11], res;
char in[11][11];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int chk(int x, int y) {
    return 0 <= x&&x < n && 0 <= y&&y < n;
}

//불을 끔
void swp(int x, int y) {
    b[x][y] ^= 1;
    for (int i = 0; i < 4; i++) {
        int cx = x + dx[i];
        int cy = y + dy[i];
        //범위 검사
        if (!chk(cx, cy))continue;
        b[cx][cy] ^= 1;
    }
}
int main() {
    
    cout << ( 1<< 1) << endl;
    cout << ( 1<< 2) << endl;
    cout << ( 1<< 10) << endl;
    
    res = 1e9, n = 10;
    //입력받음
    for (int i = 0; i < n; i++) {
        scanf("%s", &in[i]);
    }
    
    //받은 입력으로 보드 처리
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            if (in[i][j] == 'O')a[i][j] = 1;
    }
    
    //1024번 반복
    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++)
                b[j][k] = a[j][k];
        }
        int cnt = 0;
        
        //1번,2번,4번,8번,16번...1024번 총 10번에 
        for (int j = 0; j < n; j++) {
            if ((1 << j)&i) {
                cnt++;
                swp(0, j);
            }
        }
        //하나씩 꺼본다.
        for (int j = 1; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (b[j - 1][k]) {
                    cnt++;
                    swp(j, k);
                }
            }
        }
        
        //다 꺼졌는지 검사 구간
        int f = 0;
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++)
                f += b[j][k];
        }
        if (!f)
            res = min(res, cnt);
    }
    printf("%d\n", res == 1e9 ? -1 : res);
    return 0;
}



