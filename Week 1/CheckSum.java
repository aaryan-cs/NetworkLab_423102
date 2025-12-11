import java.util.*;
public class CheckSum{
    
    static String sumWithWrapAround(String s1, String s2) {
        int length  = s1.length();
        int num1 = Integer.parseInt(s1,2);
        int num2 = Integer.parseInt(s2,2);
        int sum = num1 + num2;
        int max = (1 << length) - 1;
        while(sum > max) {
            int carry = sum >> length;
            sum = (sum & max) + carry;
        }
        StringBuilder result = new StringBuilder(Integer.toBinaryString(sum));
        while (result.length() < length) {
            result.insert(0, "0");
        }
        return result.toString();
    }
    static String onesComplement(String s) {
        StringBuilder sb = new StringBuilder();
        for(char c : s.toCharArray()) {
            sb.append(c == '0' ? '1' : '0');
        }
        return sb.toString();
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter word size: ");
        int wordSize = sc.nextInt();
        System.out.println("Enter number of words: ");
        int numWords = sc.nextInt();
        sc.nextLine();
        String[] words = new String[numWords];
        System.out.println("Enter the data words:");
        for(int i = 0; i < numWords; i++) {
            words[i] = sc.next();
            if(words[i].length() != wordSize) {
                System.out.println("Word length mismatch");
                return;
            }
        }
        StringBuilder zeroSb = new StringBuilder();
        for(int i = 0; i < wordSize;i++) zeroSb.append("0");
        String currentSum = zeroSb.toString();
        for(String word : words) {
            currentSum = sumWithWrapAround(currentSum, word);
        }
        String checksum = onesComplement(currentSum);
        System.out.println("--- Transmission Side ---");
        System.out.println("Checksum : " + checksum);
        System.out.println("Transmitted words: ");
        for(String word : words) {
            System.out.println(word);
        }
        System.out.println(checksum);
        System.out.println("--- Receiver Side ---");
        System.out.println("Enter received words: ");
        String[] receivedWords = new String[numWords + 1];
        String receiverSum = zeroSb.toString();
        for (int i = 0; i < numWords + 1; i++) {
            receivedWords[i] = sc.next();
            receiverSum = sumWithWrapAround(receiverSum, receivedWords[i]);
        }
        String finalComplement = onesComplement(receiverSum);
        System.out.println("--- Receiver Calculation ---");
        System.out.println("Final Sum (after adding checksum): " + receiverSum);
        System.out.println("1's Complement of result: " + finalComplement);
        boolean error = false;
        for(char c : finalComplement.toCharArray()){
            if(c != '0'){
                error = true;
                break;
            }
        }
        if (!error) {
            System.out.println("No Error: Data received correctly");
        } else {
            System.out.println("Error Detected!");
        }
        sc.close();
    }
}