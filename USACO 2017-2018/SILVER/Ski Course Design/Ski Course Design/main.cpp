//
//  main.cpp
//  Ski Course Design
//
//  Created by Rohan Rao on 8/15/17.
//  Copyright © 2017 Rohan Rao. All rights reserved.
//


#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int sq(int x){
    int y = x * x;
    
    return y;
}
int n;


int main(int argc, const char * argv[]) {
    cin >> n;
    int inp[n];
    
    
    for(int i = 0; i < n; i++){
        
        cin >> inp[i];
    }
    
    sort(inp,inp + n);
    /*
    for(int i = 0; i < n; i++){
        cout << inp[i] << " ";
    }
    cout << endl;
    */
    
    int leastH = inp[0];
    int maxH = inp[n-1];
    if(maxH - leastH > 17){
        int cost;
        int cnt;
        while(maxH - leastH > 17){
            for(int i = 0; ){
                inp[i]
            }
        }
    }
    else{
        cout << 0;
    }
    return 0;
}
