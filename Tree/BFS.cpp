#include <iostream>
#include <queue>
#include <vector>

struct TreeNode {
    int                     val;
    std::vector<TreeNode *> children;

    TreeNode(int value) : val(value) {}
};

void bfs(TreeNode *root) {
    if (root == nullptr)
        return;

    std::queue<TreeNode *> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode *current = q.front();
        q.pop();

        std::cout << current->val << " ";

        for (TreeNode *child : current->children) {
            q.push(child);
        }
    }
}

int main() {

    TreeNode *root        = new TreeNode(1);
    TreeNode *child1      = new TreeNode(2);
    TreeNode *child2      = new TreeNode(3);
    TreeNode *child3      = new TreeNode(4);
    TreeNode *grandchild1 = new TreeNode(5);
    TreeNode *grandchild2 = new TreeNode(6);
    TreeNode *grandchild3 = new TreeNode(7);

    root->children.push_back(child1);
    root->children.push_back(child2);
    child1->children.push_back(grandchild1);
    child1->children.push_back(grandchild2);
    child2->children.push_back(grandchild3);
    child3->children.push_back(new TreeNode(8));

    std::cout << "BFS traversal: ";
    bfs(root);
    std::cout << std::endl;

    delete grandchild1;
    delete grandchild2;
    delete grandchild3;
    delete child1;
    delete child2;
    delete child3;
    delete root;

    return 0;
}
