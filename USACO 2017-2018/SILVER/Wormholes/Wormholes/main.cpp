
#include <iostream>
#include <vector>
using namespace std;
int n;

vector<pair<int,int> > wormholes;
int main(int argc, const char * argv[]) {
    //freopen ("wormhole.int","r",stdin);
    //freopen ("wormhole.out","w",stdout);
    cin >> n;
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        wormholes.push_back(make_pair(x, y));
    }
    int cnt = 0;
    int cnt2 = n;
    for(int i = 0; i < cnt2;i++){
        pair<int,int> temp = wormholes[i];
        for(int j = 0;j < cnt2 ;j++){
            if(j == i) continue;
            
            if(wormholes[j].first - 1 == temp.first && wormholes[j].second-1 != temp.second  ){
                cnt++;
                cnt2--;
                wormholes.erase(wormholes.begin() + i-1);
                wormholes.erase(wormholes.begin() + j-1);
            }
            else if(wormholes[j].first + 1 == temp.first && wormholes[j].second+1 != temp.second){
                cnt++;
                cnt2--;
                wormholes.erase(wormholes.begin() + i-1);
                wormholes.erase(wormholes.begin() + j-1);
                
                
            }
            else if(wormholes[j].second+1 == temp.second && wormholes[j].first +1 != temp.first){
                cnt2--;
                cnt++;
                wormholes.erase(wormholes.begin() + i-1);
                wormholes.erase(wormholes.begin() + j-1);
                
            }
            
            
            else if(wormholes[j].second-1 == temp.second && wormholes[j].first - 1 != temp.first){
                cnt++;
                cnt2--;
                wormholes.erase(wormholes.begin() + i-1);
                wormholes.erase(wormholes.begin() + j-1);
                
            }
            
        }
    }
    
    cout << cnt << endl;
    return 0;
}
