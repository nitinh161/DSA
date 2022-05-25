import java.util.*;
class Ques5{
    void f()throws ArithmeticException,NullPointerException{
        throw new ArithmeticException("from function");
    }
    public static void main(String args[]){
        Ques5 q = new Ques5();
        try{
            q.f();
        }
        catch (ArithmeticException e){
            System.out.println(e);
        }
    } 
}
