#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void init_prime(vector<int> &primes)
{
    vector<bool> is_p(2000001, true);
    is_p[0]=false;
    is_p[1]=false;
    for(int i=2;i<2000001;i++)
    {
        if(is_p[i]==false) continue;
        primes.push_back(i);
        for(int j=i+i;j<2000001;j+=i)
            is_p[j] = false;
    }    
}

int cal(int x, int p)
{
    int ans = 0;
    long long rec = p;
    while(x>=rec)
    {
        ans += x/rec;
        rec *= p;
    }
    return ans;
}

long long pow(long long n, int k)
{
    long long ans = 1LL;
    while(k)
    {
        if(k&1)
        {
            ans = (ans * n) % 1000000007LL;
        }
        n = (n * n) % 1000000007LL;
        k >>= 1;
    }
    return ans;
}

long long com(vector<int> &prim, int  n, int m)
{
    long long ans = 1LL;
    int num;
    for(int i=0; i<prim.size() && prim[i]<=n; ++i)
    {
        num = cal(n, prim[i]) - cal(m, prim[i]) - cal(n-m, prim[i]);
        ans = (ans * pow((long long)prim[i], num)) % 1000000007LL;
    }
    return ans;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    vector<int> primes;
    init_prime(primes);
    int T;
    int m,n;
    scanf("%d", &T);
    for(int i=0;i<T;++i)
    {
        scanf("%d%d", &m, &n);
        
        printf("%lld\n", com(primes, m-1+n-1, m-1));
    }
    return 0;
}

