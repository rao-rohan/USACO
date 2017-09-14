//
//  main.cpp
//  Diamond Collector
//
//  Created by Rohan Rao on 7/30/17.
//  Copyright © 2017 Rohan Rao. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n, k;
int main(int argc, const char * argv[]) {
    freopen ("diamond.in","r",stdin);
    freopen ("diamond.out","w",stdout);
    cin >> n >> k;
    
    int inp[n];
    vector<int> temp2;
    for(int i = 0; i < n; i++){
        cin >> inp[i];
    }
    sort(inp,inp + n);
    
    reverse(inp, inp + n);
    int temp = 0;
    
    int out = 0;
    for(int i = 0; i < n; i++){
        temp = 1;
        int cnt = n;
        int x = inp[i] - k;
        //cout << inp[i] << " " << x << " ";
        for(int j = i+1; j < cnt; j++){
           
            if(inp[j] >= x){
              //  cout << inp[j] << " ";
                temp++;
                
            }
            else if(inp[j] < x){
                break;
            }
            
            
        }
        // cout << endl;
       // cout << temp << endl;
        out = max(out , temp);
        cnt--;
        
    }
    
    cout << out;
    return 0;
}
