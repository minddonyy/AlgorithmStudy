using namespace std;
#include <iostream>
#include <vector>
 
int num, questions;
int parents[1000001];
int diffs[1000001];
int ranks[1000001];
int a, b, diff;
int getParent(int a) {
    if (parents[a] == a) return a;
    int p = parents[a];
    parents[a] = getParent(p);
    diffs[a] += diffs[p];
     
    return parents[a];
}
 
void joins(int a, int b, int diff) {
    int pa = getParent(a);
    int pb = getParent(b);
    if (pa == pb) {
        return;
    }
    if (ranks[pa] < ranks[pb]) {
        parents[pa] = pb;
        diffs[pa] = diffs[b] - diffs[a] + diff;
    }
    else {
        parents[pb] = pa;
        diffs[pb] = diffs[a] - diffs[b] - diff;
        if (ranks[pb] == ranks[pa]) {
            ranks[pa]++;
        }
    }
     
}
 
void solve() {
     
    cin >> num >> questions;
    char cmd;
    for (int i = 0; i <= num; i++) {
        parents[i] = i;
        diffs[i] = 0;
        ranks[i] = 0;
    }
 
    for (int i = 0; i < questions; i++) {
        cin >> cmd;
        if (cmd == '!') {
             
            cin >> a >> b >> diff;
            joins(a, b, diff);
        }
        else {
 
            cin >> a >> b;
            if (getParent(a) != getParent(b)) {
                cout << "UNKNOWN ";
            }
            else {
                cout << diffs[a] - diffs[b] << ' ';
            }
 
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T; cin >> T;
    for (int tc = 1; tc <= T; ++tc) {
        cout << '#' << tc << ' ';
        solve();
        cout << '\n';
    }
    return 0;
}