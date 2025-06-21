package pract6;

// Import class Graph2D (graph2D package).
import graph2D.Graph2D;
// Import class Color (java.awt package) for
// changing colors of represented elements.
import java.awt.Color;
/**
 * Class Graph2DTest: simple test for class Graph2D.
 * Draws functions Math.sin(x) and Math.sin(x)/x.
 * 
 * @author IIP
 * @version Academic Year 2021-2022
 */
public class Graph2DTest {
    /** It is not possible to create new objects for this class. */
    private Graph2DTest() { }    
    
    /** Draw sin(x) and sin(x)/x with
     *  x in [-1.0 : +PI*4] and f(x) in [-1.10 : +1.10].
     *  Representation by consecutive dots.
     */    
    public static void test() { 
        // Define value ranges for x and y
        double xMin = -1.0;
        double xMax = 15.0;
        double yMin = -3.0;
        double yMax = +4.;
        // Create drawing space with desired dimensions
        Graph2D gd1 = new Graph2D(xMin, xMax , yMin, yMax);
        // Calculate increment for each x step (delta)                           
        double delta = 5 * (xMax - xMin) / Graph2D.INI_WIDTH;  
        // Take each point in x, calculate f(x), draw (x, f(x))
        for (double x = xMin; x <= xMax; x = x + delta) {
            if(x>0){
            double y = IIPMath.log(x,0.000000001);
            gd1.drawPoint(x, y, Color.BLUE, 2);
            }
        }
        
        // Change thickness of elements to 3 (default is 1):
        gd1.setThickness(3);
        // Change color to GREEN for drawing from now on
        gd1.setForegroundColor(Color.GREEN);
        // Take each point in x, calculate f(x), draw (x, f(x))
        for (double x = xMin; x <= xMax; x = x + delta) {
            if(x>0){
            double y = IIPMath.sqrt(x);
            gd1.drawPoint(x, y); 
            }            
            // or equivalently (without changing values before):
            // gd1.drawPoint(x, y, Color.GREEN, 3);
        }        
    }
}
