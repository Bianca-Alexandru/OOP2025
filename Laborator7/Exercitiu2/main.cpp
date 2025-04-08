#include <iostream>
using namespace std;

template<typename T>
class TreeNode {
public:
    T value;
    TreeNode** children;
    int childCount;
    int capacity;
    TreeNode* parent;

    TreeNode(T val, TreeNode* parent = nullptr) {
        this->value = val;
        this->parent = parent;
        childCount = 0;
        capacity = 2;
        children = new TreeNode * [capacity];
    }

    ~TreeNode() {
        for (int i = 0; i < childCount; i++) {
            delete children[i];
        }
        delete[] children;
    }

    void addChild(TreeNode* child) {
        if (childCount == capacity) {
            resize();
        }
        children[childCount++] = child;
    }

    void insertChild(TreeNode* child, int index) {
        if (index < 0 || index > childCount) return;
        if (childCount == capacity) {
            resize();
        }
        for (int i = childCount; i > index; i--) {
            children[i] = children[i - 1];
        }
        children[index] = child;
        childCount++;
    }

    void removeChild(TreeNode* child) {
        int index = -1;
        for (int i = 0; i < childCount; ++i) {
            if (children[i] == child) {
                index = i;
                break;
            }
        }
        if (index == -1) return;

        delete children[index];

        for (int i = index; i < childCount - 1; i++) {
            children[i] = children[i + 1];
        }
        childCount--;
    }

    void resize() {
        capacity *= 2;
        TreeNode** newChildren = new TreeNode * [capacity];
        for (int i = 0; i < childCount; i++) {
            newChildren[i] = children[i];
        }
        delete[] children;
        children = newChildren;
    }
};

template<typename T>
class Tree {
private:
    TreeNode<T>* root;

public:
    Tree() : root(nullptr) {}

    ~Tree() {
        if (root) delete root;
    }

    TreeNode<T>* add_node(TreeNode<T>* parent, T val) {
        TreeNode<T>* newNode = new TreeNode<T>(val, parent);
        if (parent == nullptr) {
            root = newNode;
        }
        else {
            parent->addChild(newNode);
        }
        return newNode;
    }

    TreeNode<T>* get_node(TreeNode<T>* parent) {
        return parent == nullptr ? root : parent;
    }

    void delete_node(TreeNode<T>* node) {
        if (node == nullptr) return;
        if (node == root) {
            delete root;
            root = nullptr;
        }
        else if (node->parent != nullptr) {
            node->parent->removeChild(node);
        }
    }

    TreeNode<T>* find(TreeNode<T>* node, T target, bool (*cmp)(T, T)) {
        if (!node) return nullptr;
        if (cmp(node->value, target)) return node;

        for (int i = 0; i < node->childCount; ++i) {
            TreeNode<T>* found = find(node->children[i], target, cmp);
            if (found) return found;
        }
        return nullptr;
    }

    void insert(TreeNode<T>* parent, int index, T val) {
        if (!parent) return;
        TreeNode<T>* newNode = new TreeNode<T>(val, parent);
        parent->insertChild(newNode, index);
    }

    void sort(TreeNode<T>* node, bool (*cmp)(T, T) = nullptr) {
        if (!node || node->childCount <= 1) return;
        for (int i = 0; i < node->childCount - 1; ++i) {
            for (int j = 0; j < node->childCount - i - 1; ++j) {
                T a = node->children[j]->value;
                T b = node->children[j + 1]->value;
                bool swapNeeded = false;
                if (cmp) {
                    swapNeeded = cmp(b, a);
                }
                else {
                    swapNeeded = b < a;
                }
                if (swapNeeded) {
                    TreeNode<T>* temp = node->children[j];
                    node->children[j] = node->children[j + 1];
                    node->children[j + 1] = temp;
                }
            }
        }
    }

    int count(TreeNode<T>* node) {
        if (!node) {
            node = root;
            if (!node) return 0;
        }

        int total = node->childCount;
        for (int i = 0; i < node->childCount; ++i) {
            total += count(node->children[i]);
        }
        return total;
    }

    TreeNode<T>* get_root() {
        return root;
    }
};
bool int_equals(int a, int b) {
    return a == b;
}

int main() {
    Tree<int> tree;
    TreeNode<int>* root = tree.add_node(nullptr, 1);
    TreeNode<int>* child1 = tree.add_node(root, 5);
    TreeNode<int>* child2 = tree.add_node(root, 2);

    tree.insert(root, 1, 8); 
    tree.sort(root);         

    cout << "Total nodes under root: " << tree.count(root) << endl;

    TreeNode<int>* found = tree.find(root, 2, int_equals);
    if (found) {
        cout << "Found node with value: " << found->value << endl;
    }

    return 0;
}
