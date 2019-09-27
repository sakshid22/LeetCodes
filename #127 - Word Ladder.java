//127 - Word Ladder.java

import javafx.util.Pair;

class Solution {
    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
        
        int L = beginWord.length(); // all words of same lenth
        HashMap <String, ArrayList<String>> allComboDict = new HashMap <String, ArrayList <String>>();
        wordList.forEach(
        word -> 
        {
             for(int i =0; i<L ; i++)   //Enter generic word
                                        // value is a list of words which have same intermediate generic word
            {
              String newWord = word.substring(0,i) + '*' + word.substring(i+1, L);
              ArrayList<String> transformations = allComboDict.getOrDefault(newWord, new ArrayList<String>());
              transformations.add(word);
              allComboDict.put(newWord, transformations);
            }
        });
        
        //Queue for BFS
        Queue <Pair<String, Integer>> Q = new LinkedList<Pair<String, Integer>>();
        Q.add(new Pair(beginWord,1));
        
        //Visited to make sure we don't repeat processing word
        HashMap<String, Boolean> visited = new HashMap<String, Boolean>();
        visited.put(beginWord, true);
        
        while(!Q.isEmpty())
        {
        Pair<String, Integer> node = Q.remove();
        String word = node.getKey();
        int level = node.getValue();
        for(int i =0; i<L ; i++)
        {
        //Intermediate words for current word
        String newWord = word.substring(0,i) + '*' + word.substring(i+1, L);
        
        // Next states are all words which shrae the same intermediate state
        for (String adjacentWord: allComboDict.getOrDefault(newWord, new ArrayList<String>()))
        {
            if(adjacentWord.equals(endWord)) return level+1;
            if (!visited.containsKey(adjacentWord))
            {
             visited.put(adjacentWord, true);
             Q.add( new Pair(adjacentWord, level + 1));
             }
        }
        }
    }
    return 0;
}
}