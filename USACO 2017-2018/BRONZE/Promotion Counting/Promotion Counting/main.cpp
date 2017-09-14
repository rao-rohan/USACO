//
//  main.cpp
//  Promotion Counting
//
//  Created by Rohan Rao on 7/24/17.
//  Copyright © 2017 Rohan Rao. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    freopen ("promote.in","r",stdin);
    freopen ("promote.out","w",stdout);
    int bronzePrev, bronzeAft, silverPrev, silverAft, goldPrev, goldAft, platPrev , platAft;
    
    
    cin >> bronzePrev >> bronzeAft >> silverPrev >> silverAft >> goldPrev >> goldAft >> platPrev >> platAft;
    
    int goldToPlatinum = platAft - platPrev;
    int silverToGold = goldAft - goldPrev + platAft - platPrev;
    int bronzeToSilver = silverAft - silverPrev + goldAft - goldPrev + platAft - platPrev;
    
    cout << bronzeToSilver << endl;
    
    cout << silverToGold << endl;
    
    cout << goldToPlatinum << endl;
    
    return 0;
}
