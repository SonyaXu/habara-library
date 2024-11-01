#include <bits/stdc++.h>
template <typename T>  
struct Fenwick {  
    int n;  
    std::vector<T> a;  

    Fenwick(int n_ = 0) {  
        init(n_);  
    }  

    void init(int n_) {  
        n = n_;  
        a.assign(n + 1, T{}); 
    }  

    void add(int x, const T& v) {  
        for (int i = x; i <= n; i += i & -i) {  
            a[i] += v;  
        }  
    }
    
    T sum(int x) {  
        T ans = 0;  
        for (int i = x; i > 0; i -= i & -i) {  
            ans += a[i];  
        }  
        return ans;  
    }  

    T rangeSum(int l, int r) {   
        return sum(r) - sum(l - 1);  
    }  
}; 