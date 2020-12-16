#include "Btrees.h"

#define m 4

using namespace std;

int main() {
    int c;
    int ch;
    int keyx, key;
    NodeB* roo;
    roo = NULL;
    while (true) {
        cout<<"\n 1.Add";
        cout <<"\n 2.Delete";
        cout << "\n 3.Search";
        cout << "\n 4.Write";
        cout << "\n 5.Exit";
        cout << "\n\n";

        cin >> ch;

        switch (ch) {
        case 1:

                    cout<<"\n Enter key: ";
                    cin >> key;
                    roo = insert(key);

            break;

        case  2:
            cout<<"\n Enter Key: ";
            cin >> key;
            roo = deleteKey(&roo, key);
            break;

        case 3:
            cout<<"Enter key to search \n";
            cin >> keyx;
            search(roo, keyx);
            break;

        case 4:
            cout<<"\n\n";
            displayTree(roo, 4);
            break;

        case 5:
            return(0);
        }
    }
}
