class Solution {
    int finalans = 0;
    public int maxLength(List<String> arr) {
        // try brute force
        // get every match and calculate max
        // also check that the string that we are choosing, itself has unqiue chars or not
        combis(0, arr, new HashSet<Character>());
        return finalans;
    }
    private void combis(int ind, List<String> arr, HashSet<Character> curr){
        if(ind == arr.size()){
            finalans = Math.max(curr.size(), finalans); // stores the max answer
            return;
        }   
        
        char[] currindarr = arr.get(ind).toCharArray(); // converting the current string to a char array
        
        boolean hasele = false;
        
        for(char c: currindarr){ // checks if the any character in the current string is int the hashset
            if(curr.contains(c)){
                hasele = true;
                break;
            }
        }
        
        boolean reps = false; // to check for repitition in the string itself
        
        if(!hasele){ // if there is a element in the current hashmap, then i will not take it. 
            for(char c: currindarr){ // adds the chars to the hashmap
                if(curr.contains(c)){ // checks if there is repition in the string itself
                    reps = true;
                }
                curr.add(c);
            }
            
            if(!reps) combis(ind+1, arr, curr); // taking the string if there is no repitiion
            
            for(char c: currindarr){//removes the taken chars from the hashmap
                curr.remove(c);
            }
        }
        combis(ind+1, arr, curr); // not taking the current index and moving on
    }
}