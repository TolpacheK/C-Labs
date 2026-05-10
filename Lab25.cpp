#include <iostream>

using namespace std;

class Tree {
public:
    virtual void draw() {
    }
};

class Tree1 : public Tree {
public:
    void draw() {
        cout << " /\\" << endl;
        cout << "//\\\\" << endl;
    }
};

class Tree2 : public Tree {
public:
    void draw() {
        cout << " /\\" << endl;
        cout << "/**\\" << endl;
    }
};

class Tree3 : public Tree {
public:
    void draw() {
        cout << " /\\" << endl;
        cout << "/++\\" << endl;
    }
};

int main() {
    Tree* trees[3];

    Tree1 tree1;
    Tree2 tree2;
    Tree3 tree3;

    trees[0] = &tree1;
    trees[1] = &tree2;
    trees[2] = &tree3;

    for (int i = 0; i < 3; i++) {
        cout << "Drawing " << i + 1 << ":" << endl;
        trees[i]->draw();
    }

    return 0;
}
