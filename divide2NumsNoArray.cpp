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

        int i = 0;

        int temp = divisor;
        while (temp >= dividend - temp)
        {
            temp = divisor << i;
            count -= 1 << i;
            dividend -= temp;
            cout << temp << " " << dividend << " " << count << endl;
            i++;
        }
    
        if (i > 0) i--;
        while (dividend < 0 && i > -1)                     
        {
            while (dividend <= temp)
            {
                // cout << dividend << " " << temp << " " << count << endl;
                count -= 1 << i;
                dividend -= temp;
            }
                                    
            i--;                
            temp = divisor << i;
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
