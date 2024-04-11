#include <iostream>

using namespace std;

int main(void) {
    int n;
    cin >> n;
    if (n&1)
        printf("%d is odd", n);
    else
        printf("%d is even", n);
    return 0;
}