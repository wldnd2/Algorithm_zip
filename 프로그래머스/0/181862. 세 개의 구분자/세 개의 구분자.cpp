#include <string>
#include <vector>

using namespace std;


vector<string> solution(string myStr) {
    vector<string> answer;
    string S = "";
    
    for(auto i : myStr){
        if(i == 'a' || i == 'b' || i == 'c'){
            if(!S.empty()) answer.push_back(S);
            S.clear();
        }
        else S += i;
    }
    if(!S.empty()) answer.push_back(S);
    
    if(answer.empty()) return {"EMPTY"};
    return answer;
}
