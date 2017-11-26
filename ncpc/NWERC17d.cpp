/*
 * g++ -std=c++0x -O2 -Wall
 * https://open.kattis.com/contests/nwerc17open/problems/dunglish
 */

#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
#include<unordered_map>
using namespace std;

const int N = 21;
int c[N];
int inc[N];

int main() {
    cin.sync_with_stdio(false);

    memset(c, 0, sizeof c);
    memset(inc, 0, sizeof inc);

    int n;
    int m;
    string s;

    unordered_map<string,string> mps;
    vector<string> v;

    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> s;
        v.push_back(s);
    }
    cin >> m;
    string d,e,c_;
    for (int i=0; i<m; i++) {
        cin >> d >> e >> c_;
        mps[d] = e;
        for (int i=0; i<n; i++) {
            if (d == v[i]) {
                if (c_ == "correct") c[i]++;
                else inc[i]++;
            }
        }
    }

    long long anscc = 1;
    long long ansc = 1;
    for (int i=0; i<n; i++) {
        anscc *= c[i] + inc[i];
        ansc *= c[i];
    }
    if (anscc == 1) {
        for (int i=0; i<n; i++) {
            cout << mps[v[i]];
            if (i<n-1) cout << " ";
        }
        cout << endl;
        if (ansc == 0)
            cout << "incorrect" << endl;
        else
            cout << "correct" << endl;
    } else {
        cout << ansc << " " << "correct" << endl;
        cout << (anscc-ansc) << " " << "incorrect" << endl;
    }

    return 0;
}
