/**
 * 02:02
 * 여러 색의 뿌요를 놓음, 중력의 영향에 따라 아래 바닥이나 다른 뿌요가 나올 때까지 아래로 떨어짐
 * 뿌요를 놓고 같은 색 뿌요가 4개 이상 상하좌우로 연결되면 한번에 없어짐 -> 1연쇄
 * 뿌요가 없어지고 위에 다른 뿌요가 있으면 아래로 차례대로 떨어짐
 * 아래로 떨어지고 다시 같은 색의 뿌요가 4개이상 모이면 터지는 방식, 내려오고 터지고를 반복 시 연쇄가 누적
 * 터질 수 있는 뿌요가 여러 그룹이 있다면 동시에 터져야 하고 여러 그룹이 터지더라도 한 번의 연쇄가 추가됨
 * 상대방 필드가 주어질 때 연쇄가 몇 번 연속으로 터지는지 출력, 없으면 0
 *
 * 입력
 * 총 12개의 줄에 걸쳐 필드가 주어짐 각 줄엔 6개의 문자가 있음
 * .은 빈공간
 * R빨, G초, B파, P보, Y노
 * 주어진 필드는 모두 아래로 떨어진 뒤 상태임
 *
 * @author SSAFY
 *
 */
import java.io.*;
import java.util.*;
public class java250813_11559 {
    static int ROW = 12;    //뿌요 세로 길이
    static int COL = 6;     // 뿌요 가로 길이
    static String[][] matrix; //현재 뿌요 현황
    static int[][] pass; //뿌요 방문 현황
    static int[] XX = {-1, 1, 0, 0}; //상하좌우 탐색 X좌표
    static int[] YY = {0, 0, -1, 1}; //상하좌우 탐색 Y좌표
    static Queue<int[]> boomQ = new LinkedList<>(); //터뜨릴 좌표를 담을 큐

    static int rst = 0; //연쇄 터뜨림 횟수
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        //뿌요 현황을 입력받는다.
        matrix = new String[ROW][COL];
        for(int i = 0;i < ROW;i++) {
            matrix[i] = br.readLine().split("");
        }

        while(true) {
            boolean boomGo = false; //터뜨릴 뿌요가 있는지 확인용
            pass = new int[ROW][COL];

            //뿌요현황을 탐색시작
            for (int i = 0; i < ROW; i++) {
                for (int j = 0; j < COL; j++) {
                    if (!matrix[i][j].equals(".")) {
                        search(i, j); //bfs를 통해 연속 4개가 되는 뿌요를 찾아 터뜨릴 대상 좌표를 추가
                        if (boomQ.size() >= 4) {
                            // 4개이상이 되면 터뜨림
                            while (!boomQ.isEmpty()) {
                                int[] boomList = boomQ.poll();
                                int boomDx = boomList[0], boomDy = boomList[1];
                                matrix[boomDx][boomDy] = "*";
                                boomGo = true;
                            }
                        }
                    }
                }
            }

            if (!boomGo) break; //터뜨릴 좌표가 없으면 중단

            //터뜨리기 시작
            boom();

            //아래로 떨어짐
            down();
            rst++; //연쇄 횟수 누적
        }

        System.out.println(rst);
        br.close();
    }

    static void search(int i, int j) {
        //bfs를 통해 연속 4개이상이 붙어있는지 확인
        if(!boomQ.isEmpty()) boomQ.clear();
        Queue<int[]> q = new LinkedList<>();
        q.add(new int[]{i, j});
        boomQ.add(new int[]{i, j});
        pass[i][j] = 1;

        while(!q.isEmpty()) {
            int[] s = q.poll();
            int x = s[0], y = s[1];

            for (int row=0;row<4;row++) {
                int dx = x + XX[row];
                int dy = y + YY[row];
                if(0 <= dx && dx < ROW && 0 <= dy && dy < COL && matrix[i][j].equals(matrix[dx][dy]) && pass[dx][dy] == 0) {
                    pass[dx][dy] = 1;
                    q.add(new int[] {dx, dy});
                    boomQ.add(new int[]{dx, dy});
                }
            }

        }
    }

    //완전 탐색하며 터뜨릴 좌표대로 터뜨리기 진행
    static void boom() {
        for(int i=0;i<ROW;i++) {
            for(int j=0;j<COL;j++) {
                if(matrix[i][j].equals("*")) {
                    matrix[i][j] = ".";
                }
            }
        }
    }

    //역순으로 뿌요들을 큐에 담아 새롭게 뿌요 현황판 재정렬 -> 중력으로 떨어뜨림
    static void down(){
        for(int i=COL-1;i>=0;i--){
            Queue<String> q = new LinkedList<>();
            for(int j=ROW-1;j>=0;j--){
                if(matrix[j][i].equals(".")) continue;
                q.add(matrix[j][i]);
            }

            for(int j=ROW-1;j>=0;j--){
                if(!q.isEmpty())
                matrix[j][i] = q.poll();
                else matrix[j][i] = ".";
            }
        }

    }
}