/**
 * 01:27
 * 두 문자열이 주어질 때 두 문자열에 모두 포함된 가장 긴 공통 부분 문자열의 길이 출력
 * 연속적인 문자열만 인정
 * 없으면 0 출력
 */
package algo;

import java.io.*;
import java.util.*;

public class s250807_5582 {

	public static void main(String[] args)throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] a = br.readLine().split("");
		String[] b = br.readLine().split("");
		int aNum = a.length;
		int bNum = b.length;
		
		int[][] dp = new int[aNum][bNum];
		int cnt = 0;
		
		//문자열을 순회하며 같은지 확인
		for(int i = 0; i < aNum;i++) {
			for(int j = 0; j < bNum;j++) {
				if(a[i].equals(b[j])) {
					if(i > 0 && j > 0) //왼 대각선+1 하면 같은 문자열의 수가 누적된다 
						dp[i][j] = dp[i-1][j-1] + 1;
					else //아니라면 그냥 같은 문자열을 찾았으니 +1
						dp[i][j] += 1;
				}
				cnt = Math.max(cnt, dp[i][j]); //문자열 길이 최댓값 갱신
			}
		}
		
		System.out.println(cnt);
		
		br.close();
	}
}