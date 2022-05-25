class Ques2{
    public static void main(String args[]){
        int[] a = new int[4];
        a[0]=1;
        // a[4]=1;
        try{
            a[4]=1;
            int x = 1/0;
        }
        catch (ArrayIndexOutOfBoundsException e){
            System.out.println(e);
            System.out.println("In catch 1");
        }
        catch(ArithmeticException e){
            System.out.println(e);
            System.out.println("In catch 2");
        }
        System.out.println("IN end");
    } 
}
