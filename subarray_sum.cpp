#include<bits/stdc++.h>
using namespace std;

int maxVal(int x, int y){
    if(x>=y) return x;
    else return y;
}

int maxSum(int a[], int left, int right){
    if(right<=left) return a[left];

    int middle = left + (right-left)/2;
    int max_l = INT_MIN, s=0, max_r=INT_MIN;

    for(int i=middle; i>=left; i--){
        s += a[i];
        if(s>max_l) max_l = s;
    }
    s = 0;

    for(int i=middle+1; i<=right; i++){
        s += a[i];
        if(s>max_r) max_r = s;
    }

    int x = maxVal(maxSum(a,left, middle), maxSum(a, middle+1, right));
    int y = max_l+max_r;
    return max(x,y);
}

int main(){
    int a[] = { 2, -4, 1, 9, -6, 7, -3 };
    int n = sizeof(a) / sizeof(a[0]);
    cout<<maxSum(a, 0, n-1)<<endl;
    return 0;
}