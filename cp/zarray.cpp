/*
 * g++ -std=c++0x -O2 -Wall
 * zarray
 */

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

const int MAXN=1000001;
string s;
int z[MAXN];

int main() {
    cin.sync_with_stdio(false);

    cin >> s;
    int ns = s.size();
    memset(z, 0, sizeof z);
    int b=1, e=1;
    z[0] = ns;
    for (int i=1; i<ns; i++) {
        if (i >= e) {
            b = i;
            e = i;
            while(s[e] == s[e-b]) {
                z[i]++;
                e++;
            }
            continue;
        }
        int same = z[i-b];
        if (same > e-b) {
            z[i] = same;
            int j = e;
            while(s[j] == s[j-b]) {
                cout << j << "," << j-b << endl;
                z[i]++;
                j++;
            }
            b = i; e = j;
        }
        else {
            z[i] = same;
        }
    }
    int mx = 0;
    for (int i=1; i<ns; i++) {
        if(z[i] > mx) {
            mx = z[i];
        }
        cout << z[i] << endl;
    }
    cout << mx << endl;
}
