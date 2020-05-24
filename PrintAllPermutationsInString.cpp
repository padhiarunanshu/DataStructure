#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
  
  void swap(char& a, char& b) {
    char t = a; a = b; b = t;
  }
  
public:
  void permute(string s, int l, int r) {
    static int count = 1;
    if (l == r) cout << count++ << " " << s << endl;
    else {
        for(int i = l; i <= r; i++) {
            swap(s[l],s[i]);
            permute(s, l+1, r);
            swap(s[l], s[i]);
        }
    }
  }
};


int main()
{
    Solution s;
    string str = "FDGK";
    
    s.permute(str, 0, str.size() - 1);
    

    return 0;
}
