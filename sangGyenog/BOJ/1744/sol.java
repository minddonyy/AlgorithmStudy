/**
 * 02:52
 * 길이가 N인 수열이 주어짐 그 수열의 합을 구하려고 함
 * 수열의 두 수를 묶음, 위치에 상관없이 묶기 가능
 * 같은위치에 있는 자기자신은 묶는 건 불가
 * 그리고 어떤 수를 묶게되면 수열의 합을 구할 때 묶은 수는 서로 곱한 후 묶음
 * 수열의 모든 수는 한번만 묶거나 안 묶어야 함
 * 이 방식을 사용해 최대가 되는 수 출력
 *
 * 입력
 * 수열의 크기 N < 50
 * N개의 줄에 수열의 각 수가 주어짐
 * 수열의 수는 -1000 <= 수 <= 10000
 */

import java.io.*;
import java.util.*;
public class java250801_1744 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine().trim());
        int[] negative = new int[N]; //음수 저장용
        int[] positive = new int[N]; // 2이상 저장용
        int[] one = new int[N]; //1 저장용

        int negativeIdx = 0; //음수개수
        int oneIdx = 0; //1개수
        int zeroIdx = 0; //0개수
        int positiveIdx = 0; //2이상 개수

        //입력받기
        for(int tc = 0;tc < N;tc++){
            int now = Integer.parseInt(br.readLine().trim());

            if(now > 1){
                positive[positiveIdx] = now;
                positiveIdx++;
            }else if(now == 0){
                zeroIdx++;
            }else if(now == 1){
                one[oneIdx] = now;
                oneIdx++;
            }else{
                negative[negativeIdx] = now;
                negativeIdx++;
            }
        }

        int allNum = 0; // 최종 큰 수 출력변수
        // 정렬해준다(숫자가 있는 곳까지만)
        Arrays.sort(positive, 0, positiveIdx);
        Arrays.sort(negative, 0, negativeIdx);

        //2이상은 짝수개일 떈 큰 수 부터 2개씩 묶어 합산
        //홀수 개는 큰 수부터 두 개 씩 묶고 1개는 더해주기
        if((positiveIdx > 0) && (positiveIdx % 2 == 0)){ //짝수 개일 때
            for (int i = positiveIdx-1; i > 0; i -= 2) {
                allNum += positive[i] * positive[i - 1];
            }
        }else if(positiveIdx > 0){ //홀수 개일 때
            if (positiveIdx > 1) {
                for (int i = positiveIdx-1; i > 0; i -= 2) {
                    allNum += positive[i] * positive[i - 1];
                }
                allNum += positive[0];
            }else{ // 한 개일 때
                allNum += positive[0];
            }
        }

        //1은 곱하는 것보다 더하는 게 이득이다
        for(int i = 0;i < oneIdx;i++){
            if(one[i] == 0) break;
            allNum += one[i];
        }

        //음수는 짝수개면 서로 곱해서 합산
        if((negativeIdx > 1) && (negativeIdx % 2 == 0)){
            for (int i = 0; i < negativeIdx -1; i += 2) {
                allNum += negative[i] * negative[i+1];
            }
        }else if(negativeIdx > 0){
            //홀수 개면 짝수 개 끼리는 곱한 후 합산
            // 마지막은 0이 있으면 0이랑 곱하고 -> 사실상 0이라 그냥 계산 패스
            // 0이 없으면 그냥 더하기
            if (negativeIdx > 1) {
                for (int i = 0; i < negativeIdx-1; i += 2) {
                    allNum += negative[i] * negative[i + 1];
                }
            }

            if(zeroIdx == 0){
                allNum += negative[negativeIdx-1];
            }

        }

        System.out.println(allNum);
        br.close();
    }
}
