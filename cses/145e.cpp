/*
 * g++ -std=c++0x -O2 -Wall
 * https://cses.fi/145/task/E/
 * prob, power
 */

#include<iostream>
#include<string>
#include<cstring>
using namespace std;


long long power(long long base, long long p, long long m) {
    long long r = 1;
    while(p > 0) {
        r =  r * (p%2==0?1:base) % m;
        base = base * base % m;
        p /= 2;
    }
    return r;
}

int main() {
    long long n,m;
    cin >> n >> m;
    cout << power(3, n-1, m) << endl;
}
