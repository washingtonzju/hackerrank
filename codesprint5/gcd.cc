#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;




int init_minus(vector<int> &minus, int n)
{
    if(minus[n]!=-1)
        return minus[n];
    int sq = (int)sqrt(n);
    minus[n] = n;
    for(int i=1;i<=sq;++i)
    {
        if(n%i==0)
        {
            minus[n]-=minus[i];
            if(n/i!=i && n/i!=n)
                minus[n]-=minus[n/i];
        }
    }
    return minus[n];
}

long long get_result(vector<int> &n, vector<int>&minus)
{
    long long ans = 1LL;
    int min = 10000000;
    for(int i=0;i<n.size();++i)
        if(n[i]<min)
            min = n[i];

    for(int i=0;i<n.size();++i)
        ans = (ans * n[i]) % 1000000007LL;

    long long tmp;
    for(int i=2;i<=min;++i)
    {
        tmp = 1LL;
        for(int j=0;j<n.size();++j)
            tmp = (tmp * (n[j]/i)) % 1000000007LL;
        //printf("%lld %lld %d %lld\n", ans, tmp, i, minus[i]);
        ans = (ans + tmp * minus[i]) % 1000000007LL;        
    }
    return ans;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T, K;   
    vector<int> minus(100001, -1);
    minus[1] = 1;
    for(int i=2;i<100001;++i)
        init_minus(minus, i);
    
    scanf("%d", &T);
    for(int i=0;i<T;++i)
    {
        scanf("%d", &K);
        vector<int> n(K);
        
        
        for(int j=0;j<K;++j)
            scanf("%d", &n[j]);
        printf("%lld\n", get_result(n, minus));
    }
    return 0;
}
