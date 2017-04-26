#include<bits/stdc++.h>
using namespace std;

struct node
{
    int val;
    node *left;
    node *right;

    node(int x)
    {
        val = x;
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

    node *insert_data(node *p, int n)
    {
        if(root==NULL) root = new node(n);

        else if(p==NULL) p = new node(n);

        else if(n <= p->val) p->left = insert_data(p->left,n);

        else if(n > p->val) p->right = insert_data(p->right,n);
    }

    bool search_node(node *p, int n)
    {
        if(p==NULL) return false;

        else if(n == p->val) return true;

        else if(n<p->val) return search_node(p->left,n);

        else if(n>p->val) return search_node(p->right,n);
    }

    void inorder(node *p, int n)
    {
        if(p==NULL) return;

        inorder(p->left, n);
        if(p->val<=n) cout<<p->val<<" ";  // condition diye n er theke chotosob node gula print korbo && count rakhle kotogula choto segula ber korbo
        inorder(p->right, n);
    }

    void postorder(node *p)
    {
        if(p==NULL) return;

        postorder(p->right);
        cout<<p->val<<" ";
        postorder(p->left);
    }

    void preeorder(node *p)
    {
        if(p==NULL) return;

        cout<<p->val<<" ";
        preeorder(p->left);
        preeorder(p->right);
    }
};



main()
{
    BST b;
    bool flag;

    b.insert_data(b.root, 5);
    b.insert_data(b.root, 2);
    b.insert_data(b.root, 8);
    b.insert_data(b.root, 1);
    b.insert_data(b.root, 3);


    b.insert_data(b.root, 4);
    b.insert_data(b.root, 8);
    b.insert_data(b.root, 7);
    b.insert_data(b.root, 6);

    cout<<"Inorder Traverse: \n";
    b.inorder(b.root, 6);
    puts("");

    cout<<"Postorder Traverse: \n";
    b.postorder(b.root);
    puts("");

    cout<<"Preeorder Traverse: \n";
    b.preeorder(b.root);
    puts("");

    flag = b.search_node(b.root, 1);
    cout<<(flag?"\n*******Found******\n":"\n******Not Found******\n");
}
