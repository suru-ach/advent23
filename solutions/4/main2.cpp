#include <bits/stdc++.h>
using namespace  std;

// 1 4  1
// 2 2  2
// 3 2  4 
// 4 1  8
// 5 0  14
// 6 0  1
/*
   1 4   1
   2 2   2
   3 2   4
         8
         6
         1
         
    res <int>(n ,1);
    wins<int>(n);
    for()
  
*/
int main() {
    string str;
    int ans = 0;
    vector<int> res,wins;
    while(getline(cin, str)) {
        stringstream ss{str};
        string dum;
        ss >> dum >> dum;

        string num;
        int next = 0;
        int cnt = 0;
        set<string> st;

        while(ss >> num) {
            if(num == "|") {
                next = 1;
            }

            if(next) {
                if(st.count(num)) cnt++;    
            } else {
                st.insert(num);
            }
        }
        res.push_back(1);
        wins.push_back(cnt);
    }
    int n = res.size();
    for(int i=0;i<n;i++) {
        //cout << res[i] << ' ';
        for(int j=1;j < n && j <= wins[i];j++) {
            res[j+i]+=res[i]; 
        }
        ans += res[i];
    }
    cout << ans << endl;
}
