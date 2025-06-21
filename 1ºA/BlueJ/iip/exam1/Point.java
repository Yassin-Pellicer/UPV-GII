package exam1;

/**  
 *  Class Point: This is a data-type class to define a point in the 
 * cartesian plane defined by their coordinates x and y. 
 *  
 *  @author IIP - Lab Midterm Exam
 *  @version Academic Year 2021/22
 */
public class Point {
    // A Point has ...    

    // (a) as private instance Attributes:
    private double x;
    private double y;

    // (b) as public methods:
    /** Create a Point with abscissa px and ordinate py. 
     *  @param px double, the abscissa.
     *  @param py double, the ordinate.
     */
    public Point(double px, double py) { this.x = px; this.y = py; }

    /** Create a Point with abscissa 0.0 and ordinate 0.0. */
    public Point() { this(0, 0); }

    /** Return the abscissa of the Point this. 
     *  @return double, the abscissa.      
     */
    public double getX() { return this.x; }

    /** Return the ordinate of the Point this. 
     *  @return double, the ordinate.
     */
    public double getY() { return this.y; }

    /** Update the abscissa of this to px.
     *  @param px double, the new abscissa.
     */
    public void setX(double px) { this.x = px; }

    /** Update the ordinate of this to py.
     *  @param py double, the new ordinate.
     */
    public void setY(double py) { this.y = py; }   

    /** Updates both coordinates: the abscissa and the ordinate.
     *  @param px double, the new value for the abscissa.
     *  @param py double, the new value for the ordinate
     */
    public void move(double px, double py) { 
        this.x = px; this.y = py; 
    }  

    /** Returns the distance between two points, the current one 
     *  and another one passed as parameter.
     *  @param p Point, the other Point.
     *  @return double, the distance between this and p.
     */
    public double distance(Point p) { 
        double abs = p.x - this.x; double ord = p.y - this.y; 
        return Math.sqrt(abs * abs + ord * ord); 
    }

    /** Returns the distance between two points, the current one 
     *  and another the origin (0.0, 0.0).     
     *  @return double, the distance.
     */
    public double distance() {        
        return this.distance(new Point()); 
    }

    /**
     * Checks if the current object of the class Point
     * referenced by this is equal to another point
     * passed as argument but as a generic reference to objects of
     * the class Object.
     * @param o Object, reference to the object to be compared with this.
     * @return boolean, true if o is a reference of the class Point and
     *      the values of both coordinates are equal, else returns false.
     */
    public boolean equals(Object o) {
        return o instanceof Point 
        && this.x == ((Point) o).x 
        && this.y == ((Point) o).y;        
    }

    /** 
     * Returns an object of the class String containing a representation of the
     *  current point with the common format (abscissa,ordinate).
     *  @return String, the result.
     */
    public String toString() {
        return "(" + this.x + "," + this.y + ")";      
    }   
    
    /** 
     * Given a Point p, which together with the current Point (this)
     *  is part of a straight line with gradient m, it returns this, p 
     *  or the Point (0.0, 0.0) if the gradient m of the line is negative, 
     *  positive or zero, respectively.
     *  Precondition: this and p abscissas are different  
     *  @param p Point, the other Point.
     *  @return Point, the resultado.
     */ 
    public Point gradient(Point p) {       
        Point res = null;
        Point origin = new Point (0,0);
        
        double slope = (this.y - p.y)/(this.x - p.x);
        if(slope < 0){
            res = Point.this;            
        }else if(slope > 0){
            res = p;
        }else{
            res = origin;
        }
        return res;
    }
}