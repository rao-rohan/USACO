//
//  main.cpp
//  Lights Out
//
//  Created by Rohan Rao on 7/13/17.
//  Copyright © 2017 Rohan Rao. All rights reserved.
//

//
//  main.cpp
//  Template
//
//  Created by Rohan Rao on 7/13/17.
//  Copyright © 2017 Rohan Rao. All rights reserved.
//

/*
 ID: rohanxrao
 LANG: C++
 PROG: template
 */
//above used for usacogate

#include <iostream> //cin/out
#include <fstream>  //fin/fout
#include <algorithm>//sort, next_permutation
#include <functional>// greater: example: sort (array1, array1+n, greater<int>());
#include <cmath>   //pow, round, sqrt, floor, cell(ceiling),  etc.
#include <set>     //set<>
#include <map>     //map<>
#include <queue> //queue, priority_queue
#include <vector>   //vector<>
#include <deque> //deque
#include <stack> //stack
#include <sstream>  //string2int and other conversions
#include <string>
#include <cstring>  //memset
#include <utility>  //make_pair
#include <iomanip>  //setprecision
#include <bitset>   //bitset
#define NDEBUG
#include <cassert> //assert, disabled by NDEBUG

//#include <bits/stdc++.h>  //includes everything, supported in CF, usaco, not POJ
#define DEBUG
#define f first
#define s second
#define pb push_back
#define ll long long
#define mp make_pair
#define endl '\n'
#define sp << ' ' <<
#define INF 2000000000
#define p 1000000007
#define eps 1e-9
#define MAXN 210
// #define bitSize 262144  /*smallest pow of 2 bigger than size of array */
// #define bitSize2 bitSize*2
using namespace std;

typedef pair<int, int> pii;
typedef vector<pii> vii;



int opt[MAXN];
int psum[MAXN];
int canon[MAXN*2][MAXN*2];
vector<int> lparents[MAXN][MAXN];
vector<int> rparents[MAXN][MAXN];

int dp[MAXN][MAXN][MAXN][2];

int main() {
    
    // FILE fin = *fopen("lightsout.in", "r");
    // FILE fout = *fopen("lightsout.out", "w");
    freopen ("lightsout.in","r",stdin);
    freopen ("lightsout.out","w",stdout);
    int N;
    cin >> N;
    
    vector<pair<long long, long long> > A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i].first >> A[i].second;
    }
    
    
    vector<int> S(1, 0);
    for (int i = 0; i < N; i++) {
        int j = (i + 1) % N;
        int k = (i + 2) % N;
        S.push_back(abs(A[i].first - A[j].first) +
                    abs(A[i].second - A[j].second));
        
        if ((A[i].first - A[j].first) * (A[k].second - A[j].second) -
            (A[k].first - A[j].first) * (A[i].second - A[j].second) > 0) {
            S.push_back(-1);
        } else {
            S.push_back(-2);
        }
    }
    S.back() = 0;
    
    for (int i = 0; i < N; i++) {
        psum[i + 1] = opt[i + 1] = opt[i] + S[2 * i + 1];
    }
    opt[N] = 0;
    for (int i = N - 1; i >= 0; i--) {
        opt[i] = min(opt[i], opt[i + 1] + S[2 * i + 1]);
    }
    
    
    for (int ln = 1; ln <= S.size(); ln++) {
        for (int i = 0; i + ln <= S.size(); i++) {
            for (int& j = canon[i][ln]; j < i; j++) {
                
                if (canon[j][ln - 1] == canon[i][ln - 1] &&
                    S[j + ln - 1] == S[i + ln - 1]) {
                    break;
                }
            }
        }
    }
    
    
    for (int i = 0; i < S.size(); i += 2) {
        for (int ln = 3; i + ln <= S.size(); ln += 2) {
            if (i != canon[i][ln]) {
                continue;
            }
            lparents[canon[i + 2][ln - 2] / 2][ln / 2].push_back(i / 2);
            rparents[canon[i][ln - 2] / 2][ln / 2].push_back(i / 2);
        }
    }
    
    int result = 0;
    for (int ln = N; ln >= 1; ln--) {
        for (int i = 0; i + ln <= N + 1; i++) {
            if (canon[2 * i][2 * ln - 1] != 2 * i) {
                
                continue;
            }
            
            int dist_across = psum[i + ln - 1] - psum[i];
            for (int strt = 0; strt < ln; strt++) {
                for (int side = 0; side < 2; side++) {
                    if (i == 0 || i + ln == N + 1) {
                        
                        dp[i][ln][strt][side] = -opt[i + strt];
                        continue;
                    }
                    
                    
                    int lft_cst = -INF;
                    for (int j : lparents[i][ln]) {
                        lft_cst = max(lft_cst, S[2 * j + 1] + dp[j][ln + 1][strt + 1][0]);
                    }
                    
                    int rht_cst = -INF;
                    for (int j : rparents[i][ln]) {
                        rht_cst = max(rht_cst,
                                      S[2 * (j + ln) - 1] + dp[j][ln + 1][strt][1]);
                    }
                    
                    
                    (side ? lft_cst : rht_cst) += dist_across;
                    
                    
                    dp[i][ln][strt][side] = min(lft_cst, rht_cst);
                    
                    if (ln == 1) {
                        result = max(result, dp[i][ln][strt][side]);
                    }
                }
            }
        }
    }
    cout << result << endl;
    
    
    
    
    
    
    return 0;
}
