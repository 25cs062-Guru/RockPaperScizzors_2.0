import java.util.Scanner;

public class Rock_Roulette{
    public static void main(String[] args){
        int ropasi = (int)(Math.random() * 10);

        Scanner sc = new Scanner(System.in);

        System.out.println("----Welcome to the Rock Roulette!----");
        System.out.println("Enter a number from 1 to 10");
        int input;
        do{
        input = sc.nextInt();
        if (input == ropasi){
        System.out.println(ropasi);
        System.out.println("Correct");
        }
        }while(input != ropasi);
    }
}