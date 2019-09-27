
#17 - Letter combinations of a phone number

class Solution {
  
    Map <String, String> phone = new HashMap<String, String>()
    {{
         put("2","abc");
         put("3","def");
         put("4","ghi");
         put("5","jkl");
         put("6","mno");
         put("7","pqrs");
         put("8","tuv");
         put("9","wxyz");
    }};
    
    List <String> output = new ArrayList<String>();
    
    public void backtrack(String combination, String next_digits)
    {
        if(next_digits.length() == 0)    // If there is no more digits to check
            output.add(combination);     // Combination is done 
        else                             // If there are still digits to check
        {
            String digit = next_digits.substring(0,1); // Iterate over all letters which map the next available digit
            String letters = phone.get(digit);
            for(int i =0 ; i<letters.length(); i++)
            {   
                // Append the current letter to the combination and proceed to the next digits
                String letter = phone.get(digit). substring(i, i+1);
                backtrack(combination + letter, next_digits.substring(1));
            }
        }
            
    }
    
 
    public List<String> letterCombinations(String digits) {
       if(digits.length() !=0)
           backtrack("", digits);
           return output;
        
    }
}