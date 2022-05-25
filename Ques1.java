class Ques1{
    public static void main(String args[]){
        int[] a = new int[4];
        a[0]=1;
        // a[4]=1;
        try{
            a[4]=1;
        }
        catch (ArrayIndexOutOfBoundsException e){
            System.out.println(e);
            System.out.println("In catch");

        }
    } 
}
