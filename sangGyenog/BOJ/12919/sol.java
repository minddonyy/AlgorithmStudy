/**
 * 01:07
 * A B로만 이루어진 두 문자열 S, T
 * S를 T로 바꿀 수 있으면 1 아니면 0출력
 * 1. 문자열 뒤에 A추가
 * 2. 문자열 뒤에 B를 추가하고 문자열을 뒤집는다
 * S길이 < T길이
 */

import java.io.*;
import java.util.*;
public class java250719_12919 {
    static String S; //입력1
    static String T; //입력2
    static int rst = 0; //S -> T 가능여부
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        S = br.readLine();
        T = br.readLine();

        bfs(T); //효율성을 위해 T -> S 역으로 접근
        System.out.println(rst);
    }
    static void bfs(String word){
        Queue<String> q = new LinkedList<>();
        q.add(word);
        while(!q.isEmpty()){
            String qWord = q.poll();
            if(qWord.length() < S.length()) continue;
            if(qWord.equals(S)) {
                rst = 1;
                return;
            }

            //1. 끝에 A를 추가 -> 끝이 A면 삭제
            if(qWord.endsWith("A")) {
                StringBuilder subA = new StringBuilder();
                subA.append(qWord).deleteCharAt(qWord.length()-1);
                q.add(String.valueOf(subA));
            }

            //2. 끝에 B를 추가 후 뒤집기 -> 뒤집고, 끝이 B면 삭제
            StringBuilder subB = new StringBuilder();
            subB.append(qWord);
            String b = String.valueOf(subB.reverse());
            if(b.endsWith("B")) {
                subB.deleteCharAt(qWord.length()-1);
                q.add(String.valueOf(subB));
            }
        }
    }
}


// /**
// *  00:28 - 시간초과
//  * A B로만 이루어진 두 문자열 S, T
//  * S를 T로 바꿀 수 있으면 1 아니면 0출력
//  * 1. 문자열 뒤에 A추가
//  * 2. 문자열 뒤에 B를 추가하고 문자열을 뒤집는다
//  * S길이 < T길이
//  */

// import java.io.*;
// import java.util.*;
// public class java250719_12919 {
//     static String S;
//     static String T;
//     static int rst = 0;
//     public static void main(String[] args) throws IOException{
//         BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

//         S = br.readLine();
//         T = br.readLine();

//         dfs(S);
//         System.out.println(rst);
//     }

//     static void dfs(String subS){
//         if(subS.length() == T.length()){
//             if(subS.equals(T)){
//                 rst = 1;
//                 return;
//             }
//             else return;
//         }

//         //A를 추가한다
//         dfs(subS+"A");

//         //B를 추가 후 문자열을 뒤집는다.
//         String addB = subS+"B";
//         StringBuilder subB = new StringBuilder();
//         for(int i = addB.length()-1;i>=0;i--){
//             subB.append(addB.charAt(i));
//         }
//         dfs(String.valueOf(subB));
//     }
// }