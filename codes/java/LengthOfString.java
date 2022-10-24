import java.util.Scanner;
/**
 * Prints the length of any string without using length() function
 *
 * @author Pritam Dash
 */

class LengthOfString
{
    /**
     * Main method
     *
     * @param args Command line arguments
     */
    
    public static void main(String args[])
    {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter a string:");
        String st=sc.nextLine();
        st=st+"\0";
        char ch[]=st.toCharArray();
        int c=0;
        for(int i=0; ch[i]!='\0'; i++)
            c++;
        System.out.println("\nThe length of the string is "+c);
        sc.close();
    }
}