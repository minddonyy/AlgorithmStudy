/**
 * 02:18
 * 수행해야할 작업 N개, 각각의 작업마다 걸리는 시간이 정수로 주어짐
 * 어떤 작업을 수행하기 위해 반드시 먼저 완료되어야 할 작업들이 있음
 * 이 작업은 번호가 매겨져 있고, K번 작업에 대해 선행관계에 있는(k번 작업을 시작하기 전
 * 반드시 먼저 완료되어야 하는) 작업들의 번호는 모두 1이상 (k-1)이하여야 함
 * 작업들 중 그것에 대해 선행관계에 있는 작업이 하나도 없는 작업이 반드시 하나 이상 존재
 * 모든 작업을 완료하기 위해 필요한 최소시간을 출력
 * 서로 선행관계가 없는 작업은 동시 수행가능
 *
 * 입력
 * N
 * N개의 줄에걸쳐 N번 작업의 시간, 선행관계에 있는 작업수, 선행관계에 있는 작업 번호
 *
 */

import java.io.*;
import java.util.*;
public class java250728_2056 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());

        int[] time = new int[N+1]; //작업시간
        int[] inDegree = new int[N+1]; //선행 작업 개수
        int[] dp = new int[N+1]; //작업 최소 완료 시간
        ArrayList<Integer>[] graph = new ArrayList[N+1]; //각 노드에서 다음 노드들을 저장

        for(int i=1;i <= N;i++) graph[i] = new ArrayList<>();

        for(int tc = 1;tc <= N;tc++){
            st = new StringTokenizer(br.readLine());
            time[tc] = Integer.parseInt(st.nextToken());
            int beforeCnt = Integer.parseInt(st.nextToken());

            for(int bc = 1;bc <= beforeCnt;bc++){
                int before = Integer.parseInt(st.nextToken());

                //before작업 완료된 후 tc작업이 가능
                // 그래프에 before -> tc방향 간선을 삽입
                graph[before].add(tc);

                //tc의 선행작업 수 1증가
                inDegree[tc]++;
            }
        }

        //큐를 이용한 위상정렬 시작
        Queue<Integer> q = new LinkedList<>();
        for(int i = 1;i<=N;i++){
            //선행작업이 없는 경우
            if(inDegree[i] == 0){
                dp[i] = time[i];
                q.offer(i);
            }
        }

        //위상 정렬 수행
        while(!q.isEmpty()){
            int now = q.poll();
            //now작업의 다음 작업 확인
            for(int next : graph[now]){
                //now가 끝나야 next작업이 가능하므로 선행작업 완료 체크
                inDegree[next] --;

                //next작업을 완료하는 최소시간계산
                //현재 저장된 최소 완료 시간과 now작업 완료 후 next작업 시간을 고려한
                //시간 중 최대 값
                dp[next] = Math.max(dp[next], dp[now] + time[next]);

                // 다음 작업의 모든 선행 작업이 완료되면 큐에 추가
                if(inDegree[next] == 0) q.offer(next);
            }
        }

        //모든 작업 완료 시간을 가지고 가장 오래 걸리는 작업 시간을 출력
        int answer = 0;
        for(int i = 1;i<= N;i++){
            answer = Math.max(answer, dp[i]);
        }
        System.out.println(answer);
    }
}
