#include <bits/stdc++.h>
using namespace std;

#define vec_p vector<pair<int,int>>

/*
 dfs(i, j, mark,Pointx,y)
if(vis(i,j)
 and !isdigit(a[i][j])) return;
x=min(x,i)
y=max(y,i)
vis[i][j] = mark;
dfs(i,j+1);
dfs(i,j-1);

dfsa(i,j) {
   8*dfs(i,j,new Point(i,j)) 
}

for(i,j)
    if arr(i,j) == * 
        dfsa(i,j,true)
        dfsa(i,j,false)
 
 */

struct Node {
    // coords of '*' and its neighbouring numbers
    pair<int, int> point;
    vector<pair<int, pair<int, int>>> points;
    Node(pair<int, int> _point): point{_point} {} 
};

// mark . -> #
// mark # -> .
bool dfs(int i, int j, vector<string> &arr, vector<string> &vis, pair<int, int> &numlen, char mark) {
    if(i < 0 || j < 0 || i >= arr.size() || j >= arr.size() || vis[i][j] == mark || !isdigit(arr[i][j])) return false;
    
    vis[i][j] = mark;
    numlen.first = min(numlen.first, j);
    numlen.second = max(numlen.second, j);
    dfs(i,j+1,arr,vis,numlen,mark);
    dfs(i,j-1,arr,vis,numlen,mark);
    return true;
}

long long value = 0;

void dfsa(int i, int j, vector<string> &arr, vector<string> &vis) {
    vector<int> pos {1,1,-1,1,0,-1,-1,0,1};

    Node star {{i,j}};

    for(int k=0;k<pos.size()-1;k++) {
        int newi = i+pos[k];
        int newj = j+pos[k+1];

        //cout << i+pos[k] << ' ' << j+pos[k+1] << endl;

        pair<int, int> newNumber {newj, newj};

        if(dfs(newi,newj,arr,vis, newNumber,'#')) {
            pair<int, pair<int, int>> adj_points {newi, newNumber};

            star.points.push_back(adj_points);
        }
    }

    if(star.points.size() == 2) {
        auto point1 = star.points[0];
        string a = arr[point1.first].substr(point1.second.first, point1.second.second - point1.second.first + 1);
        auto point2 = star.points[1];
        string b = arr[point2.first].substr(point2.second.first, point2.second.second - point2.second.first + 1);
        value += stoi(a)*stoi(b);
    }

    for(auto val: star.points) {
        // cout << val.first << '>' << val.second.first << ';' << val.second.second << endl;
    }
    for(int k=0;k<pos.size()-1;k++) {

        int newi = i+pos[k];
        int newj = j+pos[k+1];
        pair<int, int> dum {newj, newj};
        dfs(newi,newj,arr,vis, dum,'.');
    }
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
            if(arr[i][j] == '*')
                dfsa(i, j, arr, vis);
        }
    }
    cout << value << endl;

    return 0;
}
