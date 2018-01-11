//
//  main.cpp
//  algo
//
//  Created by  test on 2018. 1. 8..
//  Copyright © 2018년 Lee. All rights reserved.
//

#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
int C, n;
vector<vector<int>> board;
int cache[100][100];
int recurs(int y, int x){
    if(y==n-1 && x==n-1) return 1;
    if(cache[y][x]!=-1) return cache[y][x];
    int ret = 0;
    int k = board[y][x];
    if(x+k < n){
        cache[y][x] = recurs(y,x+k);
        ret+=cache[y][x];
    }
    if(y+k < n){
        cache[y][x] = recurs(y+k, x);
        ret+=cache[y][x];
    }
    return ret;
}
int main(int argc, const char * argv[]) {
    scanf("%d", &C);
    for(int k=0;k<C;k++){
        scanf("%d",&n);
        
        for(int i=0;i<n;i++){
            vector<int> e(n);
            board.push_back(e);
        }
        memset(cache, -1, sizeof(cache));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                scanf("%d", &board[i][j]);
            }
        }
        if(recurs(0, 0)>0){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
        
        for(int i=0;i<n;i++){
            board[i].clear();
        }
        board.clear();
        
    }
    return 0;
}
