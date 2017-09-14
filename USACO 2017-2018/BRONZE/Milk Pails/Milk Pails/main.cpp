//
//  main.cpp
//  Milk Pails
//
//  Created by Rohan Rao on 7/26/17.
//  Copyright © 2017 Rohan Rao. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    freopen ("pails.in","r",stdin);
    freopen ("pails.out","w",stdout);
    int x, y ,m;
    
    cin >> x >> y >> m;
    int out = -1;
    int out2 = -1;
    int out3 = -1;
    
    int final = 0;
    int z = 0;
    int z2 = 0;
    int z3 = 0;
    int temp;
    
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= m ; j++ ){
                z = (i*x) + (j*y);
                
                z2 = (i*x);
                
                z3 = (i*y);
                
                
                if(z <= m){
                
                
                out = max(out, z);
               // cout << z << " ";
              //  cout << i << " "  << j << endl;
                }
                if (z2 <= m) {
                    out2 = max(out2, z2);
                }
                
                if(z3 <= m) {
                    out3 = max(out3, z3);
                }
                
                else{
                    continue;
                    
                    
                }
                
            }
            
        }
    
    temp = max(out2, out3);
    final = max(out, temp);
    cout << final;
    return 0;
}
