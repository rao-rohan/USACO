//
//  main.cpp
//  Recursion 1
//
//  Created by Rohan Rao on 7/16/17.
//  Copyright © 2017 Rohan Rao. All rights reserved.
//

#include <iostream>
#define sp << " "
using namespace std;
int n = 5;
int counter = 0;
void takeInp(){
    cin >> n;
}
void recurse(int x){
    if(x == 0){
        return;
    }
    
    for(int i = 0; i < x; i++){
        if(counter < 9){
        
        counter++;
        }
        else{
            counter = 1;
            
        }
        cout << counter sp;
        
    }
    cout << endl;
    recurse(--x);
    
}
int main(int argc, const char * argv[]) {
    takeInp();
    recurse(n);
    
    return 0;
}
