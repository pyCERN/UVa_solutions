import java.io.*;
import java.util.StringTokenizer;
import java.util.Stack;

public class Main{
    public static void main(String args[]) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Stack<Integer> train = new Stack<>();

        while(true){
            int N = Integer.parseInt(br.readLine());
            if(N == 0){
                break;
            }

            while(true){
                String str = br.readLine();
                if(str.equals("0")){
                    System.out.println();
                    break;
                }
                StringTokenizer st = new StringTokenizer(str, " ");
                int orderNum = 0;
                for(int i = 0; i < N; i++){
                    int inputNum = Integer.parseInt(st.nextToken());
                    while(++orderNum < inputNum){
                        train.push(orderNum);
                    }
                    if(!train.empty() && train.peek() == inputNum) train.pop();
                }
                if(train.empty()) System.out.println("Yes");
                else{
                    System.out.println("No");
                    while(!train.empty()) train.pop();
                }
            }
        }

        br.close();
    }
}