#include <iostream>
#include <algorithm>
#include <set>
#include "./minh_hash/HashOps.h"

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        HashOps<int, int, int_hash> hashMap;
        set<char> mag_keys(magazine.begin(), magazine.end());
        for (char K: mag_keys) { // store the number of occurences for each char in a hash table
            V = count(magazine.begin(), magazine.end(), K);
            hashMap.put(K, V);
        }
        
        set<char> note_keys(ransomNote.begin(), ransomNote.end());
        for (char K: note_keys) { // store the number of occurences for each char in a hash table
            int get_value;
            V = count(ransomNote.begin(), ransomNote.end(), K);
            bool res = hashMap.get(K, get_value);
            if (!res || get_value < V) {
                return false;
            }
        }

        return true;
    }

private:
    int V;
};

int main() {
    Solution sol;
    string ransomNote = "a";
    string magazine = "b";
    bool res = sol.canConstruct(ransomNote, magazine);
    cout << "ransomNote(?): " << res << endl;
}