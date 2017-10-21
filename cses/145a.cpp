/*
 * g++ -std=c++0x -O2 -Wall
 * https://cses.fi/145/task/A/
 * dp, edit distance
 */

#include<iostream>
#include<string>
#include<cstring>
using namespace std;

const int MAXN = 400001;
const int MAXS = 33;
string d[MAXN];
int A[MAXS][MAXS];

int edit(string a, string b) {
    memset(A, 0, sizeof A);
    int na = a.size();
    int nb = b.size();
    A[0][0] = 0;
    for (int i=1; i<=na; i++) A[i][0] = i;
    for (int i=1; i<=nb; i++) A[0][i] = i;
    for (int i=1; i<=na; i++) {
        for (int j=1; j<=nb; j++) {
            A[i][j] = min(A[i-1][j-1]+(a[i-1]==b[j-1]?0:1), min(A[i-1][j], A[i][j-1])+1);
        }
    }
    return A[na][nb];
}

int main() {
    int n,m;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> d[i];
    }
    cin >> m;
    string q;
    for (int i=0; i<m; i++) {
        cin >> q;
        int mn = (1<<31)-1;
        string smn;
        for (int j=0; j<n; j++) {
            int di = edit(d[j], q);
            if (di < mn) {
                mn = di;
                smn = d[j];
            }
        }
        cout << mn << " " << smn << endl;
    }
}
