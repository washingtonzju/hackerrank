#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <vector>

long long lego_func(int n, int m, vector<long long> &lego)
{
    if(lego[m]!=-1LL) return lego[m];
    if(m==0) return 1LL;
    if(
}

long long get_lego_blocks(int n, int m)
{
    vector<long long> single(m+1, 0LL);
    single[0]=1LL;
    for(int i=0;i<m;++i)
    {
        for(int j=1;j<5;++j)
            if(i+j<m+1)
            {
                single[i+j]+=single[i];
                single[i+j]%=1000000007;
            }
    }

    vector<long long> lego(m+1, -1LL);
    lego(0)=1L;
    return lego_func(n, m, lego);
}

int main() {
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T, M, N;
    scanf("%d", &T);
    for(int i=0;i<T;++i)
    {
        scanf("%d%d", &N, &M);
    }
    
    return 0;
}
