//
// Created by ezgi on 29.12.2018.
//

#ifndef RAS111_TREE_H
#define RAS111_TREE_H

#include <DataStructures/LinkedList/LinkedList.h>

typedef struct TreeNode {
    int value;
    TreeNode *left;
    TreeNode *right;
};

TreeNode *treeCreateNode(int data) {
    TreeNode *node = (TreeNode *) malloc(sizeof(TreeNode));
    node->left = NULL;
    node->right = NULL;
    node->value = data;
    return node;

}

TreeNode *doTreeInsert(TreeNode *node, TreeNode *root) {
    if (!root) {
        errorAndExit("root is null");
    }
    if (node->value > root->value) {
        if (root->right == NULL) {
            root->right = node;
        } else {
            doTreeInsert(node, root->right);
        }

    }
    if (node->value < root->value) {
        if (root->left == NULL) {
            root->left = node;
        } else {
            doTreeInsert(node, root->left);
        }

    }
    if (node->value == root->value) {
        errorAndExit("value already exists on tree\n");
    }
    return root;
}

TreeNode *treeInsert(TreeNode *self, int value) {
    TreeNode *node = treeCreateNode(value);
    doTreeInsert(node, self);
    return node;
}

int treeMaxValue(TreeNode *root) {
    if (root->right != NULL) {
        treeMaxValue(root->right);
    } else {
        return root->value;
    }
}

void treeInorder(TreeNode *root, int (consumer)(int, void *), void *env) {
    if (!root) {
        return;
    }
    treeInorder(root->left, consumer, env);
    if (!consumer(root->value, env)) { return; }
    treeInorder(root->right, consumer, env);
}

int treeFind(int data, TreeNode *root) {
    if(root==NULL)
    {
        errorAndExit("root returned null");
    }
    if(data==root->value)
    {
         return 1;
    }
    if(data<root->value)
    {
        if(root->left==NULL)
        {
            return 0;
        }
        return treeFind(data, root->left);
    }
    if(data>root->value)
    {
        if(root->right==NULL)
        {
            return 0;
        }
        return treeFind(data, root->right);
    }
}

#endif //RAS111_TREE_H
