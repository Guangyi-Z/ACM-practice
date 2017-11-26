/*
 * g++ -std=c++0x -O2 -Wall
 * https://open.kattis.com/contests/nwerc17open/problems/highscore2
 */

#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

int n;
long long a[4];

int main() {
    cin >> n;
    while (n--) {
        for (int i = 0; i < 4; i++) {
            cin >> a[i];
        }
        sort(a, a+3);

        long long x = a[0];
        long long y = a[1];
        long long z = a[2];
        long long h = a[3];
        long long mx = x*x + y*y + (z+h)*(z+h) + 7*x;
        if (h < 20) {
            for (int i=0; i<=h; i++) {
                for (int j=0; j<=h-i; j++) {
                    long long s = (x+i)*(x+i) + (y+j)*(y+j) + (z+h-i-j)*(z+h-i-j) + 7*(min(min(x+i,y+j),z+h-i-j));
                    mx = max(s, mx);
                }
            }
        }
        /*
        if (y - x <= h) {
            h -= y-x;
            long long s = y*y + y*y + (z+h)*(z+h) + 7*y;
            mx = max(s, mx);
        } else {
            x += h;
            long long s = x*x + y*y + z*z + 7*x;
            mx = max(s, mx);
        }
        */
        cout << mx << endl;
    }
    return 0;
}
