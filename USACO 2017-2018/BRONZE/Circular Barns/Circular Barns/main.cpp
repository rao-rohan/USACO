//
//  main.cpp
//  Circular Barns
//
//  Created by Rohan Rao on 7/26/17.
//  Copyright © 2017 Rohan Rao. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int n;
int main(){
    
    freopen ("cbarn.in","r",stdin);
    freopen ("cbarn.out","w",stdout);
    cin >> n;
    int cows [n];
    for(int i = 0; i < n; i++) {
        cin  >> cows[i];
    }
    int ans = n * n * 100;
    for(int unlock = 0; unlock < n; unlock++) {
        
        int currentDistance = 0;
        for(int offset = 0; offset < n; offset++) {
            currentDistance += offset * cows[(unlock+offset)%n];
        }
        
        if(currentDistance < ans) {
            ans = currentDistance;
        }
    }
    cout << ans << endl;
}


