//
//  main.cpp
//  The Cow Signal
//
//  Created by Rohan Rao on 7/28/17.
//  Copyright © 2017 Rohan Rao. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;
int strNum, strLeng, k;
string grid[10];

int main(int argc, const char * argv[]) {
    freopen ("cowsignal.in","r",stdin);
    freopen ("cowsignal.out","w",stdout);
    cin >> strNum >> strLeng >> k;
    
    for(int i = 0; i < strNum; i++){
        cin >> grid[i];
    }
    for(int i = 0; i < strNum; i++){
        vector<char> out;
        int cnt = 1;
        char prevChar = '\0';
        for(int j = 0; j < strLeng * 2; j++ ){
            if(j == 0) prevChar = grid[i][j];
            else if(grid[i][j] == prevChar){
                cnt++;
                prevChar = grid[i][j];
                
            }
            else if (grid[i][j] != prevChar){
                //cout << cnt << endl;
                for(int a = 0; a < cnt * k; a++ ){
                    out.push_back(prevChar);
                }
                prevChar = grid[i][j];
                cnt = 1;
            }
            }
        for(int b = 0; b < k;b++ ){
            for(int c = 0; c< out.size(); c++){
                cout << out[c];
            }
            cout << endl;
        }
        
    }
    return 0;
}
