import java.io.BufferedReader;
import java.io.InputStreamReader;

public class reversebinary{
    public static void main(String[] args){
        BufferedReader bi = new BufferedReader(new InputStreamReader(System.in)); // get the input

        try{
        	int N = Integer.parseInt(bi.readLine()); // gets the input N

            String originalBinary = Integer.toString(N, 2); // convert N to binary

            StringBuilder tmpBinary = new StringBuilder();
            tmpBinary.append(originalBinary);

            System.out.println(Integer.parseInt(tmpBinary.reverse().toString(),2)); //reverse the binary then convert back to decinmal using parseInt

        } 
		catch(Exception e){
            e.printStackTrace();
        }
    }
}