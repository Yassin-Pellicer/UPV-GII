package pract4;
/**
 * Class TimeInstant. 
 * <p> This class allows you to represent instants or timestamps with 
 * detail of hours and minutes. Thus, this class represents the moment 
 * that defines a time instant, in this case, the hours and minutes of 
 * any given day.
 * </p>
 * 
 *  @author IIP. Grado en Informatica. ETSINF, UPV 
 *  @version Academic Year 2021-22
 */
public class TimeInstant {

    // ATTRIBUTES:
    /** Integer attribute for storing the hours of a TimeInstant. 
     *  It should belong to the interval <code>[0..23]</code>
     */
    
    private int hours;      
    // TO COMPLETE
    /** Integer attribute for storing the minutes of a TimeInstant. 
     *  It should belong to the interval <code>[0..59]</code> 
     */
    
    private int minutes;
    // TO COMPLETE
    
    // CONSTRUCTORS:
    /**
     *  <code>TimeInstant</code> corresponding to <code>iniHours</code> 
     *  hours and <code>iniMinutes</code> minutes.
     *  <p> Precondition: <code>0<=iniHours<24, 0<=iniMinutes<60 </code> </p>
     */
    
    public TimeInstant(int iniHours, int iniMinutes){
        hours = iniHours;
        minutes = iniMinutes;
    }
    
     // TO COMPLETE
   
    /**
     * <code>TimeInstant</code> (hours and minutes) from current 
     * UTC (universal coordinated time).
     */
    
    public TimeInstant(){ 
        long minTotal = System.currentTimeMillis()/ (60*1000);
        int minCurrent = (int) minTotal % (24*60)+120;
        int hUTC= minCurrent / 60;
        int mUTC= minCurrent % 60;

        hours = hUTC;
        minutes = mUTC;
    }
    
     // TO COMPLETE
    
    // CONSULTORS AND MODIFYERS:
    /** Returns hours of current TimeInstant object. */ 
     // TO COMPLETE
    public int getHours(){
        return hours;
    }
    /** Returns minutes of current TimeInstant object. */ 
     // TO COMPLETE
    public int getMinutes(){
        return  minutes;
    }
    /** Modifies hours of current TimeInstant object. */ 
    // TO COMPLETE
    public void setHours(int hh){
        hours = hh;
    }
    /** Modifies minutes of current TimeInstant object. */ 
     // TO COMPLETE
   public void setMinutes(int mm){
       minutes = mm;
   }// OTHER METHODS:
    /** Returns current TimeInstant object in "hh:mm" format. */
     // TO COMPLETE
    public String toString(){
        String hh = "0"+hours; 
        String mm= "0"+minutes;
        hh = hh.substring(hh.length()-2);
        mm= mm.substring(mm.length()-2);
        return hh+":"+mm;
    }
   
    /** Returns true only if <code> o </code> is a TimeInstant 
     *  that concides in hours and minutes with current TimeInstant.
     */
    // TO COMPLETE
    
    public boolean equals(Object o){
        return (o instanceof TimeInstant)
        && this.hours == ((TimeInstant) o).hours
        && this.minutes == ((TimeInstant) o).minutes;
    }
      
    /** Returns number of minutes from 
     *  00:00 until current TimeInstant object
     */
    
    public int toMinutes(){
        return this.hours * 60 +this.minutes;
    }
     // TO COMPLETE
    
    /** Chronological comparison of current TimeInstant object 
     *  and <code>tInstant</code> parameter. Result is:
     *     <ul>
     *      <li>negative when current TimeInstant is previous to 
     *        <code>tInstant</code>
     *      </li>
     *      <li> zero if they are equal
     *      </li>
     *      <li>positive when current TimeInstant is posterior to 
     *        <code>tInstant</code>
     *      </li>
     *    </ul>
     */
     public static int compareTo(TimeInstant tInstant){
        int totalMinOBJ = tInstant.toMinutes();
        TimeInstant x = new TimeInstant();
        return totalMinOBJ - x.toMinutes();
    }

      
    // EXTRA ACTIVITY:
    /** Returns a TimeInstant from its textual description 
     *  in a <code>String</code> with format "<code>hh:mm</code>".
     */
 
      // TO COMPLETE
  
}
