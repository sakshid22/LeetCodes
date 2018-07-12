// #212
class Solution {
    
    class Trie{
    public: 
        Trie *children[26];
        bool leaf;
        int idx;
        Trie()
        {
            this->leaf = false;
            this->idx =0;
            fill_n(this->children, 26, nullptr);
        }
    };
    
public:
    void insertWords(Trie *root, vector<string>& words, int idx)
    {
        int pos =0, len =words[idx].size();
        while(pos<len)
        {
            if(nullptr == root->children[words[idx][pos]-'a'])
                root->children[words[idx][pos] -'a'] = new Trie();
            root = root->children[words[idx][pos++]-'a'];
         }
        root->leaf = true;
        root->idx = idx;
    }
    
    Trie *buildTrie(vector <string>& words)
    {
        Trie *root = new Trie();
        int i;
        for(i=0; i<words.size();i++)
            insertWords(root, words, i);
        return root;
    }
    
    void checkWords(vector<vector<char>>& board, int i, int j, int row, int col, Trie *root, vector<string> &res, vector<string> &words)
    {
        char temp;
        if(board[i][j] =='x') return;
        if(nullptr == root->children[board[i][j] - 'a']) return;
        else
        {
            temp = board[i][j];
            if(root ->children[temp-'a'] ->leaf)
            {
                res.push_back(words[root->children[temp -'a']->idx]);
                root->children[temp-'a']->leaf = false;
            }
            board[i][j]='x';
            //chk all possible neighbours
            if(i>0)
                checkWords(board,i-1,j, row,col,root->children[temp -'a'], res, words);
            if((i+1)<row)
                checkWords(board, i+1, j, row, col, root->children[temp -'a'], res, words);
            if(j>0)
                checkWords(board, i, j-1, row, col, root->children[temp -'a'], res, words);
            if((j+1)<col)
                checkWords(board,i, j+1, row, col, root->children[temp-'a'], res, words);
            board[i][j]= temp;
        }
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
      
        vector<string> res;
        int row = board.size();
        if(row==0)
            return res;
        int col = board[0].size();
        if(col==0)
            return res;
        int wordCount = words.size();
        if(wordCount==0)
            return res;
        
        Trie *root = buildTrie(words);
        int i,j;
        for(i=0;i<row;i++)
        {
            for(j=0;j<col && wordCount >res.size(); j++)
            {
                checkWords(board,i,j,row,col,root, res, words);
            }
        }
        return res;
    }
};