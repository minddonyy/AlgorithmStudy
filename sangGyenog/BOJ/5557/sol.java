/** 02:22
 * 숫자열에서 마지막 두 숫자 사이에 =을 넣고
 * 나머지에 +, -를 넣어 등식만들기
 * 왼쪽부터 계산 식이 0이상 20이하, 출력도 포함
 * 만들 수 있는 올바른 등식 개수 출력
 *
 * 입력
 * 숫자의 개수 N
 * 0이상 9이하 정수 N개
 */

import java.util.*;
import java.io.*;
public class java250806_5557 {
    static int N = 0;

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        int[] num = new int[N];
        for(int i = 0 ; i < N;i++){
            num[i] = Integer.parseInt(st.nextToken());
        }

        long[][] dp = new long[N][21]; //2차원으로 선언해주며 [i][j] i번째 숫자까지 계산을 마침
                                    //i번째 숫자까지 계산했을 때 j인 경우의 수를 삽입, 2^63-1 이하라서 long으로 선언..
        dp[0][num[0]] = 1L;

        for(int i = 1; i < N - 1;i++){ //마지막은 연산 후 나와야할 숫자니까 N-1전 까지
            for (int j = 0;j <= 20;j++){ //0이상 20이하의 숫자만 나와야 함
                if(dp[i-1][j] != 0){ //이전 계산 값이 하나라도 있어야 진행
                    int add = j + num[i];
                    int sub = j - num[i];
                    if(add >= 0 && add <= 20) dp[i][add] += dp[i-1][j];
                    if(sub >= 0 && sub <= 20) dp[i][sub] += dp[i-1][j];
                }
            }
        }

        System.out.println(dp[N-2][num[N-1]]);
        br.close();
    }
}
