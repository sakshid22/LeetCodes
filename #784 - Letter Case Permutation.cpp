//784

class Solution {
public:
    
    char switchcase( const char& c)
    {
        if(c>='A' && c<='Z')
          return tolower(c);
        else
           return toupper(c);
    }
    
    vector <string> letterCasePermutation(string S) 
    {
    vector <string> strings;
        strings.push_back(S);
        for(int i=0; i<S.length(); i++)
        {
            if(isalpha(S[i]))
               {
                   int stop=strings.size();
                   for(int j=0; j<stop;j++)
                   {
                       string S = strings[j];
                       S[i] = switchcase(S[i]);
                       strings.push_back(S);
                   }
               }
               
        }
        return strings;  
  }
    
};