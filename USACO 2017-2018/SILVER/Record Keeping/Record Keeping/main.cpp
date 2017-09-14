//
//  main.cpp
//  Record Keeping
//
//  Created by Rohan Rao on 8/2/17.
//  Copyright © 2017 Rohan Rao. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n;

int main(int argc, const char * argv[]) {
    freopen ("records.in","r",stdin);
   freopen ("records.out","w",stdout);
    cin >> n;
    string cows[n][3];
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 3; j++){
            cin >> cows[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 3; j++){
           // cout << cows[i][j] << " ";
        }
       // cout << endl;
    }
    int out = -1;
    int temp = 0;
    
    string tempS[3];
   // cout << "here" << endl;
    for(int i = 0; i < n; i++){
        tempS[0] = cows[i][0];
        tempS[1] = cows[i][1];
        tempS[2] = cows[i][2];
        //cout << tempS[0] << " " << tempS[1] << " " << tempS[2] << " " << endl;
        //cout << "here2" << endl;
        int temp = 1;
        for(int j = i+1; j < n; j++){
           // cout << "here3" << endl;
            int cnt = 0;
            for(int k = 0; k < 3;k++){
                if(tempS[0] == cows[j][k] || tempS[1] == cows[j][k] || tempS[2] == cows[j][k]){
                    cnt++;
                   // cout << cows[j][k] << " ";
                    //cout << cnt<< " ";
                }
                if(cnt == 3){
                    temp++;
                }
                
            }
            
           // cout << endl;
            //cout << temp << endl;
        }
       // cout << temp << endl;
        out = max(out, temp);
    }
    
    
    cout << out << endl;
    return 0;
}
