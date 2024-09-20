#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* buildTree(const std::vector<std::optional<int>>& values) {
    if (values.empty() || !values[0].has_value()) {
        return nullptr;
    }

    TreeNode* root = new TreeNode(values[0].value());  // 第一个值作为根节点
    std::queue<TreeNode*> q;
    q.push(root);

    int i = 1;
    while (i < values.size()) {
        TreeNode* current = q.front();
        q.pop();

        // 添加左子节点
        if (i < values.size() && values[i].has_value()) {
            current->left = new TreeNode(values[i].value());
            q.push(current->left);
        }
        i++;

        // 添加右子节点
        if (i < values.size() && values[i].has_value()) {
            current->right = new TreeNode(values[i].value());
            q.push(current->right);
        }
        i++;
    }

    return root;
}

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) {
            return ans;
        }
        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);
        bool isOrderLeft = true;

        while (!nodeQueue.empty()) {
            deque<int> levelList;
            int size = nodeQueue.size();
            for (int i=0; i<size; i++) {
                auto node = nodeQueue.front();
                nodeQueue.pop();
                if (isOrderLeft) {
                    levelList.push_back(node->val);
                } else {
                    levelList.push_front(node->val);
                }
                if (node->left) {
                    nodeQueue.push(node->left);
                }
                if (node->right) {
                    nodeQueue.push(node->right);
                }
            }
            ans.emplace_back(vector<int>{levelList.begin(), levelList.end()});
            isOrderLeft = !isOrderLeft;
        }
        
        return ans;
    }
};


int main() {
    Solution solution;
    std::vector<std::optional<int>> values = {3, 9, 20, std::nullopt, std::nullopt, 15, 7};
    TreeNode* root = buildTree(values);

    auto result = solution.zigzagLevelOrder(root);

    for (int i=0; i<result.size(); i++) {
        for (int j=0; j<result[i].size(); j++) {
            printf("%d ", result[i][j]);
        }
    }
    return 0;
}