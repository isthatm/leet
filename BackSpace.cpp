#include <iostream>
using namespace std;

class Solution {
public:
    bool backspaceCompare(string s, string t) {
		int s_ptr = s.length() - 1;
		int t_ptr = t.length() - 1;

		while (s_ptr >= 0 || t_ptr >= 0){
			s_ptr = backspace(s, s_ptr);
			t_ptr = backspace(t, t_ptr);
			// s[s_ptr] and t[t_ptr] can only fall into either 1 of these twos:
			// - negative value
			// - a valid char
			if (s_ptr < 0 && t_ptr < 0){
				return true;
			} else if (s_ptr < 0 || t_ptr < 0){
				cout << "FALSE" << endl;
				return false;
			}
			if (s_ptr >= 0 && t_ptr >= 0){
				if (s[s_ptr] != t[t_ptr]){
					return false;
				}
			}
			s_ptr--;
			t_ptr--;
		}
		return true;
    }

private:
	int backspace(string str, int ptr){
		int backspace = 0;
	
		while(ptr >= 0){
			if(str[ptr] == '#'){
				backspace++;
			} else if (backspace > 0){
				backspace--;
			} else{
				break;
			}
			ptr--;		
		}
		return ptr; 
	}
};

int main(){
	string s = "nzp#o#g";
	string t = "b#nzp#o#g";
	Solution sol;
	bool res = sol.backspaceCompare(s, t);
	cout << "Result: " << res << endl;
}