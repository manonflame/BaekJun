#include <cstdio>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;
int n, m, a[4];
vector<int> vt;
set<vector<int>> st;
vector<int> t;
int func(vector<int> &v, int rem, int flag) {
    if (rem == 0)return rem;
    if (flag == 1) {
        for (int i = 0; i < v.size(); i++) {
            v[i] ^= 1;
            rem--;
        }
    }
    else if (flag == 2) {
        for (int i = 0; i < v.size(); i += 2) {
            v[i] ^= 1;
            rem--;
        }
    }
    else if (flag == 3) {
        for (int i = 1; i < v.size(); i += 2) {
            v[i] ^= 1;
            rem--;
        }
    }
    else {
        for (int i = 0; i < v.size(); i += 3) {
            v[i] ^= 1;
            rem--;
        }
    }
    return rem;
}
int main() {
    //n 층수 , m 초기 시간
    scanf("%d%d", &n, &m);
    //모두 0으로 세팅
    vt.assign(n, 0);
    //각 경우의 수 배열에 입력
    for (int i = 0; i < 4; i++)
        a[i] = i + 1;
    //정답 셋에 현상태 저장
    st.insert(vt);
    
    do {
        int curr = m;
        t.assign(n, 0);
        for (int i = 0; i < 4; i++) {
            //func에 현 상태 버튼, 남은 시간, 플래그를 넣는다. 플래그를 순서대로 넣는다.
            curr = func(t, curr, a[i]);
            if (curr >= 0)
                st.insert(t);
            else
                break;
        }
    //핵심알고리즘이당.
    } while (next_permutation(a, a + 4));
    printf("%d\n", st.size());
    return 0;
}



