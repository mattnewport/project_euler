#include <algorithm>
#include <numeric>
#include <iostream>

using namespace std;

// Find the sum of all the multiples of 3 or 5 below 1000.
int p1()
{
	int sum = 0;
	for (int i = 0; i != 1000; ++i)
	{
		if (i % 3 == 0 || i % 5 == 0)
		{
			sum += i;
		}
	}
	return sum;
}

long long fib(const unsigned int n)
{
	if (n < 2) return n;

	long long f[] = { fib(1), fib(0) };
	for (unsigned int i = 2; i <= n; ++i)
	{
		auto temp = f[0] + f[1];
		f[1] = f[0];
		f[0] = temp;
	}
	return f[0];
}

long long p2()
{
	long long sum = 0;
	unsigned int i = 0;
	long long thisFib = fib(0);
	while (thisFib <= 4000000)
	{
		sum += thisFib;
		i += 2;
		thisFib = fib(i);
	}
	return sum;
}

#define SOLVE_PROBLEM(x) cout << "Problem " #x ": Answer: " << p##x() << endl;

int main()
{
	SOLVE_PROBLEM(1);
	SOLVE_PROBLEM(2);

	return 0;
}