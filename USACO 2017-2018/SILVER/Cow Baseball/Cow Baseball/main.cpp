//
//  main.cpp
//  Cow Baseball
//
//  Created by Rohan Rao on 8/2/17.
//  Copyright © 2017 Rohan Rao. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;
int n;

int main(int argc, const char * argv[]) {
    freopen ("baseball.in","r",stdin);
    freopen ("baseball.out","w",stdout);
    cin >> n;
    int cows[n];
    
    for(int i = 0; i < n;i++){
        cin >> cows[i];
    }
    
    sort(cows, cows + n);
    int cnt = 0;
    int out = 0;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            for(int k = j + 1; k < n; k++){
                int x = cows[j] - cows[i];
                int y = cows[k] - cows[j];
                if(y >= x && y <= 2*x){
                   // cout << cows[i] << " " << cows[j] << " " << cows[k] << endl;
                    cnt++;
                }
            
                
            }
        }
    }
    cout << cnt;
    
    
    return 0;
}
