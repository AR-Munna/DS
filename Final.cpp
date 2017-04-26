#include<bits/stdc++.h>
using namespace std;

struct node
{
    int val;
    node *next;
};

struct linkedlist
{
    node *head;

    linkedlist()
    {
        head = (node*)malloc(sizeof(node));
        head = NULL;
    }

    void insert_1st(int n)
    {
        node*p = (node*)malloc(sizeof(node));
        p->val = n;
        p->next = NULL;

        if(head==NULL)
        {
            head = p;
        }
        else
        {
            p->next = head;
            head = p;
        }
    }

    void insert_last(int n)
    {
        node*p = head;
        node*temp = (node*)malloc(sizeof(node));
        temp->val = n;
        temp->next = NULL;

        if(head==NULL)
        {
            head = temp;
        }
        else
        {
            while(p->next!=NULL)
            {
                p = p->next;
            }
            p->next = temp;
        }
    }

    int kth_node(int k)
    {
        node*p = head;
        int cnt=0;

        while(cnt<k)
        {
            p = p->next;
            cnt++;
        }
        p->next = NULL;

        return p->val;
    }

    void insert_after(int k, int n)
    {
        //int y = kth_node(k);
        int cnt=0;
        node*temp = (node*)malloc(sizeof(node));
        temp->val = n;
        temp->next = NULL;
        //cout<<"Y: "<<y<<endl;
        node*p = head;

        while(cnt<k)
        {
            cnt++;
            p = p->next;
        }

        temp->next = p->next;
        p->next = temp;

        //node*p = head;
        /*while(p->val!=k)
        {
            p = p->next;
        }
        temp->next = p->next;
        p->next = temp;*/

    }

    void insert_after1(int x, int y)
    {
        node*temp = (node*)malloc(sizeof(node));
        temp->val = y;
        temp->next = NULL;

        node*p = head;
        while(p->val!=x)
        {
            p = p->next;
        }
        temp->next = p->next;
        p->next = temp;

    }

    void insert_before(int k, int n)
    {
        int cnt=0;
        node*temp = (node*)malloc(sizeof(node));
        temp->val = n;
        temp->next = NULL;
        node*p = head;

        while(cnt<k-1)
        {
            cnt++;
            p = p->next;
        }

        temp->next = p->next;
        p->next = temp;
    }


    void delete_1st()
    {
        if(head==NULL) cout<<"Nothing to delete\n";
        else head = head->next;
    }

    void delete_last()
    {
        node*p = head;
        node*temp = (node*)malloc(sizeof(node));

        if(head==NULL) cout<<"Kichu nai, ki delete korbo :(\n";
        else
        {
            while(p->next!=NULL)
            {
                temp = p;
                p = p->next;
            }
            temp->next=NULL;
            free(p);
        }
    }

    void delete_kth_node(int k)
    {
        node*p = head;
        node*temp = (node*)malloc(sizeof(node));

        int cnt=0;
        if(k==0) delete_1st();
        else
        {
            while(1)
            {
                if(cnt==k) break;
                else
                {
                    temp = p;
                    p = p->next;
                    cnt++;
                }
            }

            temp->next = p->next;
        }
    }

    void copy_list(linkedlist &L)
    {
        node*p = head;

        while(p!=NULL)
        {
            L.insert_1st(p->val);
            p = p->next;
        }
    }

    int list_size()
    {
        int res = 0;
        node *p = head;

        while(p!=NULL)
        {
            ++res;
            p=p->next;
        }

        return res;
    }

    void reverse_list()
    {
        linkedlist L;

        node *p = head;

        while(p!=NULL)
        {
            L.insert_1st(p->val);
            p=p->next;
        }

        head = NULL;

        L.copy_list(*this);
    }

    void reverse_first()
    {
        int sz = list_size();

        node *p = head;

        linkedlist tmp;

        int i;

        for(i=1; i<=sz/2; i++)
        {
                tmp.insert_1st(p->val);
                p = p->next;
        }

        for(i=sz/2 + 1; i<=sz; i++)
        {
               tmp.insert_last(p->val);
               p = p->next;
        }

        head = NULL;

        tmp.copy_list(*this);
    }


    void print()
    {
        if(head==NULL) cout<<"EMPTY"<<endl;
        else
        {

            node* temp;
            temp = head;
            while(temp!=NULL)
            {
                cout<<temp->val<<" ";
                temp = temp->next;
            }
            puts("");
            puts("");
        }
    }
};

main()
{
    linkedlist l, L;

    l.insert_1st(1);
    l.insert_1st(2);
    l.insert_1st(3);
    l.insert_1st(4);
    l.insert_1st(5);

    cout<<"Print the List: ";
    l.print();

    l.insert_last(6);
    cout<<"Print After insert last: ";
    l.print();

    l.delete_1st();
    cout<<"Print After delete first: ";
    l.print();

    l.delete_last();
    cout<<"Print After delete last: ";
    l.print();

    cout<<"Print Kth node: "<<l.kth_node(1)<<endl;

    l.insert_after(1,10);
    cout<<"Print After insert after: ";
    l.print();

    l.insert_before(1,10);
    cout<<"Print After insert before: ";
    l.print();

    l.delete_kth_node(3);
    cout<<"Print After delete kth node: ";
    l.print();

    l.insert_1st(6);
    l.insert_1st(5);

    l.copy_list(L);
    cout<<"Print After copy: ";
    l.print();

    l.reverse_list();
    cout<<"Print After reverse: ";
    l.print();

    l.reverse_first();
    cout<<"Print After inverse: ";
    l.print();

}
