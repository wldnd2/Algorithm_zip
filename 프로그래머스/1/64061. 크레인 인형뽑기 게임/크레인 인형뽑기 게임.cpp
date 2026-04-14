#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    vector<int> basket;
    int height = board.size();
    for (auto pos: moves){
        pos -= 1;
        for (int h = 0; h < height; h++){
            if (!board[h][pos]) continue;
            else{
                if (basket.size() > 0 && basket[basket.size()-1] == board[h][pos]) {
                    basket.pop_back();
                    answer += 2;
                }
                else basket.push_back(board[h][pos]);
                board[h][pos] = 0;
                break;
            }
        }
    }
    return answer;
}