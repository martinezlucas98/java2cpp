public class Main{ 
       public static int len = 6;
       public static int[] arr= {10,20,30,50,70,90}; 
public static int linearSearch(int key){ 
        int r = -1;
        for (int i = 0;i < len;i++) {
            if(arr[i] == key){    
                r = i;
                break;    
            } 
            
        }  
        System.out.println(key+" is found at index: "+r); 
        return r;    
    }    
    public static void main(String[] args){       
        int key = 50;
        linearSearch(key);   
    }    
}  