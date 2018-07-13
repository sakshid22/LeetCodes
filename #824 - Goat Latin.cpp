//#824
class Solution {
/*
    public:
    string toGoatLatin(string S) {
      
        
stringstream ss(S);
string curr;
string res ="" ;
unordered_set<char> vowels ={ 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'O', 'I', 'U'};
    for(int i=0; ss>>curr; i++)
    {
        if (curr.length()<1)
        continue;
        if(vowels.count(curr[0]==0))
        {
        char first = curr[0];
        curr = curr.substr(1);
        curr.push_back(first);
        }
        
       
    curr.push_back('m');
        for(int j=0;j<=i+1; j++)
        curr.push_back('a');
        if(res.length()==0)
res = curr;
else    
res = res + " "+ curr;
}
return res;
}

*/
        
 // 2nd Solution
private:
        bool isVowel(char c)
        {
            c = tolower(c);
            return (c=='a'||c=='e'||c =='o' || c=='i' ||c=='u');
        }
public:
        string toGoatLatin(string S)
        {
            string result;
            string append ="maa", w;
            istringstream line(S);
            while(line>>w)
            {
                if(!isVowel(w[0]))
                {
                    w+=w[0];
                    w.erase(0,1);
                }
                w+=append;
                
                result += w+ " ";
                append += 'a';
                
            }
        result.erase(result.size()-1, 1);
           return result; 
        }
    
};