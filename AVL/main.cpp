
//include "av.h"
#include"avl.h"
#include <fstream>
ifstream fin("input.txt");
int main()
{
    int key;
    char option;

    NodeAVL *root = NULL;
    //	FILE *fp = fopen ( "input.txt", "r" );

//	if (!fp)
//	{
//		perror ( "Unable to open file" );
//		exit(0);
//	}

    while(1)
    {
        fin>>option;

        if( option == 'I' )
        {
            fin>>key;
            root = insertAVLNode( root, key );
        }
        else if( option == 'D' )
        {
            fin>>key;
            root = deleteAVLNode( root, key );
        }

    }

  //  fclose(fp);

    displayAVLTree(root,10);

  //  system("PAUSE");
    return 0;
}

