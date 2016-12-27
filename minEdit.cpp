#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int min2(int a, int b)
{
	return a < b ? a : b;
}

int min3(int a, int b, int c)
{
	return min2(min2(a, b), c);
}

int main() {
	string s1, s2;
	s1 = "sunday";
	s2 = "saturday";

	int dp[s1.length()+1][s2.length()+1];
	for (int x = 0; x <= s1.length(); x++)
		dp[x][0] = x;

	for (int y = 0; y <= s2.length(); y++)
		dp[0][y] = y;

	for (int x = 1; x <= s1.length(); x++)
		for (int y = 1; y <= s2.length(); y++) {
			if (s1[x-1]==s2[y-1])
				dp[x][y] = dp[x-1][y-1];
			else {
				dp[x][y] = min3(1 + dp[x-1][y-1],
								1 + dp[x-1][y],
								1 + dp[x][y-1]);
			}
		}

	cout << dp[s1.length()][s2.length()] << endl;;
	return 0;
}