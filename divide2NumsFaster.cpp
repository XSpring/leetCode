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

        int multipliers[32];
        int power2[32];

        int i = 0;

        multipliers[i] = divisor;        
        power2[i] = -1;   

        while (multipliers[i] > dividend - multipliers[i])
        {                
            multipliers[i+1] = multipliers[i] + multipliers[i];
            power2[i+1] = power2[i] + power2[i];
            /** This is the trick to get it faster **/
            count += power2[i];
            dividend -= multipliers[i];
            i++;
        }

        // cout << i << " " << power2[i] << endl;

        while (dividend < 0 && i > -1)                     
        {
            while (dividend <= multipliers[i])
            {
                // cout << dividend << " " << multipliers[i] << " " << count << " " << power2[i] << endl;
                count += power2[i];
                dividend -= multipliers[i];
            }
                                    
            i--;                    
        }

        return count;
    }

    int divide(int dividend, int divisor) 
    {
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        if (divisor == 1)
            return dividend;
            
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
