#include<bits/stdc++.h>

typedef long long int ll;
using namespace std;

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b%a, a);
}
 
// Function to calculate all common divisors
// of two given numbers
// a, b --> input integer numbers
int commDiv(int a,int b)
{
    // find gcd of a,b
    int n = gcd(a, b);
 
    // Count divisors of n.
    int result = 0;
    for (int i=1; i<=sqrt(n); i++)
    {
        // if 'i' is factor of n
        if (n%i==0)
        {
            // check if divisors are equal
            if (n/i == i)
                result += i;
            else
                result += (i+n/i);
        }
    }
    return result;
}
int main(){
	ll n;
	ll sum = 0; 
	cin>>n;
	for(ll i=1;i<=n;i++){
		for(ll j=i;j<=n;j++){
			int cur = commDiv(i,j);
			 
			sum+=cur;
		}
	}
	cout<<sum;
	
}
