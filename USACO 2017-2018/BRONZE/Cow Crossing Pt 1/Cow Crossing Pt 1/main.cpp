//
//  main.cpp
//  Cow Crossing Pt 1
//
//  Created by Rohan Rao on 7/24/17.
//  Copyright © 2017 Rohan Rao. All rights reserved.
//

#include <iostream>
using namespace std;

int n;
int main(int argc, const char * argv[]) {
    //freopen ("crossroad.in","r",stdin);
    //freopen ("crossroad.out","w",stdout);
    
    cin >> n;
    
    int lastSeen[11];
    
    // track the number of crossings that are confirmed
    int crossings = 0;
    for(int i = 0; i < n; i++) {
        // read in the data for one observation
        
        int index;
        int current;
        
        cin >> index >> current;
        
        current++;
        
        
        if(lastSeen[index] > 0 && lastSeen[index] != current) {
            crossings++;
        }
        
        // update the last side we have seen the given cow on
        lastSeen[index] = current;
    }
    
    // print the answer
    cout << crossings << endl;
    
    return 0;
}
