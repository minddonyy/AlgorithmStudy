/**
 * 01:18
 * N개의 수가 주어졌을 때 내림차순으로 정렬
 * 입력
 * 수의 개수 N
 * N개의 줄에 걸쳐 숫자가 주어짐
 * 1<= N <= 1000000
 */

import java.io.*;
import java.util.*;
public class java250731_11931 {

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        StringBuilder sb = new StringBuilder();
        int N = Integer.parseInt(st.nextToken());
        int[] num = new int[N];
        for(int tc = 0;tc < N;tc++){
            st = new StringTokenizer(br.readLine());
            num[tc] = Integer.parseInt(st.nextToken());
        }

        Arrays.sort(num); //정렬

        //반대로 출력
        for(int n=N-1;n>=0;n--){
            sb.append(num[n]).append("\n");
        }
        System.out.println(sb);
        br.close();
    }
}