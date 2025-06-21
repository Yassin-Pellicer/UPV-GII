package pract2;
/**
 * Write a description of class MyDrawing here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class MyDrawing
{
    public static void main(String[] args) {        
        // Init blackboard given name and dimensions
        Blackboard bb = new Blackboard("WINDOW TO THE WORLD", 720, 720);   
        Circle c = new Circle(50, "yellow", 300, 300);
        Circle X = new Circle(40, "black", 300, 300);
        Circle u = new Circle(30, "red", 300, 300);
        Circle y = new Circle(20, "blue", 300, 300);
        Circle z = new Circle(10, "green", 300, 300);
        bb.add(c);
        bb.add(X);
        bb.add(u);
        bb.add(y);
        bb.add(z);
        Circle cp = new Circle(50, "yellow", 500, 300);
        Circle Xp = new Circle(40, "black", 500, 300);
        Circle up = new Circle(30, "red", 500, 300);
        Circle yp = new Circle(20, "blue", 500, 300);
        Circle zp = new Circle(10, "green", 500, 300);
        bb.add(cp);
        bb.add(Xp);
        bb.add(up);
        bb.add(yp);
        bb.add(zp);
        Rectangle r = new Rectangle(200, 10, "red", 500, 300);
        // put it on the drawing space
        bb.add(r); 
        System.out.println("the radius of the circle is: " + c.getRadius());
    }
}
