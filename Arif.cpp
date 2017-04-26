#include<bits/stdc++.h>
using namespace std;

// singly linked list

struct node
{

    int val;
    node* next;

    node(int x)
    {
        val = x;
        next=NULL;
    }
};

struct SinglyLinkedList
{

    node *head;

    SinglyLinkedList()
    {
        head = (node*)malloc(sizeof(node));
        head = NULL;
    }


    void insert_first(int val)
    {
        node *a = new node(val);

        if(head==NULL)  head = a;

        else
        {
            a->next = head;
            head = a;

        }
    }

    void insert_last(int val)
    {

        node *a = new node(val);

        if(head==NULL)  head = a;

        else
        {
            node *p = head;

            while(p->next!=NULL)    p = p->next;

            p->next = a;
        }
    }


    void insert_after(int k, int val)
    {
        node *a = new node(val);

        node *p = head;

        for(int i=1; i<k; i++)  p = p->next;

        a->next = p->next;
        p->next = a;
    }

    void insert_before(int k, int val)
    {
        if(k==1)    insert_first(val);
        else insert_after(k-1, val);
    }


    void print_list()
    {

        node *p = head;

        cout<<"List: ";
        while(p!=NULL)
        {
            cout<<p->val<<" ";
            p=p->next;
        }

        puts("");
    }


    void delete_first()
    {
        if(head==NULL)  return;

        if(head->next==NULL)    head = NULL;

        else head = head->next;
    }


    void delete_last()
    {
        if(head==NULL)  return;

        if(head->next==NULL)    head = NULL;

        else
        {
            node *p = head;

            while(p->next->next!=NULL)    p = p->next;

            p->next = NULL;
        }

    }


    void delete_kth(int k)
    {
        if(k==1)   delete_first();

        else
        {
            node *p = head;
            for(int i=1; i<k-1; i++)  p = p->next;
            p->next = p->next->next;
        }
    }

    void copy_list(SinglyLinkedList &L)
    {
        node *p = head;

        while(p!=NULL)
        {
            L.insert_last(p->val);
            p=p->next;
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
        SinglyLinkedList L;

        node *p = head;

        while(p!=NULL)
        {
            L.insert_first(p->val);
            p=p->next;
        }

        head = NULL;

        L.copy_list(*this);
    }


    void reverse_first()
    {
        int sz = list_size();

        node *p = head;

        SinglyLinkedList tmp;

        int i;

        for(i=1; i<=sz/2; i++)
        {
                tmp.insert_first(p->val);
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



};


int main()
{

    SinglyLinkedList a;


    a.insert_first(6);
    a.insert_first(5);
    a.insert_first(4);
    a.insert_first(3);
    a.insert_first(2);
    a.insert_first(1);

    a.print_list();
    a.reverse_first();

    a.print_list();
    a.reverse_first();
    a.print_list();


  //  a.copy_list(b);

   // b.print_list();


}

