#pragma once
#include <vector>

struct TreeNode {
    struct TreeNode* leftChild;
    struct TreeNode* rightChild;
    int tag;
};

typedef std::vector<int> TreePath;

std::pair<int, std::vector<TreePath>> calculate_tree_depth(struct TreeNode* root);

struct TreeNode* make_node(int tag, struct TreeNode* left, struct TreeNode* right);

void delete_node(struct TreeNode* node);