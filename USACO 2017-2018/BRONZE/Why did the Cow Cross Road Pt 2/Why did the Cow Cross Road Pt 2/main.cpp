//
//  main.cpp
//  Why did the Cow Cross Road Pt 2
//
//  Created by Rohan Rao on 7/30/17.
//  Copyright © 2017 Rohan Rao. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

char inp[52];
vector<pair<char ,char> > list;
int main(int argc, const char * argv[]) {
    freopen ("circlecross.in","r",stdin);
    freopen ("circlecross.out","w",stdout);
    for(int i = 0; i < 52; i++){
        cin >> inp[i];
    }
    char temp = inp[0];
    for(int i = 1; i < 52; i++){
        if(i%2 != 0 && temp != inp[i]){
            list.push_back(make_pair(temp, inp[i]));
        }
        temp = inp[i];
    }
    int out = 0;
    for(int i = 0; i < list.size(); i++){
        for(int j = 0; j < list.size(); j++){
            if(list[i] == list[j]){
                list.erase(list.begin() + i);
                list.erase(list.begin() + j);
                out++;
                
            }
                
        }
    }
  
    cout << out;
    return 0;
}
