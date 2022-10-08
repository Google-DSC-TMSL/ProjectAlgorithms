class KthBitNthBinaryString {
    public char findKthBit(int n, int k) {
        
        if(n==1){ // not n == 0
            return '0';
        }
        
        int len  = (1<<n) - 1; // since the length is 2 times the previous one in every step
        
        if(k == len/2 + 1){
            return '1';
        }
        else if(k > len/2 + 1){ // if k is more, move to the 2nd half of the string
            
            if(findKthBit(n-1, len - k +1) == '0'){ // checking the original and then returning the inverted bit
                return '1';
            }
            else{
                return '0';
            }
        }
        else if(k < len/2 + 1){ // if k is in the first half, no need to invert, just return the same bit
            return findKthBit(n-1, k);
        }
        
        return '1'; // dummy return for syntax
    }
}