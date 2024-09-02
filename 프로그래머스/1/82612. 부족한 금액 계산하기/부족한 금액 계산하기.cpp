using namespace std;

long long solution(int price, int money, int count)
{
    long long acc = 0;
    for(int i = 1; i <= count; i++){
        acc += price*i;
    }
    if (money-acc < 0) return acc-money;
    return 0;
}