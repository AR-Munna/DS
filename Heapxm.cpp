#include<bits/stdc++.h>
using namespace std;

struct info
{
    string name;
    int roll, marks;

    info()
    {

    }

    info(string n, int r, int m)
    {
        name = n;
        roll = r;
        marks = m;
    }
};

struct heap
{
    info in;
    info student[100];
    info temp[100];
    info ra[100];
    int index = 0, sz = 0;

    void insert_info(info in)
    {
        student[++index] = in;

        int i = index;

        while(i>1 && student[i].marks>student[i/2].marks)
        {
            swap(student[i/2],student[i]);
            i = i/2;
        }
    }

    void print()
    {
        for(int i=1; i<=index; i++)
        {
            cout<<"Name: "<<student[i].name<<"\t"<<"Roll: "<<student[i].roll<<"\t"<<"Marks: "<<student[i].marks<<endl;
        }
    }

    info delete_root()
    {
        info root = student[1];
        swap(student[1],student[index--]);
        int cur = 1;

        while(1)
        {
            int Lt = cur*2;
            int Rt = Lt+1;

            if(student[cur].marks<student[Lt].marks && Lt<=index && student[Lt].marks>=student[Rt].marks && Rt<=index)
            {
                swap(student[cur], student[Lt]);
                cur = Lt;
            }
            else if(student[cur].marks<student[Rt].marks && Rt<=index && student[Rt].marks>=student[Lt].marks && Lt<=index)
            {
                swap(student[cur],student[Rt]);
                cur = Rt;
            }

            else if(student[cur].marks<student[Lt].marks && Lt<=index && Rt>index)
            {
                swap(student[cur], student[Lt]);
                cur = Lt;
            }

            else break;
        }
        return root;
    }

    void heapsort()
    {
        int tmp = index;

        for(int i=0; i<tmp; i++)
        {

                sz++;
                temp[sz] = delete_root();

        }

        for(int i=1;i<=sz;i++)
        {
            cout<<"Name: "<<temp[i].name<<"\t"<<"Roll: "<<temp[i].roll<<"\t"<<"Marks: "<<temp[i].marks<<endl;
        }
    }

    void _rank()
    {
        int r = 1, cnt=0;

        for(int i=1; i<=sz;)
        {
            for(int j=i; j<=sz; j++)
            {
                if(temp[i].marks == temp[j].marks)
                {
                   cnt++;
                   cout<<r<<" Name: "<<temp[j].name<<"\t"<<"Roll: "<<temp[j].roll<<"\t"<<"Marks: "<<temp[j].marks<<endl;
                }
            }
            i += cnt;
            r++;
            cnt = 0;
        }
    }
};

main()
{
    heap h;

    int t, r, m;

    string nm;

    freopen("input.txt","r",stdin);

    while(cin>>nm>>r>>m)
    {
        info in = info(nm,r,m);

        h.insert_info(in);
    }

    h.print();
    cout<<"*********************************************\n";
    h.heapsort();
    cout<<"*********************************************\n";
    h._rank();

    return 0;

}
