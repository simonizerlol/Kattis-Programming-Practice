#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int N;
    cin >> N;
    long X = 0;
    while(N--){
        int P;
        cin >> P;
        X += pow(P/10,P%10); // 212/10 gives 21, 212%10 gives 2
    }
    cout << X;
    return 0;
}