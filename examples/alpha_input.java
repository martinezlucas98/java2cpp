// Welcome to java2cpp
public class Main {
  static void myMethod() {
    System.out.println("Method executed!");
  }

  static int vectLen(int[] vect){
  	boolean testing = true;
    int i = 0;
  	while (testing){
      try {
        int test = vect[i];
        i = i+1;
      }catch(Exception e){
      	testing = false;
      }
    }
    return (i);
  }

  static int[] arrXY(double arr[][]){
  	boolean testing = true;
    int[] xy = new int[2];
    int i = 0;
    int j = 0;
  	while (testing){
      try {
        double test = arr[i][0];
        i = i+1;
      }catch(Exception e){
      	testing = false;
      }
    }
    testing = true;
    while (testing){
      try {
        double test = arr[0][j];
        j = j+1;
      }catch(Exception e){
      	testing = false;
      }
    }
    xy[0] = i;
    xy[1] = j;
    return (xy);
  }

  public static void main(String[] args) {
  	String randomStr = "we made it to the embedded IF";
    int[] vect = {0,1,2,3,4,5,6,7,8,9};
    double[][] arr = new double[5][3];
    myMethod();
    for (int i = 0; i < 10; i++) {
      if (i%2==0){
      	System.out.println(i);
      }else{
      	System.out.println("X");
        if(i%3==0){
        	System.out.println(randomStr);
        }
      }
    }
    System.out.println("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    int l = vectLen(vect);
    System.out.println("Vector length:"+l);
    int[] dim = arrXY(arr);
    System.out.println("2 dimensional array dimensions: "+dim[0]+"x"+dim[1]);
  }
}
/*
Goodbye!
*/
