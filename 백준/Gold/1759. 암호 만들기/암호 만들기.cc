#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool is_valid(vector<char> data, vector<bool> visited){
    int check_1 = 0; // a e i o u
    int check_2 = 0; // etc...
    for (size_t i = 0; i < visited.size(); i++){
        if (visited[i]){
            if (data[i] == 'a' || data[i] == 'e' || data[i] == 'i' || data[i] == 'o' || data[i] == 'u') check_1++;
            else check_2 ++;
        }
    }
    if (check_1 >= 1 && check_2 >= 2) return true;
    return false;
}

void backtrack(vector<char> data, vector<bool> visited, int prev_idx, int depth, int target){
    if (depth == target && is_valid(data, visited)){
        for (size_t i = 0; i < visited.size(); i++){
            if (visited[i]) cout << data[i];
        }
        cout << "\n";
        return;
    }
    for (size_t i = prev_idx; i < data.size(); i++){
        if (!visited[i]){
            visited[i] = true;
            backtrack(data, visited, i, depth+1, target);
            visited[i] = false;
        }
    }
}

void solve() {
    int l, c;
    cin >> l >> c;

    vector<char> pw;
    vector<bool> visited(c, false);
    for (int i = 0; i < c; i++) {
        char temp;
        cin >> temp;
        pw.push_back(temp);
    }
    sort(pw.begin(), pw.end());
    backtrack(pw, visited, 0, 0, l);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}