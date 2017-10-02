#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

vector<long long> primefactor(long long n) {
    long long root;
    vector<long long> factors;

    // Print the number of 2s that divide n
    while(n%2 == 0) {
        n /= 2;
        factors.push_back(2);
    }

    // n must be odd at this point. So we can skip 
    // one element (Note i = i +2)
    for(int i=3; i<=sqrt(n); i += 2){
        // While i divides n, print i and divide n
        while(n%i == 0) {
            n /= i;
            factors.push_back(i);
        }
    }

    // This condition is to handle the case when n 
    // is a prime number greater than 2
    if(n > 2)
        factors.push_back(n);
    return factors;
}

long long newN(vector<long long> factors) {
    long long sum = 0;
    for(int i=0; i<factors.size(); i++)
        sum += factors[i];
    return sum;
}

int main() {
    long long n, ctr;
    vector<long long> factors;

    while(cin >> n && n != 4) {
        ctr = 1;

        factors = primefactor(n);
        while(factors.size() != 1) {
            n = newN(factors);
            factors = primefactor(n);
            ctr++;
        }

        cout << n << ' ' << ctr << '\n';
    }
    return 0;
}