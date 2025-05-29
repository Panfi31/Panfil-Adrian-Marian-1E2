#include <iostream>
#include "Tree.hpp"

int main() {
    Tree<int> t;

    TreeNode<int>* root = t.add_node(nullptr, 1);
    TreeNode<int>* c1 = t.add_node(root, 2);
    t.add_node(root, 3);
    t.add_node(c1, 4);

    std::cout << "Numar total de noduri (fara radacina): " << t.count(root) << "\n";

    return 0;
}
