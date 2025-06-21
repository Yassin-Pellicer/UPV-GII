package exam1;

import others.Point;
import java.util.Locale;
import java.util.Scanner;
/**
 * Class MainExam: This is a main class that uses the hidden class others.Point, 
 * which is identical to your class Point, with a checked method yIntercept(double, Point). 
 * 
 * @author IIP - Lab Midterm Exam
 * @version academic year 2021-22
 */
public class MainExam {
    // There is no objects in this class
    private MainExam() { }
    
    public static void main(String[] args) {
        Scanner teclado = new Scanner(System.in).useLocale(Locale.US);
        
        System.out.println("Keyboard reading of the coordinates of one Point.");
        System.out.print("   -> input the abscissa: ");
        double abs1 = teclado.nextDouble();
        System.out.print("   -> input the ordinate: ");
        double ord1 = teclado.nextDouble();
        
        System.out.println("Keyboard reading of the coordinates of another Point.");
        System.out.print("   -> input the abscissa: ");
        double abs2 = teclado.nextDouble();
        System.out.print("   -> input the ordinate: ");
        double ord2 = teclado.nextDouble();
        
        // Once the different values have been read 
    // and assuming they are correct
        // a) Create a Point p1 from abs1 and ord1
        Point p1 = new Point(abs1, ord1);
        // b) Create a Point p2 from abs2 and ord2
        Point p2 = new Point(abs2, ord2);
        // c) Get the Point p3 result of applying the method gradient to p1 by passing the Point p2 as argument
        if(abs1 < abs2){
        Point p3 = p1.gradient(p2);
        System.out.print("\nPoint p3 results in: "+p3.toString());
        }else{
        Point p3 = p2.gradient(p1);
        System.out.print("\nPoint p3 results in: "+p3.toString());
        }
    }
}
