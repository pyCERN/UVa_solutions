// UVa 674 - Coin Change
// DP (coin change)
import java.io.*;

class Result{
    public static Integer[] DP = new Integer[7500];

    public static void wayOfChange(int target){
        Integer[] coins = {1, 5, 10, 25, 50};
        
        for(int i = 0; i < 5; i++){
                for(int v = 0; v <= target; v++){
                if(v >= coins[i]) DP[v] += DP[v-coins[i]];
            }
        }
    }
}

class Main{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = null;

        for(int i = 0; i < 7500; i++) Result.DP[i] = 0;
        Result.DP[0] = 1;
        Result.wayOfChange(7489);
        
        while((s = br.readLine()) != null){
            int target = Integer.parseInt(s);
            System.out.printf("%d\n", Result.DP[target]);
        }
    }
}