#define NO_OF_CHARS 256

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length()==0) return 0;
        
        int idStart, idEnd, maxCount;
        idStart = 0;
        idEnd = 0;
        maxCount = 0;
    
        int dict[NO_OF_CHARS];
        for (int i = 0; i < NO_OF_CHARS; i++)
            dict[i] = -1;
    
        int is[s.length()];
        for (int i = 0; i < s.length(); i++)
            is[i] = int(s[i]);
        
       idEnd = idStart;
        dict[is[0]] = 0;
        for (idEnd = 1; idEnd < s.length(); idEnd++)
        {
            if (dict[is[idEnd]] == -1 || dict[is[idEnd]] < idStart)
            {
                dict[is[idEnd]] = idEnd;
            }
            else
            {
                if (idEnd - idStart > maxCount)
                    maxCount = idEnd - idStart;
            
                idStart = dict[is[idEnd]] + 1;
                dict[is[idEnd]] = idEnd;
            }
        }
    
        if (idEnd - idStart > maxCount)
            maxCount = idEnd - idStart;
        
        return maxCount;
    }
};