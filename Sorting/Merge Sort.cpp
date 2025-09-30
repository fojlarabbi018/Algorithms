#include<bits/stdc++.h>
using namespace std;
#define ll long long

// O(n) --- for a complete level (there is total -- log n -- levels)
vector<int> merge(vector<int> l, vector<int> r) {
    int i = 0;
    int j = 0;
    vector<int> res;
    while(i < l.size() && j < r.size()) {
        if(l[i] <= r[j]) {
            res.push_back(l[i]);
            i++;
        }
        else {
            res.push_back(r[j]);
            j++;
        }
    }
    // If one of the pointers doesn't reach the end
    while(i < l.size()) {
        res.push_back(l[i]);
        i++;
    }
    while(j < r.size()) {
        res.push_back(r[j]);
        j++;
    }
    return res;
}
vector<int> v;
int n;
// O(log n)
vector<int> merge_sort(int low, int high) {
    if(low == high) { // When only one element
        vector<int> t;
        t.push_back(v[low]);
        return t;
    }
    int mid = (low + high) / 2;
    vector<int> l = merge_sort(low, mid);
    vector<int> r = merge_sort(mid + 1, high);
    return merge(l, r);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    vector<int> t(n);
    for(int i = 0; i < n; i++) {
        cin >> t[i];
    }
    v = t;
    vector<int> ans = merge_sort(0, n - 1);
    for(int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    return 0;
}



