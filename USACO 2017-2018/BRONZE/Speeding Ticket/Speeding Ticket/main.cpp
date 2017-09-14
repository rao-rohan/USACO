//
//  main.cpp
//  Speeding Ticket
//
//  Created by Rohan Rao on 7/24/17.
//  Copyright © 2017 Rohan Rao. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

vector<pair<int ,int> > rule;

vector<pair<int,int > > bess;

int n;
int m;
int x ,y;
int amount;
int temp;
int main(int argc, const char * argv[]) {
    //freopen ("speeding.in","r",stdin);
    //freopen ("speeding.out","w",stdout);
    cin >> n >> m;
    
    for(int i = 0; i < n;i ++){
        
        cin >> x >> y;
        
        rule.push_back(make_pair(x, y));
    }
    for(int i = 0; i < m;i ++){
        
        cin >> x >> y;
        
        bess.push_back(make_pair(x, y));
    }
    int z = min(n,m);
    int leftOver = 0;;
    int tempLeftOver;
    for(int i = 0; i < z;i++){
        //        if(abs(rule[i].first - bess[i].first != 0)){
        //            tempLeftOver = abs(rule[i].first - bess[i].first);
        //        }
        //        if(rule[i].second - bess[i].second >= 0){
        //            amount++;
        //        }
        amount = max(amount, temp);
        if(rule[i].first - bess[i].first == 0){
            if(bess[i].second - rule[i].second >= 0){
                temp = bess[i].second - rule[i].second;
            }
            
            
        }
        else if(rule[i].first - (bess[i].first + leftOver) > 0){
            leftOver = rule[i].first - bess[i].first + leftOver;
            if(bess[i].second - rule[i].second >= 0){
                temp = bess[i].second - rule[i].second;
            }
        }
        else if((rule[i].first + leftOver) - bess[i].first < 0){
            leftOver = rule[i].first - bess[i].first + leftOver;
            if(bess[i].second - rule[i].second >= 0){
                temp = bess[i].second - rule[i].second;
            }
        }
        
    }
    cout << amount << endl;
    
    return 0;
}
