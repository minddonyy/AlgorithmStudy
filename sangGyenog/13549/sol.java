/**
 * 02:08
 * 수빈이는 현재 점  0 <= N <= 100000에 있고
 * 동생은 점 0 <= K <= 100000에 있음
 * 수빈이는 걷거나 순간이동 가능
 *
 * 수빈이의 위치가 X일때
 * 걷는다면 1초 후 x-1, x+1로 이동
 * 순간이동 시 0초 후 X*2위치로 이동
 * 수빈이와 동생위치가 주어질 때 수빈이가 동생을 찾을 수 있는 가장 빠른 시간은 몇 초인지 출력
 *
 * 입력
 * 수빈이가 있는 위치 N, 동생이 있는 위치 K
 *
 *
 */

import java.io.*;
import java.util.*;
public class java250809_13549 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken()), K = Integer.parseInt(st.nextToken());
        PriorityQueue<int[]> q = new PriorityQueue<>((a, b) -> a[1] - b[1]);
        int[] visited = new int[100001];
        Arrays.fill(visited, Integer.MAX_VALUE); //방문처리를 위치값에 시간을 넣을예정, 먼저 가장 큰 숫자 삽입

        q.add(new int[]{N, 0}); //현재 수빈위치, 누적시간

        visited[N] = 0; //처음 방문처리
        int rst = 0;

        while (!q.isEmpty()) {
            int[] qList = q.poll();
            int nowThis = qList[0], nowTime = qList[1];
            if (nowThis == K) { //도착 시 중단
                rst = nowTime;
                break;
            }
            if (visited[nowThis] > nowTime) continue; //현재 시간이 누적시간 보다 작으면 패스

            //이동 시 현재 시간보다 큰 경우만 (방문하지 않았을 때만) 방문처리

            if(nowThis*2 <= 100000 && nowTime < visited[nowThis*2]){ //순간이동
                visited[nowThis*2] = nowTime;
                q.add(new int[]{nowThis*2, nowTime});
            }

            if(nowThis+1 <= 100000 && nowTime + 1 < visited[nowThis+1]){ //앞으로 한 칸 이동
                visited[nowThis+1] = nowTime +1 ;
                q.add(new int[]{nowThis+1, nowTime+1});
            }

            if (nowThis-1 >= 0 && nowTime+1 <  visited[nowThis-1]) {//뒤로 한칸이동
                visited[nowThis - 1] = nowTime+1;
                q.add(new int[]{nowThis - 1, nowTime + 1});
            }

        }

        System.out.println(rst);
        br.close();

    }
}
