#include <iostream>
using namespace std;

class Solution {
public:
    bool backspaceCompare(string s, string t) {
		int s_ptr = s.length() - 1;
		int t_ptr = t.length() - 1;

		while (s_ptr >= 0 && t_ptr >= 0){
			
			s_ptr = backspace(s, s_ptr);
			t_ptr = backspace(t, t_ptr);
			// s[s_ptr] and t[t_ptr] can only fall into either 1 of these twos:
			// - negative value
			// - a valid char
			if (s_ptr >= 0 && t_ptr >= 0){
				if (s[s_ptr] != t[t_ptr]){
					return false;
				}
			}

			s_ptr--;
			t_ptr--;
		}
		
		if (s_ptr < 0 && t_ptr < 0){
			cout << "trueeee" << endl;
			return true;
		} else{
			return false;
		}
    }
private:
	int backspace(string str, int ptr){
		int backspace = 0;
	
		while(ptr >= 0){
			if(str[ptr] == '#'){
				backspace++;
			} else if (backspace > 0){
			// not # and backspace > 0 -> char to be deleted
			// backspace is also deleted
				backspace--;
			} else{
				//exit the loop at the valid char
				break;
			}
			ptr--;		
		}
		cout << str << "," << ptr << endl;
		return ptr; 
	}
};

int main(){
	string s = "bxj##tw";
	string t = "bxj###tw";
	Solution sol;
	bool res = sol.backspaceCompare(s, t);
	cout << res << endl;
}