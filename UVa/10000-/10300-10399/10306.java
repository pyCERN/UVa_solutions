// UVa 10306 - e-Coins
import java.io.*;
import java.util.*;



class Main{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] s = br.readLine().split(" ");
        int n = Integer.parseInt(s[0]), target = Integer.parseInt(s[1]);
        List<List<Integer>> vec = new ArrayList<>();

        for(int i = 0; i < n; i++){
            List<Integer> tmp = new ArrayList<>();
            s = br.readLine().split(" ");
            tmp.add(Integer.parseInt(s[0])); tmp.add(Integer.parseInt(s[1]));
            vec.add(tmp);
        }
    }
}