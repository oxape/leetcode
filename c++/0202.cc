#include <string>
#include <unordered_map>
#include <cstdio>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        std::unordered_map<int, int> map;
        int value;
        int old;
        int mod;
        while(true) {
            if (map.count(n)) {
                return false;
            }
            old = n;
            value = 0;
            while(n > 0) {
                mod = n%10;
                value += mod*mod;
                n = n/10;
            }
            if (value == 1) {
                break;
            }
            map.insert(std::pair<const int, int>(old, value));
            n = value;
        }
        return true;
    }
};


int main() {
    Solution solution;

    bool result = solution.isHappy(2);
    printf("%s\n", result?"true":"false");
    return 0;
}
