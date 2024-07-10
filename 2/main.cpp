#include <bits/stdc++.h>
using namespace std;

string trim(string str, char delim = ' ') {
    int i = 0;
    while(i < str.size() && str[i] == delim) i++;
    str = str.substr(i, str.size()-i);
    i = str.size()-1;
    while(i >= 0 && str[i] == delim) i--;
    str = str.substr(0, i+1);
    return str;
}

vector<string> split(string str, char delim = ' ') {
	vector<string> arr;
	int prev = 0;
    int n = str.size();
	string s;
	for(int i=0;i<=n;i++) {
		if(i == n || str[i] == delim) {
			s = trim(str.substr(prev, i-prev), delim);
			if(!s.empty()) arr.push_back(s);
			prev = i+1;
		}
	}
	return arr;
}

void appends(unordered_map<string, int> &mp, vector<string> str) {
    int score = stoi(str[0]);
    string color = str[1];
    mp[color] = max(mp[color], score);
}

int solve() {
    string str;
    int res = 0;
    while(getline(cin, str)) {
        if(str.empty()) continue;
        vector<string> games = split(str, ':');
        //string gameno = stoi(split(games[0])[1]);
        int gameno = stoi(split(games[0])[1]);
        //cout << gameno << endl;
        
        vector<string> subgames = split(games[1], ';');
        unordered_map<string, int> mp;
          
        for(auto subg: subgames) {
            vector<string> box = split(subg, ',');
            for(auto die: box) {
                appends(mp, split(die));
            }
        }
            int redcount = mp["red"];
            int greencount = mp["green"];
            int bluecount = mp["blue"];
            //if(redcount <= 12 && greencount <= 13 && bluecount <= 14) {
                //res+=gameno;
                int val = 1;
                if(mp["red"]) val*=mp["red"];
                if(mp["green"]) val*=mp["green"];
                if(mp["blue"]) val*=mp["blue"];
                cout << val << endl;
                res+=val;
            //}
    }
    return res;
}

int main() {
    unordered_map<string, int> val{{"red", 12}, {"green", 13}, {"bule", 14}};
    cout<<solve() << endl;
}

