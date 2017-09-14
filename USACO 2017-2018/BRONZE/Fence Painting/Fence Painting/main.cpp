//
//  main.cpp
//  Fence Painting
//
//  Created by Rohan Rao on 7/24/17.
//  Copyright © 2017 Rohan Rao. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;

int a = 0;
int b = 0;
int c = 0;
int d = 0;
int max1 = 0;
int max2 = 0;
int min1 = 0;
int min2 = 0;
int minMain = 0;
int maxMain = 0;


int main(int argc, const char * argv[]) {
 
    freopen ("paint.in","r",stdin);
    freopen ("paint.out","w",stdout);
   
    
    cin >> a >> b >> c >> d;
    /*
    min1 = min(a,b);
    
    min2 = min(c,d);
    
    max1 = max(a,b);
    
    max2 = max(c,d);
    
    int x = 0;
    int y = 0;
    int z = 0;
    
    if(a < b) x = b;
    else x = a;
    
    if(c > d ) y = d;
    else y = c;
    
    
    if((x-y) > 0) {
        z = (x-y);
    }
    
    
    
    minMain = min(min1, min2);
    
    maxMain = max(max1, max2);
    */
    int out = 0;
    
    for(int i = 0; i < 100; i++){
        if(i >= a && i + 1 <= b) out++;
        else if(i >= c && i + 1 <= d) out++;

    }
   
    cout << out << endl;
    
    
    
   
    return 0;
}
