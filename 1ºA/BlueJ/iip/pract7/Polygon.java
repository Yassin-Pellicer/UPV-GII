package pract7;
import java.awt.Color;
import pract5.Point;
/**
 * Clase Polygon. Poligonos solidos (de un determinado color) en el plano,
 * dados por la secuencia de sus vertices.
 * 
 * @author IIP - Practica 7
 * @version Curso 2021/22
 */
public class Polygon {    
    /* COMPLETAR la definicion de atributos de instancia privados */

    /**
     * Construye un poligono a partir de un array x con las
     * abcsisas x0, x1, x2, ..., xn-1 de sus vertices, y un array y
     * con las ordenadas y0, y1, y2, ... yn-1 de sus vertices, n > 0.
     * Los vertices definen un poligono cuyos lados se extienden de 
     * un vertice al siguiente, y cerrandose en (x0,y0).
     * Por defecto, el poligono es de color azul (Color.BLUE).
     * @param x double[], las abscisas.
     * @param y double[], las ordenadas.
     */
    
    private Color color;
    private Point v[];
    
    public Polygon(double[] x, double[] y) {
        v = new Point[x.length];
        
        for(int i = 0; i < v.length; i++){  
            v[i]= new Point(x[i], y[i]);
        }
        
        color = Color.BLUE;
    }

    /** Devuelve el color del poligono.
     *  @return Color, el color. 
     */
    public Color getColor() {
        return color;
    }
    
    /** Actualiza el color del poligono a un color dado.
     *  @param nC Color, el nuevo color.
     */
    public void setColor(Color nC) {
        color = nC;
    }
    
    /** Devuelve las abcisas de los vertices del poligono. 
     *  @return double[], las abscisas de los vertices.
     */
    public double[] verticesX() {
        double [] x = new double[v.length];
         for(int i = 0; i < v.length; i++){  
            x[i]= v[i].getX();
        }
        return x;
    }
    
    /** Devuelve las ordenadas de los vertices del poligono.
     *  @return double[], las ordenadas de los vertices. 
     */
    public double[] verticesY() {
        double [] y = new double[v.length];
         for(int i = 0; i < v.length; i++){  
            y[i]= v[i].getY();
        }
        return y;
    }
    
    /** Traslada los vertices del poligono: 
     *  incX en el eje X e incY en el eje Y.
     *  @param incX double, el incremento o decremento en X.
     *  @param incY double, el incremento o decremento en Y.
     */
    public void translate(double incX, double incY) {
        double x[] = verticesX();
        double y[] = verticesY();

        for (int i = 0; i < v.length; i++){
            v[i].setX(x[i]+incX);
        }
        for (int i = 0; i < v.length; i++){
            v[i].setY(y[i]+incY);
        }
    }
            
    /** Devuelve el perimetro del poligono.
     *  @return double, el perimetro.
     */
    public double perimeter() {
        double perimTotal = 0;
        double distFin = 0;

        for (int i = 0; i < v.length-1; i++){
           double dist = v[i+1].distance(v[i]);
           perimTotal += dist;
        }

        distFin = v[0].distance(v[v.length-1]);
        return perimTotal+distFin;
    }   
          
    /** Comprueba si el Point p es interior al poligono.
     *  PRECONDICION: p no esta sobre los lados del poligono.
     *  Si el punto es interior al poligono devuelve true; 
     *  en caso contrario, devuelve false.
     *  @param p Point, el punto.
     *  @return boolean, true si el punto es interior o false
     *  si es exterior.
     */
    public boolean inside(Point p) {
        int nCounter = 0;
        
        for (int i = 0; i < v.length-1; i++){
            if(p.cross(v[i+1],v[i]) == Point.CROSS || p.cross(v[i],v[i+1]) == Point.LOW_CROSS){
               nCounter += 1; 
            }
        }
        
        if(p.cross(v[0],v[v.length-1]) == Point.CROSS || p.cross(v[0],v[v.length-1]) == Point.LOW_CROSS){
            nCounter += 1;
        }

        if (nCounter % 2 != 0){
            return true;
        }
            return false;
    } 
    }
