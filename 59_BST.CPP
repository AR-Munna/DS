#include<bits/stdc++.h>
using namespace std;

struct tree
{
    char name[100];
    int roll;
    double marks;
    tree* left;
    tree* right;
};

struct BST
{
    tree* root;

    BST()
    {
        root = (tree*)malloc(sizeof(tree));
        root = NULL;
    }

    tree* newtree(char s[100],int r,double m)
    {
        tree* p = (tree*)malloc(sizeof(tree));
        strcpy(p->name,s);
        p->roll = r;
        p->marks = m;
        p->right = NULL;
        p->left = NULL;

    }

    tree* insert_w(tree* p,char s[100],int r,double m)
    {
        if(root==NULL)      root = newtree(s,r,m);

        else if(p==NULL)    p = newtree(s,r,m);

        else if(strcmp(p->name,s)>0)    p->left = insert_w(p->left,s,r,m);

        else if(strcmp(p->name,s)<0)    p->right = insert_w(p->right,s,r,m);

        else if(strcmp(p->name,s)==0)
        {
            if(p->roll>r)   p->left = insert_w(p->left,s,r,m);
            else    p->right = insert_w(p->right,s,r,m);
        }

        return p;

    }

    void inorder_print(tree* p)
    {
        if(p==NULL)     return;

        inorder_print(p->left);

        cout<<"(Name:"<<p->name<<" ";
        cout<<",Roll: "<<p->roll<<" ";
        cout<<", Marks:"<<p->marks<<")"<<"->";

        inorder_print(p->right);
    }


};

int main()
{
    BST a;
    char s[100];
    int n,i,j,k,l,o,r;
    double m;

    cout<<"1:Insert"<<endl;
    cout<<"2:Print"<<endl;

    while(1)
    {
        cin>>n;

        if(n==1)
        {
            cin>>s;
            cin>>r;
            cin>>m;
            a.insert_w(a.root,s,r,m);
        }

        else if(n==2)
        {
            a.inorder_print(a.root);
        }

    }

    return 0;
}
