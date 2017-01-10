class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int idStart, idEnd, maxCount;
        idStart = 0;
        idEnd = 0;
        maxCount = 0;
    
        unordered_map<char, int> dict;
    
        idEnd = idStart;
        while (idStart < s.length() && idEnd < s.length())
        {
            while (idEnd < s.length() && (dict.find(s[idEnd]) == dict.end() || dict[s[idEnd]] < idStart))
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