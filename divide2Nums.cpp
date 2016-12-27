#include <iostream>
#include <limits.h>
#include <cmath>
#include <vector>

using namespace std;

    int divideAbs(int dividend, int divisor) 
    {
        if (dividend > 0)
            dividend = -dividend;
        if (divisor > 0)
            divisor = -divisor;

        int count = 0;

        vector<int> multipliers;
        vector<int> power2;

        int i = 0;

        multipliers.push_back(divisor);        
        power2.push_back(-1);   

        while (multipliers[i] > dividend - multipliers[i])
        {                
            multipliers.push_back(multipliers[i] + multipliers[i]);
            power2.push_back(power2[i] + power2[i]);
            i++;
        }

        // cout << i << " " << power2[i] << endl;

        while (dividend < 0 && i > -1)                     
        {
            while (dividend <= multipliers[i])
            {
                count += power2[i];
                dividend -= multipliers[i];
            }
                                    
            i--;                    
        }

        return count;
    }

    int divide(int dividend, int divisor) 
    {
        if (divisor == dividend)
            return 1;

        // divisor = INT_MIN, -1, 0, 1, MAX_INT
        if (divisor == 1)
            return dividend;

        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;
    
        if (dividend > INT_MIN && divisor == -1)
            return -dividend;

        if (divisor == INT_MIN)
        {
            return 0;
        }

        if (divisor == INT_MAX)
        {
            if (dividend <= -INT_MAX)
                return -1;

            return 0;
        }

        if ((dividend < 0 && divisor < 0) || (dividend > 0 && divisor > 0))
        {
            return -divideAbs(dividend, divisor);
        } 

        return divideAbs(dividend, divisor);
    }
    
int main()
{
    int a = INT_MAX;
    int b = INT_MIN;

    cout << divide(a, b) << endl;
}
