//
//  main.cpp
//  Recursion
//
//  Created by Rohan Rao on 7/16/17.
//  Copyright © 2017 Rohan Rao. All rights reserved.
//

#include <iostream>
#define sp << " "
using namespace std;
int x;
int y;
int n;
void recurse(int x , int y){
    if(x == 0) return;
    
    for(int i = 0; i <x; i++){
        cout << y << " ";
        y--;
    }
    y = n;
    cout << endl;
    recurse(x-1,y);
    return;
    
    
}



int main(int argc, const char * argv[]) {
    
    cin >>  x >> n;
    
    recurse(x, n);
    
   
    
    return 0 ;
    
    
}
