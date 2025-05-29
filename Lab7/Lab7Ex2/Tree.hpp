#pragma once

template<typename T>
class TreeNode {
public:
    T value;
    TreeNode<T>** children;
    int childCount, capacity;

    TreeNode(T val) : value(val), children(nullptr), childCount(0), capacity(0) {}

    ~TreeNode() {
        for (int i = 0; i < childCount; i++) {
            delete children[i];
        }
        delete[] children;
    }

    void add_child(TreeNode<T>* child) {
        if (childCount == capacity) {
            int newCapacity = (capacity == 0) ? 2 : capacity * 2;
            TreeNode<T>** newChildren = new TreeNode<T>*[newCapacity];
            for (int i = 0; i < childCount; i++) {
                newChildren[i] = children[i];
            }
            delete[] children;
            children = newChildren;
            capacity = newCapacity;
        }
        children[childCount++] = child;
    }
};

template<typename T>
class Tree {
public:
    TreeNode<T>* root = nullptr;

    TreeNode<T>* add_node(TreeNode<T>* parent, T val) {
        TreeNode<T>* node = new TreeNode<T>(val);
        if (parent == nullptr) {
            root = node;
        }
        else {
            parent->add_child(node);
        }
        return node;
    }

    int count(TreeNode<T>* node) {
        if (node == nullptr) node = root;
        if (node == nullptr) return 0;

        int total = node->childCount;
        for (int i = 0; i < node->childCount; i++) {
            total += count(node->children[i]);
        }
        return total;
    }
};


