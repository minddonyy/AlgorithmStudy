/**
 * 01:42
 * 벼락치기
 * 1. 여러 단원을 융합한 문제는 출제하지 않는다
 * 2. 한 단원에 한 문제를 출제, 단, 그 단원에 모든 내용을 알고 있어야 풀 수 있음
 * 힌트 두 개와 함께 각 단원별 배점을 적어놓음
 * 어떤 단원의 문제를 맞추기 위해서 그 단원의 예상 공부 시간 이상해야 맞출 수 있음
 * 남은 시간동안 공부해서 얻을 수 있는 최대점수를 출력
 *
 * 입력
 * 시험의 단원개수 N, 시험까지 남은 시간 T
 * N줄에 걸쳐 각 단원 별 예상 공부 시간, 그 단원 문제의 배점S
 *
 * 출력
 * 얻을 수 있는 최대점수
 */
import java.io.*;
import java.util.*;
public class java250717_14728 {

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken()), T = Integer.parseInt(st.nextToken());

        int[] K = new int[N+1]; //소요시간 배열
        int[] P = new int[N+1]; //배점 배열

        for(int tc = 1;tc <= N;tc++){
            st = new StringTokenizer(br.readLine());
            int stdTime = Integer.parseInt(st.nextToken()), point = Integer.parseInt(st.nextToken());
            K[tc] = stdTime;
            P[tc] = point;
        }

        int[] dp = new int[T+1]; //dp[t] t시간 안에 얻을 수 있는 최대 점수

        for(int i = 1;i<=N;i++){
            //남은 시간에서 1씩 빼면서 각 시간마다 가장 높은 점수를 갱신한다
            for(int t = T;t >= K[i];t--){
                dp[t] = Math.max(dp[t], dp[t - K[i]] + P[i]);
            }
        }

        System.out.println(dp[T]);

        br.close();
    }
}