#include<bits/stdc++.h>
using namespace std;

struct heap
{
    int arr[100], temp[100];
    int sz, i;

    heap()
    {
        sz=0;
    }

    void insert_node(int n)
    {
       arr[++sz] = n;
       i = sz;

       while(i>1 && arr[i]>arr[i/2]) //if ">" then it will be a max heap
       {
           swap(arr[i/2],arr[i]);
           i = i/2;
       }
    }

    void print_heap()
    {
        for(int i=1; i<=sz; i++)
        {
            cout<<arr[i]<<" ";
        }
        puts("");
    }

    int delete_root()
    {
        int root = arr[1];
        swap(arr[1],arr[sz--]);
        int cur = 1;

        while(1)
        {
            int left = 2*cur;
            int right = left+1;

            if(arr[cur]<arr[left] && left<=sz && arr[left]>=arr[right] && right<=sz)
            {
                swap(arr[cur], arr[left]);
                cur = left;
            }

            else if(arr[cur]<arr[right] && right<=sz && arr[right]>=arr[left] && left<=sz)
            {
                swap(arr[cur], arr[right]);
                cur = right;
            }

            else if(arr[cur]<arr[left] && left<=sz && right>sz)
            {
                swap(arr[cur], arr[left]);
                cur = left;
            }

            else break;
        }

        return root;
    }

    void heap_sort()
    {
        int tmp = sz, sj=0;

        for(int i=0; i<tmp; i++)
        {
            sj++;
            temp[sj] = delete_root();
        }

        for(int i=1; i<=sj; i++) cout<<temp[i]<<" ";
        puts("");
    }
};

main()
{
    heap h;

    h.insert_node(1);
    h.insert_node(2);
    h.insert_node(4);
    h.insert_node(7);
    h.insert_node(5);
    h.insert_node(9);

    cout<<"Print the heap: \n";
    h.print_heap();

    cout<<"Print the heap after sorting: \n";
    h.heap_sort();
}
