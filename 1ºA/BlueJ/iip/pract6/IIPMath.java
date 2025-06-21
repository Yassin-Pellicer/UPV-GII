package pract6;

/**
 * Class IIPMath: utility class that implements some mathematical operations: 
 * IIPMath.sqrt(double) and IIPMath.log(double).
 *
 * @author IIP
 * @version Academic Year 2021-2022
 */
public class IIPMath {
    /** Approximated value for log(2). */
    
    /** It is not possible to create new objects for this class. */
    private IIPMath() { }    
    
    /**
     * Returns the square root of x >= 0 with a precision epsilon > 0. 
     * // COMPLETE COMMENTS
     */
    public static double sqrt(double x, double epsilon) {
        double termCurr = (1+x)/2;
        double termPrev;
        double error = epsilon + 1;
        while (error >= epsilon){
            termPrev = termCurr;
            termCurr = (termPrev + x/ termPrev)/2;
            error = termPrev - termCurr;
        }
        return termCurr;
    }            

    /**
     * Returns the square root of x >= 0 with a precision 1e-15. 
     * // COMPLETE COMMENTS
     */
    public static double sqrt(double x) {    
        return sqrt(x, 1e-15);
    }                 
                  
    /**
     * Returns log(z), 1/2 <= z < 1, with an error epsilon > 0.
     * // COMPLETE COMMENTS
     */
    public static double logBase(double z, double epsilon) {
        double y = (1-z)/(1+z); 
        double currTerm = y;
        double sum = currTerm;
        int k = 1;
        while (currTerm >= epsilon){
            currTerm = y*y*((2.0*k-1))*currTerm/(2.0*k+1);
            sum += currTerm;
            k++; 
        }
        return -2*sum;
    }
            
    /**
     * Returns log(x), x > 0, with an error epsilon > 0.
     * // COMPLETE COMMENTS
     */
    public static double log(double x, double epsilon) {
        
        double fValue = 0;

        if(x > 0.5 && x < 1){
            fValue = logBase (x, epsilon);
        }else{
            if(x < 0.5){
                int times2 = 0;
                while (x < 0.5){
                    x = x*2.0;
                    --times2;
                }
                fValue = times2*0.6931471806 + logBase(x, epsilon);
            }else{
                int times2div = 0;
                while (x >= 1){
                    x = x/2.0;
                    ++times2div;
                }
                fValue = times2div*0.6931471806 + logBase(x, epsilon);
            }
        }
        return fValue;
    }

    /**
     * Returns log(x), x > 0, with error 1e-15.
     * // COMPLETE COMMENTS
     */
    public static double log(double x) {
        return log(8,1e-15);
    }              
}
