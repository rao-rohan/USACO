//
//  main.cpp
//  Angry Cows Bronze
//
//  Created by Rohan Rao on 7/26/17.
//  Copyright © 2017 Rohan Rao. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;

vector<pair <int, int>> bales;
int getExplosionIndex(int location[n], int startIndex, bool goLeft) {
    int lastExplosionIndex = startIndex;
    int currentRadius = 1;
    // if the last hay bale that explodes is not either the left most haybale or the right hay bale, continue simulating explosions.
    while(lastExplosionIndex > 0 && lastExplosionIndex < n-1) {
        
        // lastExplosionIndex stores the index of the hay bale that we are currently simulating an explosion for
        int direction = 0;
        
        // figure out which direction to inspect hay bales
        if(goLeft) {
            direction = -1;
        }
        else {
            direction = 1;
        }
        
        /*
         * check if the next closest hay bale is within the range of the explosion
         * the next hay bale to check is at index (nextIndex + direction)
         * to avoid an index out of bounds exception on the array, we must first check that it is betwen 0 and location.length-1.
         * After that, we check if the distance between the two points is less than or equal to the explosion radius.
         */
        int nextIndex = lastExplosionIndex;
        while(nextIndex + direction >= 0 && nextIndex + direction < n && abs(location[nextIndex + direction] - location[lastExplosionIndex]) <= currentRadius) {
            nextIndex += direction;
        }
        
        /*
         * At the end of the while loop, "nextIndex" stores the farthest hay bale that exploded due to the current one exploding.
         * If no other hay bale explodes because of the current explosion, we break out of the while loop
         */
        
        if(nextIndex == lastExplosionIndex) {
            break;
        }
        
        /*
         * Otherwise, we now have a new hay bale to simulate an explosion for.
         */
        
        lastExplosionIndex = nextIndex;
        currentRadius++;
    }
    return lastExplosionIndex;
}

int main() {
    // initialize file I/O
    
    // read in N
    int n;
    cin >> n;
    // read in the locations into an array
    int locations[n];
    for(int i = 0; i < n; i++) {
        cin >> locations[i];
    }
    
    // sort the locations for convenience
    sort(locations , locations + n);
    
    int answer = 1;
    int leftMostExplosion;
    int rightMostExplosion;
    int numExploded;
    // loop over every possible hay bale, simulating the explosion starting from that hay bale
    for(int start = 0; start < n; start++) {
        // figure out the farthest hay bale to the left that explodes
         leftMostExplosion = getExplosionIndex(locations, start, true);
        
        // figure out the farthest hay bale to the right that explodes
         rightMostExplosion = getExplosionIndex(locations, start, false);
        
        // count the number of hay bales that explode
         numExploded = rightMostExplosion - leftMostExplosion + 1;
        
        // if the number that explodes, and update our answer if we explode more hay bales
        answer = max(answer, numExploded);
    }
    
    // print the answer
    cout << answer << endl;
}

