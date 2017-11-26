/*
 * g++ -std=c++0x -O2 -Wall
 * https://open.kattis.com/contests/nwerc17open/problems/bossbattle
 */

#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
    cin.sync_with_stdio(false);

    int n;
    cin >> n;
    if (n < 3)
        cout << 1 << endl;
    else
        cout << n-2 << endl;

    return 0;
}
