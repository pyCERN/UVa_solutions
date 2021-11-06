// UVa 787 - Maximum Sub-sequence Product
import java.util.Scanner;
import java.math.BigInteger;

class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        BigInteger[] seq = new BigInteger[105];
        int len = 0;

        while(sc.hasNext()){
            BigInteger n = sc.nextBigInteger();

            if(n.compareTo(BigInteger.valueOf(-999999)) == 0){
                BigInteger ans = n;
                for(int i = 0; i < len; i++){
                    BigInteger prod = BigInteger.ONE;
                    for(int j = i; j < len; j++){
                        prod = prod.multiply(seq[j]);
                        if(ans.compareTo(prod) == -1) ans = prod;
                    }
                }
                System.out.println(ans);
                len = 0;
            }
            else{
                seq[len++] = n;
            }
        }
    }
}
