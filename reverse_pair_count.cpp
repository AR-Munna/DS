#include<bits/stdc++.h>
using namespace std;
//int l=0, r=0, c=0;
void printArray(int a[], int n){
    int i;
    for(i=0; i<n; i++) {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int mergeArray(int a[], int left, int middle, int right){
    int n1 = middle-left+1;
    int n2 = right-middle;
    int left_array[n1], right_array[n2];
    
    for(int i=0; i<n1; i++) left_array[i] = a[left+i];
    for(int i=0; i<n2; i++) right_array[i] = a[middle+1+i];

    int i=0, j=0, k=left, c=0;

    while(i<n1 && j<n2){
        if(left_array[i]>right_array[j]) {
            a[k] = left_array[i];
            if(left_array[i]>2*right_array[j]) {
                c++;
            }
            i++;
        }
        else if(left_array[i]<=right_array[j]){
            a[k] = right_array[j];
            j++;
        }
        //cout<<"c: "<<c<<endl;
        k++;
    }

    while(i<n1){
        a[k] = left_array[i];
        i++;
        k++;
    }

    while(j<n2){
        a[k] = right_array[j];
        j++;
        k++;
    }
    return c;
}

int mergeSort(int a[], int left, int right){
    int res = 0;
    if(left<right){
        int middle = (right+left)/2;
        res += mergeSort(a, left, middle);
        res += mergeSort(a, middle+1, right);

        res += mergeArray(a, left, middle, right);
    }
    return res;
}
int main(){
    //int a[] = {1, 3, 2, 3, 1};
    int a[] = {2, 4, 3, 5, 1};
    int sz = sizeof(a)/sizeof(a[0]);
    cout<<mergeSort(a,0,sz-1)<<endl;
    //printArray(a, sz);
    return 0;
}