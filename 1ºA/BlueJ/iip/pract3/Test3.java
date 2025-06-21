package pract3;
import java.util.Scanner;

 public class Test3{

    //Activity 4//
     
    public static void main(String[] args){
        
        Scanner kbd=new Scanner(System.in);
        System.out.println("Reading hour from keyboard.");
        System.out.print("   -> Input the hour (between 0 and 23): ");
        int h = kbd.nextInt();
        System.out.print("   -> Input the minutes (between 0 and 59): ");
        int m = kbd.nextInt();

        String hh = "0"+h; hh= "0" +hh;
        String mm = "0"+m; mm= "0" +mm;
        
        hh = hh.substring(hh.length()-2);
        mm = mm.substring(mm.length()-2);
        
        System.out.printf("Inputted hour: "+hh); 
        System.out.println(":"+mm);
       
    //Activity 5//
    
        long minTotal = System.currentTimeMillis()/ (60*1000);
        int minCurrent = (int) minTotal % (24*60);
        
        int hUTC= minCurrent / 60;
        int mUTC= minCurrent % 60;
        
        String hhUTC = "0"+hUTC; 
        String mmUTC = "0"+mUTC;
        hhUTC = hhUTC.substring(hhUTC.length()-2);
        mmUTC = mmUTC.substring(mmUTC.length()-2);
        
        System.out.println("UTC hour: "+hhUTC+ ":" +mmUTC); 
        
    //Activity 6//
    
        int DifferenceFinalHour = Math.abs(h - hUTC);
        int DifferenceFinalMinutes = Math.abs(m - mUTC);
        String hhDifferenceFinalHour = "0"+DifferenceFinalHour; 
        String mmDifferenceFinalMinutes = "0"+DifferenceFinalMinutes;
        hhDifferenceFinalHour= hhDifferenceFinalHour.substring(hhDifferenceFinalHour.length()-2);
        mmDifferenceFinalMinutes= mmDifferenceFinalMinutes.substring(mmDifferenceFinalMinutes.length()-2);
        
        System.out.println("UTC hour difference: "+hhDifferenceFinalHour+ ":" +mmDifferenceFinalMinutes); 

        
        
        
        
    }
}
