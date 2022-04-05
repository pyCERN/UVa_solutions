// UVa 10306 - e-Coins
// DP (coin change) or BFS
import java.io.*;
import java.util.*;

class Pair{
    int row, col;
    Pair(int row, int col){
        this.row = row;
        this.col = col;
    }
}

class Result{
    public static Integer[][][] DP = new Integer[41][301][301];

    public static int wayOfMove(List<List<Integer>> vecs, int target, int x, int y, int i){
        int x2y2 = x*x + y*y;

        if(x2y2 == target*target) return 0;
        if(x2y2 > target*target || i < 0) return 100000;
        if(DP[i][x][y] != 0) return DP[i][x][y];
        
        List<Integer> vec = vecs.get(i);
        int dx = vec.get(0), dy = vec.get(1);
        DP[i][x][y] = Math.min(1 + wayOfMove(vecs, target, x+dx, y+dy, i), wayOfMove(vecs, target, x, y, i-1));

        return DP[i][x][y];
    }

    public static int bfs(List<List<Integer>> vecs, int target){
        Integer[][] dist = new Integer[target+1][target+1];
        Queue<Pair> q = new LinkedList<>();
        
        for(var d: dist) Arrays.fill(d, 100000);
        dist[0][0] = 0;
        q.add(new Pair(0, 0));

        while(!q.isEmpty()){
            Pair node = q.poll();
            int r = node.row, c = node.col;

            for(int i = 0; i < vecs.size(); i++){
                List<Integer> vec = vecs.get(i);
                int dr = vec.get(0), dc = vec.get(1);
                int rr = r+dr, cc = c+dc;
                if(rr < 0 || rr >= target || cc < 0 || cc >= target) continue;

                if(dist[rr][cc] == 100000){
                    dist[rr][cc] = dist[r][c] + 1;
                    if(rr*rr + cc*cc == target*target) return dist[rr][cc];
                    q.add(new Pair(rr, cc));
                }
            }
        }
        return -1;
    }
}

class Main{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int TC = Integer.parseInt(br.readLine());

        while(TC-- > 0){
            String[] s = br.readLine().split(" ");
            int n = Integer.parseInt(s[0]), target = Integer.parseInt(s[1]);
            List<List<Integer>> vecs = new ArrayList<>();

            for(int i = 0; i < n; i++){
                List<Integer> tmp = new ArrayList<>();
                s = br.readLine().split(" ");
                tmp.add(Integer.parseInt(s[0])); tmp.add(Integer.parseInt(s[1]));
                vecs.add(tmp);
            }

            for(int i = 0; i < 41; i++){
                for(int x = 0; x < 301; x++){
                    for(int y = 0; y < 301; y++) Result.DP[i][x][y] = 0;
                }
            }
            // int ans = Result.wayOfMove(vecs, target, 0, 0, n-1);
            // if(ans == 100000) System.out.printf("not possible\n");
            // else System.out.printf("%d\n", ans);
            int ans = Result.bfs(vecs, target);
            System.out.printf("%d\n", ans);
        }
    }
}