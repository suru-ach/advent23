#include <bits/stdc++.h>
using namespace std;

vector<vector<vector<long long>>> grid(7);
vector<long long> res;
long long ans;

long long f(long long a, long long b, long long r, long long c) {
    return (b <= c && c <= b+r) ? c+a-b : INT_MIN;
}
 
void func(long long s, long long i) {
    if(i == 7) {
        ans = s;
        return;
    }
    for(auto& v: grid[i]) {
        long long func_val = f(v[0], v[1], v[2], s);
        if(func_val != INT_MIN) {
            func(func_val, i+1);
            return;
        }
    }
    func(s, i+1);
}

int main() {
    vector<long long>seeds;
    string str;
    long long it = -1;

    getline(cin, str);
    string _;
    stringstream ss{str};
    ss >> _;
    long long val;
    while(ss >> val) {
        seeds.push_back(val);
    }
    
    while(getline(cin, str)) {
        if(str == "") continue;
        if(isalpha(str[0])) {
            it++;
        }
        else {
            stringstream ss{str};
            long long a,b,c;
            ss >> a >> b >> c;
            grid[it].push_back({a,b,c});
        }
    }
    unordered_map<long long, long long>dp;
    long long minval = INT_MAX;
    for(int i=0;i<seeds.size();i+=2) {
        for(int j=0;j<seeds[i+1];j++) {
            if(dp.count(seeds[i]+j)) continue;
            func(seeds[i]+j, 0);
            dp[seeds[i]+j] = ans;
            minval = min(minval, ans);
        }
    }
    for(long long seed: seeds) {
        func(seed, 0);
        minval = min(minval, ans);
    }
    cout << minval << endl;
}
