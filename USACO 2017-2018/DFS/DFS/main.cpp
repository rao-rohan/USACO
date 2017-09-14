//
//  main.cpp
//  DFS
//
//  Created by Rohan Rao on 7/18/17.
//  Copyright © 2017 Rohan Rao. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
using namespace std;
typedef pair<int, int> pii;
stack <pair<int, int> > s;

int inpArray1[1000];
int inpArray2[1000];
int n = 0;
bool vis[1000];
int out = 0;
void dfs(int curnode, int depth) {
    
   // cout << "Here";
    s.push(make_pair(curnode, depth));
 //   cout << "here2";
    while(!s.empty()){
       
        pii x;
        x = s.top();
        cerr << x.first << x.second << endl;
       // vis[x.first] = true;
        s.pop();
        //cout << x.first << " " << x.second << endl;
        if(x.first == 0){
            continue;
        }
       // cout << "Here3" << endl;
        if (out < x.second) {
            out = x.second;
           // cout << out;
        }
        if(!vis[x.first]){
            //cout << "Here" << endl;
            s.push(make_pair(inpArray1[x.first], x.second +1));
            vis[x.first] = true;
            
        }
        if(!vis[x.first]){
            //cout << "Here1" << endl;
            s.push(make_pair(inpArray2[x.first], x.second +1));
            vis[inpArray1[x.first]] = true;
        }
        
    }
    
    return;
}

int main() {
    cin >> n;
  //  cout << n;
    
    int inp1, inp2, inp3;
    for (int i = 1; i < n; i++) {
        cin >> inp1 >> inp2 >> inp3;
     //   cout << inp1 << inp2 << inp3;
        //   cout << "here1" << endl;
        //inpArray1[inp1] = inp2;
        //inpArray2[inp1] = imnp3;
        
        inpArray1[inp1] = inp2;
        inpArray2[inp1] = inp3;
        
        //cout << i << endl;
    }
        
    
        
        
    
 //   cerr << "dfsing" << endl;
    dfs(1, 1);
    
    cout << out;
    
    
    return 0;
}
