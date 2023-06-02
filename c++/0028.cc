#include <string>
#include <vector>
#include <cstdio>

using namespace std;

class Solution {
public:
    static char base;

    int strStr(string haystack, string needle) {
        // return search('a', haystack, needle);
        return search('a', haystack, needle);
    }

    void kmp_construct(char base, vector<vector<int>> &dfa, string p) {
        vector<char> letters;
        int M = p.size();
        dfa.push_back({});
        for (int i=0; i<26; i++) {
            letters.push_back((char)((int)base+i));
            dfa[0].push_back(0);
        }
        dfa[0][(int)p.at(0)-((int)base)] = 1;
        for (int X=0, j=1; j < M; j++) {
            
            dfa.push_back({});
            for (int li=0; li<letters.size(); li++) {
                int index = (int)letters[li]-((int)base);
                dfa[j].push_back(dfa[X][index]);
            }
            dfa[j][(int)p.at(j)-((int)base)] = j+1;
            // printf("j = %d c = %c X = %d [%d][%c]=%d\n", j, p.at(j), X, X, p.at(j), dfa[X][(int)p.at(j)-((int)base)]);
            X = dfa[X][(int)p.at(j)-((int)base)];
        }
    }

    int search(char base, string s, string p) {
        vector<vector<int>> dfa;
        kmp_construct(base, dfa, p);
        int i;
        int q;
        int M = p.size();
        for (i=0, q=0; i<s.size() && q < M; i++) {
            q = dfa[q][(int)s.at(i)-((int)base)];
        }
        if (q == M) {
            return i-M;
        }
        return -1;
    }

    void next_construct(char base, vector<int> &next, string p) {
        int M = p.size();
        int j=0;
        int i=1; //失配时从pattern[i=1]和patter[j=0]开始尝试
        next.assign(M, 0);
        while (i < M) {
            if (p[i] == p[j]) {
                j++;
                next[i] = j+1;
                i++;
            } else if (j == 0){
                next[i] = 0;
                i++;
                j=0; //为了方便理解
            } else {
                j = next[j - 1];//匹配失败的时候，j回到j-1位的最长前后缀的位置
            }
        }
    }

    void next_construct_minus_one(char base, vector<int> &next, string p) {
        int M = p.size();
        int j=-1;
        int i=0;
        next.assign(M+1, -1);
        while (i < M) {
            if (j == -1) {
                i++;
                next[i] = 0;
                j = 0;
            } else if (p[i] == p[j]) {
                i++;
                next[i] = j+1;
                j++;
            } else {
                j = next[j];//匹配失败的时候，j回到j-1位的最长前后缀的位置
            }
        }
    }

    int ptm_search(char base, string s, string p) {
        return -1;
    }
};

int main() {
    Solution solution;
    int result = solution.strStr("bcbaabacaababacaa", "ababac");
    // int result = solution.strStr("aabaabaafa", "aabaaf");
    vector<int> next;
    // solution.next_construct('a', next, "ababac");
    // solution.next_construct_minus_one('a', next, "ababac");
    // solution.next_construct_minus_one('a', next, "abababca");
    solution.next_construct_minus_one('a', next, "ababaa");
    solution.next_construct_minus_one('a', next, "ababaa");
    solution.next_construct_minus_one('a', next, "aabc");
    printf("######%d\n", result);
    return 0;
}