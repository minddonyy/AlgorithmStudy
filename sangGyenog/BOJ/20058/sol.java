/**
 * 03:36
 * 2**n * 2**n 격자
 * 각 위치에 얼음의 양이 있음
 * 파이어스톰시전시 단계 L결정 필요
 * 먼저 격자를 2**L * 2**L 크기의 부분격자로 나눔
 * 모든 부분 격자를 오른쪽 90도 회전
 * 얼음이 있는 칸 3개 또는 그 이상과 인접해있지 않은(상, 하, 좌, 우말고 나머지) 얼음의 양이 1줄어듦
 * 파이어스톰을 통 Q번 시전한다고 할 때 모든 파이어 스톰이 끝난 후
 * 1. 남은 얼음 A[r][c]의 합
 * 2. 남은 얼음 중 가장 큰 덩어리가 차지하는 칸의 개수
 * 을 출력 덩어리가 없으면 0
 * 얼음이 있는 칸이 얼음이 있는 칸과 인접하면 연결되어 있는 것
 *
 * 입력
 * N, Q
 * 2**N개줄에 격자의 얼음정보가 주어짐
 * 마법을 시전한 단계가 주어짐
 */

import java.io.*;
import java.util.*;
public class java250721_20058 {

    static int[] x = {-1, 1, 0, 0};
    static int[] y = {0, 0, -1, 1};
    static int nPow = 0;
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken()), Q = Integer.parseInt(st.nextToken());
        nPow = (int) Math.pow(2, N);
        int[][] matrix = new int[nPow][nPow]; //얼음 좌표
        int[][] matrixPass = new int[nPow][nPow]; //얼음 방문여부
        int[] qList = new int[Q]; //시전한 단계 리스트

        for(int i=0;i<nPow;i++){
            st = new StringTokenizer(br.readLine());
            for(int j=0;j<nPow;j++){
                matrix[i][j] = Integer.parseInt(st.nextToken());
                matrixPass[i][j] = 0;
            }
        }

        st = new StringTokenizer(br.readLine());
        for(int i = 0;i<Q;i++){
            qList[i] = Integer.parseInt(st.nextToken());
        }

        //파이어스톰 시행
        for(int q : qList) {
            rotation(matrix, q); //90도 회전
            unFreeze(matrix); //얼음 녹이기
        }

        //결과출력1 - 전체 얼음 합산
        int rst1 = 0;
        for(int i=0;i<nPow;i++){
            for (int j=0;j<nPow;j++){
                if(matrix[i][j] < 1) continue;
                rst1 += matrix[i][j];
            }
        }

        //결과출력2 - 제일 큰 얼음 덩어리 찾기
        int rst2 = 0;
        for(int i=0;i<nPow;i++){
            for (int j=0;j<nPow;j++){
                if(matrixPass[i][j] == 1 || matrix[i][j] < 1) continue;
                rst2 = Math.max(rst2, bigIce(i, j, matrixPass, matrix));
            }
        }
        System.out.println(rst2 != 0 ? rst1 : 0);
        System.out.println(rst2);
        br.close();
    }

    static void rotation(int[][] matrix, int q){
        int qPow = (int) Math.pow(2, q);
        //범위잡기
        for(int i=0;i<nPow;i+=qPow){
            for (int j=0;j<nPow;j+=qPow){
                subRotate(matrix, i, j, qPow);
            }
        }
    }

    static void subRotate(int[][] matrix, int i, int j, int qPow){
        int[][] tempMatrix = new int[qPow][qPow];
        //범위만큼 안에서만 90도 회전
        for(int row=0;row<qPow;row++){
           for(int col=0;col<qPow;col++){
               tempMatrix[col][qPow-1-row] = matrix[row+i][col+j];
           }
        }

        for(int row=0;row<qPow;row++){
            for(int col=0;col<qPow;col++){
                matrix[row+i][col+j] = tempMatrix[row][col];
            }
        }
    }

    static void unFreeze(int[][] matrix){
        //상, 하, 좌, 우 인접한 얼음이 3개 미만이면 녹이기
        List<int[]> unFreezeList = new ArrayList<>();
        for(int i=0;i<nPow;i++) {
            for (int j = 0; j < nPow; j++) {
                int subCnt = 0;
                for (int ii = 0; ii < x.length; ii++) {
                    int dx = i + x[ii];
                    int dy = j + y[ii];
                    if (0 > dx || dx >= nPow || 0 > dy || dy >= nPow) continue;
                    if (matrix[dx][dy] <= 0) continue;
                    subCnt++;
                }
                if(subCnt < 3){
                    unFreezeList.add(new int[]{i, j});
                }
            }
        }
        //실시간으로 녹이지 말고 한꺼번에!
        for(int ii = 0;ii<unFreezeList.size();ii++){
            int[] pos = unFreezeList.get(ii);
            matrix[pos[0]][pos[1]] -= 1;
        }
    }

    //얼음덩어리 그룹화(땅갯수세기)
    static int bigIce(int i, int j, int[][] matrixPass, int[][] matrix){
        Queue<int[]> q = new LinkedList<>();
        q.add(new int[]{i, j});
        matrixPass[i][j] = 1;
        int bigRst = 1;
        while (!q.isEmpty()){
            int[] qq = q.poll();
            int a = qq[0], b = qq[1];
            for(int ii = 0;ii<x.length;ii++){
                int dx = a + x[ii];
                int dy = b + y[ii];
                if(0 > dx || dx >= nPow || 0 > dy || dy >= nPow || matrix[dx][dy] < 1 || matrixPass[dx][dy] == 1) continue;
                matrixPass[dx][dy] = 1;
                q.add(new int[]{dx, dy});
                bigRst++;
            }
        }
        return bigRst;
    }
}
