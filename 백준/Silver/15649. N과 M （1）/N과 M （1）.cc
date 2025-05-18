#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

unsigned int n, m;
int numList[9] = {0, };
bool visited[9] = {0, };

void init(){
    cin >> n >> m;
}

void solve(int idx){
    if (idx == m){
        for(int i = 0; i < m; i++)
            cout << numList[i] << " ";
        cout << "\n";
        return;
    }
    for(int i = 1; i < n+1; i++){
        if (!visited[i]){
            numList[idx] = i;
            visited[i] = true;
            solve(idx+1);
            visited[i] = false;
        }
    }
}


int main(void){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    init();
    solve(0);
    return 0;
}