import java.util.*;
class ParityChecker{
    String appendParityBit(String data) {
        int numberOfOnes = 0;
        for(int i = 0; i < data.length(); i++) {
            if(data.charAt(i) == '1') numberOfOnes += 1;
        }
        String dataWithParityBit;
        if(numberOfOnes % 2 == 0) {
            dataWithParityBit = data + "0";
        } else {
            dataWithParityBit = data + "1";
        }
    return dataWithParityBit;
    }
    String checkCorrect(String dataWithParityBit) {
        int receivedParity = 0;
        for(int i = 0; i < dataWithParityBit.length(); i++) {
            if(dataWithParityBit.charAt(i) == '1') receivedParity += 1;
        }
        if(receivedParity % 2 == 0) return "No error detected";
        else return "Error detected";
    }
}

public class ParityCheck {
    public static void main(String[] args) {
        ParityChecker p = new ParityChecker();
        Scanner s = new Scanner(System.in);
        System.out.println("Enter sender data: ");
        String senderData = s.nextLine();
        System.out.println("Generated data with parity : " + p.appendParityBit(senderData));
        System.out.println("Enter received data: ");
        String receiverData = s.nextLine();
        System.out.println(p.checkCorrect(receiverData));
    }
}