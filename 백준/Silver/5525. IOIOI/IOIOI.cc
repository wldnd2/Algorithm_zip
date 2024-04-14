#include <iostream>
#include <string>
using namespace std;

int main(void){
    int n, s_len;
    string s;
    cin >> n >> s_len >> s;
    int count = 0, pattern = 0, idx = 0;
    while(idx < s_len-2){
        if(s[idx] == 'I' && s[idx+1] == 'O' && s[idx+2] == 'I'){
            pattern++;
            if(pattern == n){
                count++;
                pattern--;
            }
            idx++;
        }else{
            pattern = 0;
        }
        idx++;
    }
    cout << count << endl;
}
