#include <map>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <iostream>

using namespace std;

class Solution1 {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> notvisisted;
        unordered_map<string, int> wordListMap;
        queue<string> q;

        for (const string &word : wordList) {
            wordListMap[word] = 1;
        }

        unordered_map<string, int> wordDis;
        wordDis[beginWord] = 0;
        q.push(beginWord);
        while(q.size() > 0) {
            auto w = q.front();
            q.pop();

            if (notvisisted.find(w) != notvisisted.end()) {
                continue;
            }
            notvisisted.insert(w);

            for (int i=0; i<w.size(); i++) {
                for (char ch='a'; ch<='z'; ch++) {
                    string newWord = w;
                    newWord[i] = ch;
                    if (notvisisted.find(newWord) != notvisisted.end()) {
                        continue;
                    }
                    if (wordListMap.find(newWord) != wordListMap.end()) {
                        if (wordDis[newWord] == 0 || wordDis[newWord] > wordDis[w] + 1) {
                            wordDis[newWord] = wordDis[w] + 1;
                        }
                        if (newWord == endWord) {
                            return wordDis[newWord]+1;
                        }
                        q.push(newWord);
                    }
                }
            }
        }
        return 0;
    }
};

class Solution2{
public:
    unordered_map<string, int> wordId;
    unordered_map<int, string> idWord;
    vector<vector<int>> edge;
    int nodeNum = 0;

    void addWord(string &origin, string &word) {
        if (!wordId.count(word)) { //这里只是给每个节点一个唯一的id, 所以已经存在的节点不需要重复设置id
            wordId[word] = nodeNum++;
            idWord[nodeNum-1] = word;
            edge.emplace_back();
        }
    }

    void addEdge(string &word) {
        string origin = word;
        addWord(origin, word);
        int id1 = wordId[word];
        for (char &it : word) {
            char tmp = it;
            it = '*';
            addWord(origin, word);
            int id2 = wordId[word];
            edge[id1].push_back(id2);
            edge[id2].push_back(id1);
            it = tmp;
        }
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        for (string &word : wordList) {
            addEdge(word);
        }

        addEdge(beginWord);

        if (!wordId.count(endWord)) {
            return 0;
        }

        vector<int> dis(nodeNum, INT_MAX);
        int beginId = wordId[beginWord], endId = wordId[endWord];
        dis[beginId] = 0;

        queue<int> que;
        que.push(beginId);
        while (!que.empty()) {
            int x = que.front();
            que.pop();
            if (x == endId) {
                return dis[endId] / 2 + 1;
            }
            for (int &it : edge[x]) {
                /*
                这里就把可能出现的循环为去除了，已经访问过的节点不需要访问了。
                由于这是一个广度优先搜索，所以第一次访问到的节点的路径一定是最短的。
                */
                if (dis[it] == INT_MAX) {
                    dis[it] = dis[x] + 1;
                    printf("%s -> %s\n", idWord[x].c_str(), idWord[it].c_str());
                    que.push(it);
                } else {
                    printf("### %s -> %s is wrong\n", idWord[x].c_str(), idWord[it].c_str());
                }
            }
        }
        return 0;
    }
};

int main() {
    Solution2 s;
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
    // vector<string> wordList = {"hot","dot","dog","lot","log"};

    // string beginWord = "a";
    // string endWord = "c";
    // vector<string> wordList = {"a","b","c"};

    cout << s.ladderLength(beginWord, endWord, wordList) << endl;
    return 0;
}
