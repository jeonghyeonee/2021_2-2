import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.util.Scanner;

public class memory_hierarchy {

    static float tot = 0;
    static float hit_1 = 0;
    static float hit_2 = 0;
    static float hit_3 = 0;
    static float hit_4 = 0;
    static int tag = 0; // 2 way set tag


    //--------Hit ratio 계산용 변수--------------------

    static String[][] L4 = new String[512][8]; // global 변수(array) 선언

    //-------------L4----------------------

    static String[][][] L3 = new String[16][2][8]; // 2-way set

    //--------------L3-----------------------

    static String[][] L2 = new String[2][8];

    // --------------L2-------------------

    static String[] L1 = new String[1];

    //----------------L1------------------


    public static String[] SearchL2(String x) { // 값 찾는 함수 (매개변수 : value)

        for(int i =0; i < L2.length; i++) { // L2에 있는지 찾기
            for(int j=0; j < 8; j++) {
                if(x.equals(L2[i][j])) {
                    System.out.println("Hit! in L2");
                    hit_2++;
                    L1[0] = x;
                    return L2[i];
                }
            }

        }
        System.out.println("not in L2");
        return SearchL3(x); // 없으면 L3로 가
    }

    public static String[] SearchL3(String x) { // 값 찾는 함수 (매개변수 : value)
        for(int i =0; i < L3.length; i++) {
            for(int j=0; j < 8; j++) {
                if(x.equals(L3[i][0][j])) {
                    System.out.println("Hit! in L3");
                    hit_3++;
                    L2[i%2] = L3[i][0]; // 한 세트당 블럭 수 16개(16 = L2.length)
                    L1[0] = x;
                    return L2[i%2];
                }
                else if(x.equals(L3[i][1][j])) {
                    System.out.println("Hit! in L3");
                    hit_3++;
                    L2[i%2] = L3[i][1]; // 한 세트당 블럭 수 16개(16 = L2.length)
                    L1[0] = x;
                    return L2[i%2];
                }
            }
        }
        System.out.println("not in L3");
        return SearchL4(x); // 없으면 L4로 가
    }

    public static String[] SearchL4(String x) { // 값 찾는 함수 (매개변수 : value)
        for(int i =0; i < L4.length; i++) {
            for(int j=0; j < 8; j++) {
                if(x.equals(L4[i][j])) { // 값을 찾으면! => 8개의 블럭 모두 상위 캐시에 저장!
                    System.out.println("Hit! in L4");
                    hit_4++;
                    L3[i%16][tag%2] = L4[i]; // 한 세트당 블럭 수 128개(128 = L3.length), 배열 전부를 집어넣기
                    L2[i%16%2] = L4[i]; // L2에도 값을 저장해주고 진행
                    tag++;
                    L1[0] = x;
                    return L2[i%16%2];
                }
            }
        }
        System.out.println("not in L4");
        System.out.println("invalid value(Or Capacity miss)");
//        String[] beL4 = L1;
        return L1; // 이전 데이터 그대로 가지고 있기
    }


    public static void main(String[] args) {

        BufferedReader br = null;
        String line;
        int count = 0;

        Scanner scan = new Scanner(System.in);
        System.out.print("파일 경로를 입력해주세요: ");
        String path = scan.nextLine();

        try {
            br = new BufferedReader(new InputStreamReader(new FileInputStream(path), "UTF-8"));
            while((line = br.readLine()) != null) {

                String[] temp = line.split(",");
//                for(int i=0; i<temp.length; i++) {
////                    System.out.print(temp[i]);
////                    if(i!=temp.length-1) System.out.print(", ");
////                    else System.out.println();
//                }\
//                System.out.println("The End");
                for (int j=0; j<L4.length; j++){
                    for(int k=0; k<L4[j].length; k++) {
                        L4[j][k] = temp[count];
                        count++;
                        System.out.print(L4[j][k] + " ");
                    }
                    System.out.println();
                }


            }

        } catch (Exception e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }



        while(true) {

            Scanner sc = new Scanner(System.in);
            System.out.println(" ");
            //------------L3 출력--------------
//            for(int i=0; i<L3.length; i++){
//                for(int j=0; j<L3[i].length; j++){
//                    for(int k=0; k<L3[i][j].length; k++){
//                        System.out.print(L3[i][j][k]);
//                    }
//                    System.out.println();
//                }
//                System.out.println();
//            }
            System.out.print("접근할 값(종료시에는 exit) : ");
            String value = sc.nextLine();
            tot++;
            if(value.equals("exit")) break;
            else {
                //------------값 입력---------------------

                int valid = 0; // 1 = true, 0 = false
                if(value.equals(L1[0])){
                    valid = 1;
                }


                if (valid == 1) { // 있으면 hit!
                    System.out.println("Hit! in L1");
                    hit_1++;
                }
                else { // 없으면 SearchL2!
                    System.out.println("not in L1"); // L2에서 값 찾는 함수 넣기
                    SearchL2(value); // L2에서 값 찾는 함수
                }
                //----------------검색----------------------

                System.out.println("--------------------------------");
                System.out.println("L1 hit ratio : "+hit_1/tot);
                System.out.println("L2 hit ratio : "+hit_2/tot);
                System.out.println("L3 hit ratio : "+hit_3/tot);
                System.out.println("L4 hit ratio : "+hit_4/tot);
                System.out.println("--------------------------------");

                //---------------Hit ratio------------------
            }
        }
    }
}