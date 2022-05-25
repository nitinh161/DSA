import java.util.*;
class Ques6{
    
    public static void main(String args[]){
        bank[] q = new bank[2];

        q[0] = new bank(5,550,"manav");
        q[1] = new bank(55,5622,"mukul");
        try{
            q[1].withdraw(452);
            q[0].withdraw(500);
        }
        catch (InsufficientBalanceException e){
            System.out.println(e);
        }

        try{
            String k = "2";
            if(k.getClass().getName()!="Integer"){
                throw new ArithmeticException("Invalid account"); 
            }

        }
        catch (ArithmeticException e){
            System.out.println(e);
        }
    } 
}
class InsufficientBalanceException extends ArithmeticException{
        InsufficientBalanceException(String s){
            super(s);
        }
    }
    
class bank{
    int ac_no;
    int bal;
    String name;
    bank(int a,int b,String n){
        ac_no=a;
        bal=b;
        name=n;
    }
    void check_bal(){
        if(bal>=100) return;
        System.out.println("Account no = "+ac_no+"\nName = "+name+"\nBalance = "+bal);   
    }
    void deposit(int a){
        this.bal+=a;
    }
    void withdraw(int a) throws InsufficientBalanceException{
        this.bal-=a;
        if(this.bal<100){
            this.bal+=a;
            throw new InsufficientBalanceException("Balance goes less than 100");
        }
        System.out.println("Your curr bal = "+bal);
    }
}
