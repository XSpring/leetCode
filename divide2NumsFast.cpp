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

        vector<int> multipliersA;
        vector<int> power2A;

        multipliersA.push_back(divisor);        
        power2A.push_back(-1);   

        for (int j = 1; j < i; j++)
        {
            cout << multipliers[j-1] << " " << multipliers[j] << endl;

            multipliersA.push_back(multipliers[j]);
            power2A.push_back(power2[j]);

            multipliersA.push_back(multipliers[j] + multipliers[j-1]);
            power2A.push_back(power2[j] + power2[j-1]);
        }

        i = power2A.size() - 1;
        // cout << i << " " << power2[i] << endl;

        while (dividend < 0 && i > -1)                     
        {            
            while (dividend <= multipliersA[i])
            {
                cout << dividend << " " << count << " " << multipliersA[i] << endl;
                count += power2A[i];
                dividend -= multipliersA[i];
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
    int b = 3;

    cout << divide(a, b) << endl;
}
