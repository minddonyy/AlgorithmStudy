/**
 * 01:13
 * 세 대각선이 한점에서 만나지 않는 볼록 N각형(모든 내부각이 180도 보다 작음)
 * 대각선 교차점의 개수세서 출력
 */

import java.util.*;
import java.io.*;
public class java250722_3049 {

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        System.out.println(N * (N - 1) * (N - 2) * (N - 3) / 24);
    }

}
