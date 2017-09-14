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
//#define s second
#define pb push_back
#define ll long long
#define mp make_pair
#define endl '\n'
#define sp << ' ' <<
#define inf 2000000000
#define p 1000000007
#define eps 1e-9
#define maxn 100010
// #define bitSize 262144  /*smallest pow of 2 bigger than size of array */
// #define bitSize2 bitSize*2
using namespace std;

typedef pair<int, int> pii;
typedef vector<pii> vii;
int col, row;
char grid[50][50];

bool usedH[50][50];
bool usedV[50][50];
bool used[50][50];
bool works, works2;
int outNum;
vii outCords;



int dx[4] = {0, 1, 0 , -1};
int dy[4] = {1, 0, -1,  0};
void dfs(int sc, int sr){
    stack<pii> s;
    
    s.push(mp(sc, sr));
    
    
    while(!s.empty()){
        pii currnode;
        currnode = s.top();
        int nc = currnode.first;
        int nr = currnode.second;
        s.pop();
        cout << nc + 1 sp nr + 1 << endl;
        if(grid[nc][nr] != '#' && nr >= 0 && nc >= 0 && nr < row && nc < col && !used[nc][nr] ){
            
            for(int i = nr+1; i < row; i++){
                if(grid[nc][i] != '#' && i >= 0 && nc >= 0 && i < row && nc < col && !usedV[nc][i]){
                    works = true;
                    
                }
                
                else{
                    works = false;
                    break;
                }
                
            }
            for(int j = nc+1; j < col; j++){
                if(grid[j][nr] != '#' && nr >= 0 && j >= 0 && nr < row && j < col && !usedH[j][nr]){
                    works2 = true;
                    
                }
                
                else{
                    works2 = false;
                    break;
                }
                
            }
            if(works){
                usedV[nc][nr] = true;
                for(int i = nr+1; i < row; i++){
                    if(grid[nc][i] != '#' && i >= 0 && nc >= 0 && i < row && nc < col && !usedV[nc][i]){
                        
                        usedV[nc][i] = true;
                    }
                    
                    else{
                        break;
                    }
                    
                }
            }
            if(works2){
                usedH[nc][nr] = true;
                for(int j = nc+1; j < col; j++){
                    if(grid[j][nr] != '#' && nr >= 0 && j >= 0 && nr < row && j < col && !usedH[j][nr]){
                        usedH[j][nr] = true;
                        
                    }
                    
                    else{
                        works2 = false;
                        break;
                    }
                    
                }

                
            }
            if(works || works2 ){
                used[nr][nc] = true;
                outNum++;
                outCords.push_back(mp(nc, nr));
                
            }
        }
        
        if(nr != row - 1 && nc != col - 1){
            s.push(mp(nc+1, nr));
            s.push(mp(nc, nr + 1));
        }
        /*
         if(nr == row - 1 && nc != col - 1){
         
         s.push(mp(nc, 0));
         s.push(mp(nc+ 1, 0));
         
         }
         if(nr != row - 1 && nc == col - 1){
         
         s.push(mp(0, nr));
         s.push(mp(0, nr+ 1));
         
         }
         */
        if(nr == row - 1 && nc == col  - 1){
            break;
        }
        
    }
    
    
    
    
    
    
    
}

void takeInp(){
    cin >> col >> row;
    
    for(int i = 0; i < col; i++){
        for(int j = 0; j < row; j++)
            cin >> grid[i][j];
    }
    
}
int main(){
    takeInp();
    
    dfs(0,0);
    
    cout << outNum << endl;
    
    for(int i = 0; i < outCords.size(); i++){
        cout << outCords[i].first + 1 sp outCords[i].second + 1 << endl;
    }
    
    return 0;
}


