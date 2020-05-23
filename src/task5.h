#pragma once
#include <vector>

struct TreeNode {
    struct TreeNode* leftChild;
    struct TreeNode* rightChild;
    int tag;
};

typedef std::vector<int> TreePath;

std::pair<int, std::vector<TreePath>> calculate_tree_depth(struct TreeNode* root);