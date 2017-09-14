//
//  main.cpp
//  Block Game
//
//  Created by Rohan Rao on 7/26/17.
//  Copyright © 2017 Rohan Rao. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n;
/*
string inp[100];
int alph[26];

int main(int argc, const char * argv[]) {
    freopen ("blocks.in","r",stdin);
    freopen ("blocks.out","w",stdout);
    cin >> n;
    
    for(int i = 0; i < n*2; i++){
        cin >> inp[i];
    }
    int z = n*2;
    for(int i = 0; i < z+1; i++){
        for(int j = 0; j < z + 1; j++){
            if(inp[i][j] == 'a'){
                int x = alph[0];
                alph[0] = x + 1;
            }
            if(inp[i][j] == 'b'){
                int x = alph[1];
                alph[1] = x + 1;
            }
            if(inp[i][j] == 'c'){
                int x = alph[2];
                alph[2] = x + 1;
            }
            if(inp[i][j] == 'd'){
                int x = alph[3];
                alph[3] = x + 1;
            }
            if(inp[i][j] == 'e'){
                int x = alph[4];
                alph[4] = x + 1;
            }
            if(inp[i][j] == 'f'){
                int x = alph[5];
                alph[5] = x + 1;
            }
            if(inp[i][j] == 'g'){
                int x = alph[6];
                alph[6] = x + 1;
            }
            if(inp[i][j] == 'h'){
                int x = alph[7];
                alph[7] = x + 1;
            }
            if(inp[i][j] == 'i'){
                int x = alph[8];
                alph[8] = x + 1;
            }
            if(inp[i][j] == 'j'){
                int x = alph[9];
                alph[9] = x + 1;
            }
            if(inp[i][j] == 'k'){
                int x = alph[10];
                alph[10] = x + 1;
            }
            if(inp[i][j] == 'l'){
                int x = alph[11];
                alph[11] = x + 1;
            }
            if(inp[i][j] == 'm'){
                int x = alph[12];
                alph[12] = x + 1;
            }
            if(inp[i][j] == 'n'){
                int x = alph[13];
                alph[13] = x + 1;
            }
            if(inp[i][j] == 'o'){
                int x = alph[14];
                alph[14] = x + 1;
            }
            if(inp[i][j] == 'p'){
                int x = alph[15];
                alph[15] = x + 1;
            }
            if(inp[i][j] == 'q'){
                int x = alph[16];
                alph[16] = x + 1;
            }
            if(inp[i][j] == 'r'){
                int x = alph[17];
                alph[17] = x + 1;
            }
            if(inp[i][j] == 's'){
                int x = alph[18];
                alph[18] = x + 1;
            }
            if(inp[i][j] == 't'){
                int x = alph[19];
                alph[19] = x + 1;
            }
            if(inp[i][j] == 'u'){
                int x = alph[20];
                alph[20] = x + 1;
            }
            if(inp[i][j] == 'v'){
                int x = alph[21];
                alph[21] = x + 1;
            }
            if(inp[i][j] == 'w'){
                int x = alph[22];
                alph[22] = x + 1;
            }
            if(inp[i][j] == 'x'){
                int x = alph[23];
                alph[23] = x + 1;
            }
            if(inp[i][j] == 'y'){
                int x = alph[24];
                alph[24] = x + 1;
            }
            if(inp[i][j] == 'z'){
                int x = alph[25];
                alph[25] = x + 1;
            }
            
        }
    }
    for(int i = 0; i < 26; i++){
        cout << alph[i] << endl;
    }
    return 0;
}
*/
int getFrequency(string s) {
    int blocksNeeded = new int[26];
    for(int i = 0; i < s.length(); i++) {
        int index = s.charAt(i) - 'a';
        blocksNeeded[index]++;
    }
    return blocksNeeded;
}

}

int main(){
        int blocksNeeded[26];
        
        // read in the number of blocks
            cin >> n;
    
        for(int i = 0; i < n; i++) {
            // read in each pair of words
            
            string firstWord;
            string secondWord;
            
            cin >> firstWord >> secondWord;
            // get the frequency counts
            vector<int> firstFrequency;
            vector<int> secondFrequency;
            firstFrequency.push_back(getFrequency(firstWord));
            firstFrequency.push_back(getFrequency(secondWord));
            
            // update the number of blocks needed
            for(int j = 0; j < 26; j++) {
                if(firstFrequency[j] > secondFrequency[j]) {
                    blocksNeeded[j] += firstFrequency[j];
                }
                else {
                    blocksNeeded[j] += secondFrequency[j];
                }
            }
        }
        
        // print the answer
        for(int i = 0; i < 26; i++) {
            cout << blocksNeeded[i];
        }
        
}

