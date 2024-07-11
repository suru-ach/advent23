#include <bits/stdc++.h>
using namespace  std;

int main() {
    string str;
    int res = 0;
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
        if(cnt) res += (1<<(cnt-1));
    }
    cout << res << endl;
}
