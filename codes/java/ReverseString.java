import java.util.Scanner;
/**
 * To reverse a string by reducing the loops
 *
 * @author Pritam Dash
 */
class ReverseString
{
    /**
     * Main method
     *
     * @param args Command line arguments
     */
    public static void main(String args[])
    {
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter a word: ");
        String s=sc.nextLine();
        int len=s.length();
        String s1="",s2="";
        for(int i=0, j=len-1; i<len/2; i++, j--)
        {
            s1=s.charAt(i)+s1;
            s2+=s.charAt(j);
        }
        if(len%2==0)
        System.out.println("Reverse string:"+s2+s1);
        else
        System.out.println("Reverse string:"+s2+s.charAt(len/2)+s1);
    }
}        