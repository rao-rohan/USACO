//
//  main.cpp
//  Coding Bat Recursion
//
//  Created by Rohan Rao on 7/16/17.
//  Copyright © 2017 Rohan Rao. All rights reserved.
//

#include <iostream>
#include <string>
#define as << "*"
#define ll long long
using namespace std;
string n;

void recurse(string x){
    ll cnt = x.length();
    if(ll == 0){
        return;
    }
    for(int i = 0; i < cnt){
        recurse(x)
    }
    
}
int main(int argc, const char * argv[]) {
    
    cin >> n;
    
    recurse(n);
    
    return 0;
}
