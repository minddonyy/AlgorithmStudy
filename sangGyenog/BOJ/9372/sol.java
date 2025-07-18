/**
 * 02:20
 * N개국을 여행하는데 가장 적은 종류의 비행기를 타고 국가를 이동
 * 이를 출력
 * 다른 국가를 거쳐가도 이미 방문한 곳이어도 됨
 *
 * 입력
 * 테케 수 T
 * 국가의 수N, 비행기 종류 M
 * M개의 줄에 a, b의 쌍이 입력
 * a와 b를 왕복하는 비행기가 있다는 것을 의미
 * 항상 연결 그래프를 이룸
 *
 * 출력
 * 테스트 케이스마다 한 줄을 출력
 * 모든 국가를 여행하기 위해 타야하는 비행기 종류의 최소 개수
 */
import java.io.*;
import java.util.*;
public class java250718_9372 {
    static int rst = 0;
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int T = Integer.parseInt(st.nextToken());

        for(int tc=0;tc<T;tc++){
            st = new StringTokenizer(br.readLine());
            int N = Integer.parseInt(st.nextToken()), M = Integer.parseInt(st.nextToken());
            HashMap<Integer, List<Integer>> map = new HashMap<>(); //국가별 연결리스트 생성용

            int[] worldPass = new int[N+1]; //방문여부 확인
            rst = 0;

            for(int i=0;i<=N;i++) map.put(i, new ArrayList<>());    //null-> 빈 칸으로 채우기

            //양방향 연결 맵 생성
            for(int info=0;info<M;info++){
                st = new StringTokenizer(br.readLine());
                int a = Integer.parseInt(st.nextToken()), b = Integer.parseInt(st.nextToken());

                map.get(a).add(b);
                map.get(b).add(a);
            }

            search(1, map, worldPass);//1번국가부터 연결탐색시작
            System.out.println(rst);
        }

        br.close();
    }

    static void search(int wor, HashMap<Integer, List<Integer>> map, int[] worldPass){
        worldPass[wor] = 1;
        //한 국가를 시작으로 연결된 국가 모두 돌아본다
        for(Integer num : map.get(wor)){
            if(worldPass[num] == 1) continue;
            rst++;
            search(num, map, worldPass);
        }
    }

}
