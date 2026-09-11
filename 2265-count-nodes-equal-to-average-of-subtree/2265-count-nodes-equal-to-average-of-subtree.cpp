/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

 #include <cmath>

class Solution {
public:
    struct SumLen {
        int sum;
        int length;
    };

    int count{0};

    SumLen cal_size_sum(TreeNode *node){
        SumLen t {.sum = 0,.length = 0};
        SumLen tl {.sum = 0,.length = 0};
        SumLen tr {.sum = 0,.length = 0};

        if(node->left != NULL) {
            tl = cal_size_sum(node->left);
        }

        if(node->right != NULL) {
            tr = cal_size_sum(node->right);
        }

        t.sum = node->val + tl.sum + tr.sum;
        t.length = 1 + tl.length + tr.length;

        int avg = round(t.sum / t.length);
        if (avg == node->val) {
            count++;
        }
        return t;
    }

    int averageOfSubtree(TreeNode* root) {
        (void) cal_size_sum(root);
        return count;
    }
};