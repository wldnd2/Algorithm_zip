#include <string>
#include <vector>

using namespace std;

string solution(string rny_string) {
    string answer = "";
    for(char w: rny_string){
        if (w == 'm') answer += "rn";
        else answer += w;
    }
    return answer;
}