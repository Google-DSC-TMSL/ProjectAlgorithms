import java.io.*;
public class Stringtointeger {
        // Function to convert String to integer
        public static int convert(String str)
        {
            int val = 0;
            System.out.println("String = " + str);

            // Convert the String
            try {
                val = Integer.parseInt(str);
            }
            catch (NumberFormatException e) {

                // This is thrown when the String
                // contains characters other than digits
                System.out.println("Invalid String");
            }
            return val;
        }

        // Driver code
        public static void main(String[] args)
        {

            String str = "1234";
            int val = convert(str);
            System.out.println("Integer value = " + val);
            System.out.println();

            str = "123s";
            val = convert(str);
            System.out.println("Integer value = " + val);
        }
    }
