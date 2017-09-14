//
//  main.cpp
//  Why Did the Cow Cross the Road Part 1
//
//  Created by Rohan Rao on 7/24/17.
//  Copyright © 2017 Rohan Rao. All rights reserved.
//
/*
#include <iostream>
#include <vector>
using namespace std;

bool comp(const pair<int,int> &a,
          const pair<int,int> &b)
{
    return (a.second > b.second);
}


bool usedChick[20000];

bool usedCow[20000];


int main(int argc, const char * argv[]) {
    
    int c , m;
    
    cin >> c >> m;
    
    /*
     vector<int> chickTimes;
    
    vector<pair<int,int> > cowTimes;
    
    int cnt = 0;
    int out = 0;
    for(int i = 0; i < c; i++){
        int z;
        cin >> z;
        chickTimes.push_back(z);
    }
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x  >> y;
        cowTimes.push_back(make_pair(x, y));
    }
    sort(chickTimes.begin(), chickTimes.end() );
    reverse(chickTimes.begin(), chickTimes.end() );
    /*
     for(int i = 0; i < c; i++){
     cout << chickTimes[i];
     }
     */
  //  sort(cowTimes.begin(), cowTimes.end(), comp);
    /*
     for(int i = 0; i < m; i++){
     cout << cowTimes[i].first << cowTimes[i].second;
     }
     */
    // bool cont  = true;
    // int i = 0;
    /*
     while(cont){
     if(i ==  c - 1){
     break;
     }
     if(chickTimes[i] >= cowTimes[cnt].first && chickTimes[cnt] <= cowTimes[cnt].second){
     cout << chickTimes[i] << endl;
     
     cout << cowTimes[cnt].first << cowTimes[cnt].second << endl;
     
     out++;
     cnt++;
     i++;
     }
     else{
     i++;
     }
     if(cnt == m - 1){
     cnt = 0;
     }
     }
     */
    /*
    for(int i = 0; i < c; i++){
        for(int j = 0; j < m; j++){
            if(chickTimes[i] >= cowTimes[j].first && chickTimes[i] <= cowTimes[j].second && !usedChick[i] && !usedCow[j] ){
                cnt++;
                
                usedCow[j] = true;
                usedChick[i] = true;
                
            }
        }
    }
    cout << cnt << endl;
    */
 /*
    return 0;
    
}

// cout << out << endl;
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

typedef pair<int,int> pii;

multiset<int> chickens;
vector<pii> cows;
int c, n;

int main(void)
{
    ifstream fin("helpcross.in");
    ofstream fout("helpcross.out");
    
    fin >> c >> n;
    int x, y, total=0;
    for (int i=0; i<c; i++) { fin >> x; chickens.insert(x); }
    for (int i=0; i<n; i++) { fin >> x >> y; cows.push_back(pii(y,x)); }
    sort (cows.begin(), cows.end());
    for (int j=0; j<n; j++) {
        auto which_chicken = chickens.lower_bound(cows[j].second);
        if (which_chicken != chickens.end() && *which_chicken <= cows[j].first) {
            total++;
            chickens.erase(which_chicken);
        }
    } 
    fout << total << "\n";
    return 0;
}



