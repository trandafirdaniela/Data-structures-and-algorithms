#include "bst.h"
void Display(Node* root, int nivel)
{
    int i;
    if(root==nullptr)
        return;

    Display(root->right, nivel+1);

    for(i=0; i<=nivel; i++)
        cout<<"    ";
    cout<<root->data<<"\n";
    Display(root->left,nivel+1);

}

Node *Add_Node(Node *root,int data)
{
    if(root==NULL)
    {
        root=new Node;
        root->data=data;
        root->left=root->right=NULL;
    }
    else if(data <= root->data)
    {
        root->left=Add_Node(root->left,data);
    }
    else
    {
        root->right=Add_Node(root->right,data);
    }
    return root;
}
void preorder (Node *root)//RSD
{
    //daca nu s-a ajuns la ultimul nod
    if(root!=NULL)
    {
        //se viziteaza radacina
        cout<<"\n"<<root->data;
        //se viziteaza copilul din stanga apoi cel din dreapta
        preorder(root->left);
        preorder(root->right);
    }
}
void inorder(Node *root) //SRD
{
    //daca nu s-a ajuns la ultimul nod
    if(root!=NULL)
    {
        inorder(root->left);//se viziteaza copilul din stanga
        cout<<"\n"<<root->data;//se viziteaza radacina
        inorder(root->right);//se viziteaza copilul din dreapta
    }
}
void postorder(Node *root)
{
    if (root!=NULL)//daca nu s-a ajuns la ultimul nod
    {
        postorder(root->left);//se viziteaza copilul din dreapta
        postorder(root->right);//se viziteaza copilul din stanga
        cout<<"\n"<<root->data;//se viziteaza radacina
    }
}

Node* FindMin(Node* root)
{
    //minimul cel mai din stanga
    while(root->left != NULL)
        root = root->left;
    return root;
}
Node* Delete( Node *root, int data)
{


    if(root == NULL)
        return root;
    if(data < root->data)
        root->left = Delete(root->left,data);
    else if (data > root->data)
        root->right = Delete(root->right,data);
    else
    {
        // nod cu un singur copil ori fara
        if (root->left == NULL)
        {
            Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            free(root);
            return temp;
        }

        // nod cu 2 : cel mai mic din partea dreapta
        Node* temp = FindMin(root->right);

        //conținutul succesorului inorder în acest nod
          root->data = temp->data;

        // sterge succesorul inorder
        root->right = Delete(root->right, temp->data);
    }

    return root;
}

//int randomNumberGenerator()
//{
//
//    return rand() % G_values_limit;
//}
//
//void randomizareInput(ofstream &outputFile, int minValue, int MaxValue, int nrOfValues){
//    int random_node;
//    time_t t;
//    srand((unsigned) time(&t));
//    for(int iterator1 = 0; iterator1 < nrOfValues; iterator1++){
//        random_node = minValue + rand() % (MaxValue - minValue+1);
//        outputFile << random_node << endl;
//    }
//}
//void writeInFile()
//{
//  ofstream myfile;
//  myfile.open ("test.txt");
//  myfile << "Writing this to a file.\n";
//  myfile.close();
//}
