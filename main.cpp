#include <iostream>
#include "binarySearchTree.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    binarySearchTree T;
    cout << "Inserting 8, 3 10, 1, 6, 14, 4 ,7 ,13 into tree"<<endl;
    T.insert(8);
    T.insert(3);
    T.insert(10);
    T.insert(1);
    T.insert(6);
    T.insert(14);
    T.insert(4);
    T.insert(7);
    T.insert(13);
    
    cout<<"printing tree"<<endl;
    T.printTree();
    cout<<"removing 8"<<endl;
    T.remove(8);
    cout<<"printing tree"<<endl;
    T.printTree();
    
    return 0;
}
