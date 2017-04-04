#include<bits/stdc++.h>

using namespace std;

struct info
{
    string name;
    int roll, marks;

    info(){}

    info(string s, int r, int m)
    {
        name = s;
        roll = r;
        marks = m;
    }
};

struct node
{
    info data;
    node *left;
    node *right;

    node()
    {
        left = NULL;
        right = NULL;
    }
};

struct BST
{
    node *root;

    BST()
    {
        root = NULL;
    }

    node *new_node(info in)
    {
        node *p = new node;
        p->data = in;
        p->left = NULL;
        p->right = NULL;
    }

    node *insert_info(node *p, info in)
    {
        if(root == NULL) root = new_node(in);

        else if(p == NULL) p = new_node(in);

        else if(p->data.name>in.name) p->left = insert_info(p->left,in);

        else if(p->data.name<in.name) p->right = insert_info(p->right,in);

        else
        {
            if(p->data.roll > in.roll) p->left = insert_info(p->left,in);
            else p->right = insert_info(p->right, in);
        }
        return p;
    }

    void inorder(node *p)
    {
        if(p==NULL) return;

        inorder(p->left);
        cout<<p->data.name<<"\t"<<p->data.roll<<"\t"<<p->data.marks<<endl;
        inorder(p->right);
    }
};

main()
{
    BST b;

    freopen("input.txt", "r", stdin);

    int t, r, m;

    string nm;

    while(cin>>nm>>r>>m)
    {
        info in = info(nm,r,m);

        b.insert_info(b.root, in);
    }

    b.inorder(b.root);

    return 0;
}
