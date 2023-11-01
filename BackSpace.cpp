#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool backspaceCompare(string s, string t) {
		string res_s = backspaceHandler(s);
		string res_t = backspaceHandler(t);

		return res_s == res_t;
    }
private:
	string backspaceHandler(string s){
		vector<char> v_string(s.begin(), s.end());
		for(int i=0; i < v_string.size(); i++){
			if (v_string[i] == '#'){
				v_string.erase(v_string.begin() + i);
				v_string.erase(v_string.begin() + i - 1);
				i = 0;
				continue;
			}
		}
		string res_str(v_string.begin(), v_string.end());
		
		return res_str;
	}
};

int main(){
	string s = "a##c";
	string t = "#a#c";
	Solution sol;
	bool res = sol.backspaceCompare(s, t);
	cout << res << endl;
}