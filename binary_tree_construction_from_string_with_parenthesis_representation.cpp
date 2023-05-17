/*
* https://www.tutorialspoint.com/construct-binary-tree-from-string-in-cplusplus
* Suppose we have a string consisting of parenthesis and integers. We have to construct a binary tree from that string. 
* The whole input represents a binary tree. It holds an integer that followed by zero, one or two pairs of parentheses. 
* The integer represents the root's value and a pair of parenthesis contains a child binary tree with the same structure.
* So, if the input is like "4(2(3)(1))(6(5))", then the output will be [3,2,1,4,5,6] (inorder traversal).
*/

#include <iostream>
using namespace std;

class Node{
    public:
        char v;
        Node *l;
        Node *r;
        Node *p;
        Node(char _v){
            v = _v;
            l = NULL;
            r = NULL;
            p = NULL;
        }
};

void inOrderTraversal(Node *root){
    if(root == NULL) return;
    inOrderTraversal(root->l);
    cout << root->v << endl ;
    inOrderTraversal(root->r);   
}

void freeTree(Node *root){
    if(root == NULL) return;
    freeTree(root->l);
    delete(root);
    freeTree(root->r); 

}

int main() {
    Node * c;
    Node * root = NULL; 
    Node * parent = NULL;
    string s ;
    cin >> s ;
    for(int i = 0 ; i < s.size() ; i++)
    {
        if(s[i] != ')' && s[i] != '(')
        {
            c = new Node(s[i]);
            if( i == 0) root = c;
            c->p = parent;
            if(i != 0 && parent->l == NULL)  parent->l = c;
            else if(i != 0 && parent->r == NULL) parent->r = c;
        }
        else if(s[i] == '(')    parent = c;
        else if (s[i] == ')')   c = c->p ;
    }
    
    inOrderTraversal(root);
    freeTree(root);
    return 0;
}
