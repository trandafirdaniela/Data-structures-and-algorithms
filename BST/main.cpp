#include"bst.h"


int main()

{

    Node *root=nullptr;
    int i,n,x;
    do
    {
        cout<<"\n1.Adauga un nod";
        cout<<"\n2.Sterge un nod";
        cout<<"\n3.Preorder";
        cout<<"\n4.Inorder";
        cout<<"\n5.Postorder";
        cout<<"\n6.Arborescenta";
        cout<<"\n\nOptiunea dumneavoastra: ";
        cin>>i;
        switch(i)
        {
        case 1:
            cin>>n;
               root= Add_Node(root,n);
            break;
        case 2:
            cout<<"\nAlegeti nodul pe care doriti sa-l stergeti";
            cin>>x;
            root=Delete(root,x);
            break;
        case 3:
            preorder(root);
            break;
        case 4:
            inorder(root);
            break;
        case 5:
            postorder(root);
            break;
        case 6:
            Display(root, 0);
            break;
        }



    }
    while(i);
}
