#include <bitset>
#include <iostream>
using namespace std;

bitset<100000000> notPrimes;
void SieveOfEratosthenes(int n)
{
	notPrimes[0] = 1;
	notPrimes[1] = 1;
	
    for (int i = 2; i*i <= n; i++)
    {
        if (!notPrimes[i])
        {
            for (int j = i*i; j < n; j+=i)
            {
                notPrimes[j] = 1;
            }
        }
    }
}

int main()
{
	int n = 100000000;

    SieveOfEratosthenes(n);

    for (int i = n-1; i >= 0; i--)
    {
        if (!notPrimes[i])
        {
            cout << i;
            break;
        }
    }

    // for (int i = 0; i < n; i++)
    // {
    //     if (!notPrimes[i])
    //     {
    //         cout << i << " ";
    //     }
    // }

	return 0;
}