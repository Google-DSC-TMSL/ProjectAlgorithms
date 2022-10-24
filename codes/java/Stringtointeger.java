import java.io.*;
public class ConvertStringToInteger {  
    public static void main(String[] args) {  
        //1st way  
        String str1 = "5";  
        int result = Integer.parseInt(str1); // Using Integer.parsrInt()  
        System.out.println(result);  
   
        //2nd way  
        String str2 = "123";  
        Integer result2 = Integer.valueOf(str2); // Using Integer.valueOf()  
        System.out.println(result2);  
        
    }  
}  
