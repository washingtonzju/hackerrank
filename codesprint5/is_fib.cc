#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void generate_fib_sequence(vector<long long> &fibs)
{
    long long tmp;
    fibs.push_back(0LL);
    fibs.push_back(1LL);
    for(int i=2;;++i)
    {
        tmp = fibs[i-1]+fibs[i-2];
        if(tmp > (10000000000LL)) break;
        fibs.push_back(tmp);
        //printf("%lld ", fibs[i]);
    }
}

bool is_fib(vector<long long> &fibs, long long num)
{
    int begin = 0, end = fibs.size() -1;
    int mid;
    while(begin <= end)
    {
        mid = (begin + end)/2;
        if(fibs[mid]==num)
            return true;
        else if(fibs[mid]>num)
            end = mid - 1;
        else
            begin = mid + 1;
    }
    return false;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    vector<long long> fibs;
    fibs.clear();
    generate_fib_sequence(fibs);
    int T;
    long long N;
    scanf("%d", &T);
    for(int i=0;i<T;++i)
    {
        scanf("%lld", &N);
        if(is_fib(fibs, N))
            printf("IsFibo\n");
        else
            printf("IsNotFibo\n");
    }
    return 0;
}
