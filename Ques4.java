import java.util.*;
class Ques4{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        // a[4]=1;
        try{
            if(n<0){
                throw new ArithmeticException("Negative Number");
            }
            if(n==0){
                System.out.println("Ans = "+0);
                return;
            }
            int ans=1;
            for(int i=n;i>1;i--) ans*=i;
            System.out.println("Ans = "+ans);
        }
        catch(ArithmeticException e){
            System.out.println(e);
        }
        // System.out.println("IN end");
    } 
}
