/**
 * 02:34
 * NxN크기의 땅을 구매함
 * 땅을 1x1크기 칸으로 나눔 각각 칸은 (r, c)로 나타냄
 * 땅의 양분을 조사하는 로봇이 있다
 * 처음 모든 땅의 양분은 5
 * M개의 나무를 구매해 키운 후 파는 재테크
 * 같은 칸에 여러 나무가 있을 수 있다
 *
 * 과정
 * 1. 봄 - 나무가 자신의 나이만큼 양분을 먹고 나이 +1 자기칸에 있는 양분만 먹을 수 있음
 * 여러 나무가 있다면 나이가 어린 나무부터 양분을 먹음
 * 양분부족 시 자신의 나이만큼 못먹는 나무는 죽음
 * 2. 여름 - 봄에 죽은 나무가 양분으로 변함 죽은 나무마다 나이를 2로 나눈 값이 나무가 있던 칸에 양분으로 추가
 * 소수점 아래는 버림
 * 3. 가을 - 나무 번식, 번식하는 나무는 나이가 5의 배수, 인접한 8개 칸에 나이가 1인 나무가 생김
 * 4. 겨울 - 양분을 조사하는 로봇이 양분을 추가함, 각 칸에 추가되는 양분은 입력으로 주어지는 A[r][c]
 *
 * K년이 지난 후 살아있는 나무의 개수 출력
 *
 * 입력
 * N, M, K
 * N개의 줄에 걸쳐 A배열 값이 주어짐
 * M개의 줄에 걸쳐 나무 정보를 나타내는 X, y, z
 * x, y는 위치 / z는 나이임
 *
 */
import java.io.*;
import java.util.*;

public class java250716_16235 {

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken()), M = Integer.parseInt(st.nextToken()), K = Integer.parseInt(st.nextToken());
        int[][] matrix = new int[N][N]; //각 칸의 기본 양분 공급정보
        int[][] nowMatrix = new int[N][N]; //각 칸의 현재 양분 재고
        ArrayList[][] treeMatrix = new ArrayList[N][N]; // 각 위치의 나무 나이 배열
        int year = 0; // 년수
        int rst = 0; // 최종 출력 나무 수

        //기본 양분 입력 받기
        for (int i = 0;i < N;i++){
            st = new StringTokenizer(br.readLine());
            for(int j = 0; j < N;j++){
                matrix[i][j] = Integer.parseInt(st.nextToken());
                nowMatrix[i][j] = 5; //첫 양분은 기본으로 5
                treeMatrix[i][j] = new ArrayList<>(); //각 위치의 나무 배열도 생성
            }
        }

        //현재 나무 위치와 나이 입력 받기
        for(int i = 0;i < M;i++){
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken())-1, y = Integer.parseInt(st.nextToken())-1, age = Integer.parseInt(st.nextToken());
            treeMatrix[x][y].add(age);
        }

        //각 위치에서 나무 나이 순으로 정렬
        for(int i = 0;i < N;i++) {
            for(int j = 0;j < N;j++) {
                Collections.sort(treeMatrix[i][j]);
            }
        }

        //4계절 시작
        while (year < K){
            springSummer(N, nowMatrix, treeMatrix); //봄, 여름
            autumn(N, treeMatrix); //가을
            winter(N, matrix, nowMatrix); //겨울
            year++; // 년수+1
        }

        //최종 살아있는 나무 수 구하기
        for (int i=0;i<N;i++){
            for(int j = 0;j < N;j++) {
                if(treeMatrix[i][j].size() > 0)
                rst += treeMatrix[i][j].size();
            }
        }

        System.out.println(rst);
        br.close();
    }
    static void springSummer(int N, int[][] nowMatrix, ArrayList[][] treeMatrix ){
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                ArrayList<Integer> newTree = new ArrayList<>(); //살아있는 나무 리스트 새로 생성
                int deadTree = 0; //죽는 나무의 양분 수
                for(int mm=0;mm<treeMatrix[i][j].size();mm++){
                    int treeNow = (int) treeMatrix[i][j].get(mm);
                    if(nowMatrix[i][j] >= treeNow){
                        nowMatrix[i][j] -= treeNow; //양분먹기
                        newTree.add(treeNow+1); //새 나무 리스트에 추가

                    }else deadTree += treeNow / 2; //죽으면 양분으로 전환

                }
                nowMatrix[i][j] += deadTree;
                treeMatrix[i][j] = newTree;
            }
        }
    }

    static int[] X = {-1, 1, 0, 0, -1, -1, 1, 1};
    static int[] Y = {0, 0, -1, 1, -1, 1, -1, 1};

    static void autumn(int N, ArrayList[][] treeMatrix){
        ArrayList<int[]> add = new ArrayList<>(); // 새로 태어날 나무 리스트 생성용
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                for(int mm=0;mm<treeMatrix[i][j].size();mm++){
                    int treeNow = (int) treeMatrix[i][j].get(mm);

                    //나이가 5의 배수라면 8방향으로 새 나무 전파
                    if(treeNow % 5 == 0){
                        for (int jj = 0;jj < X.length;jj++){
                            int dx = i + X[jj];
                            int dy = j + Y[jj];
                            if(0 > dx || N <= dx || 0 > dy || N <= dy) continue;
                            add.add(new int[]{dx, dy});
                        }
                    }
                }
            }
        }
        for(int i=0;i<add.size();i++){
            int[] addList = add.get(i);
            int addX = addList[0], addY = addList[1];
            treeMatrix[addX][addY].add(0, 1);
        }

    }

    static void winter(int N, int[][] matrix, int[][] nowMatrix){
        //각 위치의 기본 양분 뿌리기
        for(int i = 0;i < N;i++){
            for(int j = 0;j < N ;j++){
                nowMatrix[i][j] += matrix[i][j];
            }
        }
    }


}