#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

void Display(Node* root, int nivel);
Node *Add_Node(Node *root,int data);
void preorder (Node *root);
void inorder(Node *root);
void postorder(Node *root);
Node* FindMin(Node* root);
Node* Delete( Node *root, int data);
//void writeInFile();


