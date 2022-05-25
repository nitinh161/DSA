class Ques3{
    public static void main(String args[]){
        int[] a = new int[4];
        a[0]=1;
        // a[4]=1;
        try{
            a[3]=1;
            try{
                int x = 1/0;
            }
            catch(ArithmeticException e){
                System.out.println(e);
                System.out.println("In nested catch");
            }
        }
        finally{
            System.out.println("in final");
        }
        
        // System.out.println("IN end");
    } 
}
