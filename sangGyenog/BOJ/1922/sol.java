/**
 * 02:24
 * 허브를 이용해 컴퓨터끼리 연결 모든 컴퓨터를 연결하기 위해 필요한 최소비용 출력
 *
 * 입력
 * 컴퓨터의 수 N
 * 연결할 수 있는 선의 수 M
 * M+2번째 줄까지 총 M개의 줄에 각 컴퓨터를 연결하는데 드는 비용이 주어짐
 * -> A컴퓨터 B컴퓨터 연결비용
 */

import java.io.*;
import java.util.*;
public class java250730_1922 {
    static int N = 0; //컴퓨터 대수
    static int M = 0; //간선 수
    static int[] head; //각 컴퓨터 대수(연결 확인용)
    static int[] rank; //순위

    //컴퓨터간 연결정보를 info로 구성
    static class Info implements Comparable<Info>{
        int from, to, cost;
        Info(int f, int t, int c){
            from = f;
            to = t;
            cost = c;
        }
        public int compareTo(Info i){
            return this.cost - i.cost;
        }
    }

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        M = Integer.parseInt(br.readLine());
        head = new int[N+1];
        rank = new int[N+1];
        ArrayList<Info> info = new ArrayList<>();

        //초기 값 셋팅
        for(int i=1;i<=N;i++){
            head[i] = i;
            rank[i] = 0;
        }

        //입력받기
        for(int tc = 0;tc < M;tc++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken()), b = Integer.parseInt(st.nextToken()), pay = Integer.parseInt(st.nextToken());

            info.add(new Info(a, b, pay));
        }

        Collections.sort(info); //비용 오름차순으로 정렬(compareTo에 위임)

        int rst = 0; //최종 비용 합산
        //간선을 탐색하면서 서로 연결되어 있으면 합치고, 아니면 비용계산한다
        for(Info i : info) if(union(i.from, i.to)) rst += i.cost;
        System.out.println(rst);
        br.close();
    }

    static boolean union(int a, int b){
        //왼, 오 연결여부 확인
        int left = searchHead(a);
        int right = searchHead(b);

        //같으면 패스
        if(left == right) return false;
        //다르면 트리 높이를 고려하여 합친다
        if(rank[left] < rank[right]){
            head[left] = right;
        }else if(rank[left] > rank[right]){
            head[right] = left;
        }else{
            head[right] = left;
            rank[right]++;
        }
        return true;
    }

    //연결여부 확인, 상위에 부모가 없을 때까지 찾는다.
    static int searchHead(int x){
        if(head[x] != x) head[x] = searchHead(head[x]);
        return head[x];
    }
}
