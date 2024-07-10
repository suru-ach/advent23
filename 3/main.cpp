#include <bits/stdc++.h>
using namespace std;

void dfs(int i, int j, vector<string> &arr, vector<string> &vis, int sym = 0) {
    if(i < 0 || j < 0 || i >= arr.size() || j >= arr.size() || vis[i][j] == '#' || arr[i][j] == '.' || (isdigit(arr[i][j]) && !sym)) return;

    vis[i][j] = '#';
    if(!isalpha(arr[i][j])) sym = 1;
    dfs(i+1,j,arr,vis,sym);
    dfs(i-1,j,arr,vis,sym);
    dfs(i,j+1,arr,vis,sym);
    dfs(i,j-1,arr,vis,sym);
    dfs(i+1,j+1,arr,vis,sym);
    dfs(i-1,j-1,arr,vis,sym);
    dfs(i-1,j+1,arr,vis,sym);
    dfs(i+1,j-1,arr,vis,sym);
}

int main() {
    string str;
    vector<string> arr;
    vector<string> vis;
    while(getline(cin, str)) {
        arr.push_back(str);
        vis.push_back(string(str.size(), '.'));
    }

    // . ->not visited
    // # ->visited

    for(int i=0;i<arr.size();i++) {
        for(int j=0;j<arr[0].size();j++) {
            dfs(i, j, arr, vis, 0);
        }
    }

    int res = 0;
    for(int i=0;i<arr.size();i++) {
        int value = 0, digit = 1;
        for(int j=arr[0].size()-1;j>=-1;j--) {
            if(j == -1 || vis[i][j] == '.' || !isdigit(arr[i][j])) {
                //cout << ' ';
                if(value) res+=value;
                value = 0;
                digit = 1;
            }
            if(vis[i][j] == '#' && isdigit(arr[i][j])) {
                //cout << arr[i][j];
                value+=(digit*(arr[i][j]-'0'));
                digit*=10;
            }
        }
        cout << res << endl;
    }

    cout << res << endl;
    for(auto val: arr) {
        //cout << val << endl;
    }
    for(auto val: vis) {
        //cout << val << endl;
    }

}
