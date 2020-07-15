/*

PROBLEM STATEMENT : 


Given an input string, reverse the string word by word.

 

Example 1:

Input: "the sky is blue"
Output: "blue is sky the"
Example 2:

Input: "  hello world!  "
Output: "world! hello"
Explanation: Your reversed string should not contain leading or trailing spaces.
Example 3:

Input: "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.
 

Note:

A word is defined as a sequence of non-space characters.
Input string may contain leading or trailing spaces. However, your reversed string should not contain leading or trailing spaces.
You need to reduce multiple spaces between two words to a single space in the reversed string.
 

Follow up:

For C programmers, try to solve it in-place in O(1) extra space.


*/
class Solution {
public:
    string reverseWords(string s) {
        string result ; 
        int i=0 ; //For Keeping Track of The Starting Indices of a String
         
        int N = s.length();
        
       while(i < N){
           while(i < N && s[i] == ' '){
               i++ ; 
           }
           if(i >= N) break ; //Now , My Main Question to Ponder Over is why did we apply this Condition
          int j=i+1 ; 
            while(j < N && s[j] != ' '){
                j++ ; 
            }
           string word = s.substr(i , j-i);
           if(result.length() == 0) result = word ; 
           else result = word + " " + result ; 
           i=j+1 ; 
           
       }
        return result ; 
        
    }
};