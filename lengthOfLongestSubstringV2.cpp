#define NO_OF_CHARS 256

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int idStart, idEnd, maxCount;
        idStart = 0;
        idEnd = 0;
        maxCount = 0;
    
        int dict[NO_OF_CHARS];
        for (int i = 0; i < NO_OF_CHARS; i++)
            dict[i] = -1;
    
        idEnd = idStart;
        while (idStart < s.length() && idEnd < s.length())
        {
            while (idEnd < s.length() && (dict[s[idEnd]] == -1 || dict[s[idEnd]] < idStart))
            {
                dict[s[idEnd]] = idEnd;
                idEnd++;
            }
        
            // cout << idStart << " " << idEnd << endl;
        
            if (idEnd - idStart > maxCount)
                maxCount = idEnd - idStart;
            
            if (idEnd < s.length())
            {
                int temp = dict[s[idEnd]];
            
                dict[s[idEnd]] = idEnd;
                idStart = temp+1;
                idEnd++;
            }
        }
        
        return maxCount;
    }
};