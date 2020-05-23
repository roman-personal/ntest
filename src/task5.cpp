#include "task5.h"

struct TreeWalker {
    int max_depth = 0;
    int current_depth = 0;
    std::vector<TreePath> paths;
    std::vector<int> current_path;

    void walk(struct TreeNode* tree) {
        if (tree == nullptr)
            return;
        current_depth++;
        current_path.push_back(tree->tag);
        if (is_leaf(tree)) {
            if (current_depth > max_depth) {
                paths.clear();
                paths.push_back(current_path);
                max_depth = current_depth;
            }
            else if (current_depth == max_depth) {
                paths.push_back(current_path);
            }
        }
        else {
            walk(tree->leftChild);
            walk(tree->rightChild);
        }
        current_path.pop_back();
        current_depth--;
    }

    bool is_leaf(struct TreeNode* node) {
        return node->leftChild == nullptr && node->rightChild == nullptr;
    }

};

std::pair<int, std::vector<TreePath>> calculate_tree_depth(struct TreeNode* tree) {
    TreeWalker walker;
    walker.walk(tree);
    return std::make_pair(walker.max_depth, walker.paths);
}

struct TreeNode* make_node(int tag, struct TreeNode* left, struct TreeNode* right) {
    auto node = new TreeNode();
    node->tag = tag;
    node->leftChild = left;
    node->rightChild = right;
    return node;
}

void delete_node(struct TreeNode* node) {
    if (node == nullptr)
        return;
    delete_node(node->leftChild);
    delete_node(node->rightChild);
    delete node;
}