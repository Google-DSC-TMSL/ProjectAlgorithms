//  M  - 1000
//  CM - 900
//  D  - 500 
//  CD - 400
//  C  - 100
//  XC - 90
//  L  - 50
//  XL - 40
//  X  - 10
//  IX - 9
//  V  - 5
//  IV - 4
//  I  - 1

class Solution {
    public String intToRoman(int num) {
        int[] intCode = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        String[] code = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        
        StringBuilder sb = new StringBuilder();
        for(int i = 0; i < intCode.length; i++){
            while(num >= intCode[i]){
                sb.append(code[i]);
                num-=intCode[i];
            }
        }
        return sb.toString();
    }
}