/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package javafxmlapplication;

import java.io.IOException;
import java.time.LocalDate;
import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.image.Image;
import javafx.stage.Stage;
import model.Club;
import model.Member;

public class JavaFXMLApplication extends Application {
    
    public static Stage login;
    public static Stage signup;
    public static Stage mainScreen;
    public static Stage checkData;
    public static Stage myReservations;
    public static Member memberLoggedIn;
    public static Stage checkAvailability;
    public static Image icon = new Image("img/Avatar_icon_green.svg.png");
    public static LocalDate date = LocalDate.now();
    
    public static String selectedCourtText = "All Courts";
    public static String bookingStatus = "";
    
    @Override
    public void start(Stage stage) throws Exception {
        // try{Club c = Club.getInstance(); c.setInitialData();}catch(Exception e){}
        //======================================================================
        // 1- creación del grafo de escena a partir del fichero FXML
        FXMLLoader fxmlLoader = new FXMLLoader();
        fxmlLoader.setLocation(getClass().getResource("FXMLDocument.fxml"));
        //======================================================================
        // 2- creación de la escena con el nodo raiz del grafo de escena
        Scene scene = new Scene(fxmlLoader.load());
        //======================================================================
        // 3- asiganación de la escena al Stage que recibe el metodo 
        //     - configuracion del stage
        //     - se muestra el stage de manera no modal mediante el metodo show()
        login = new Stage();
        login.setResizable(true);
        login.setTitle("Login");
        login.setScene(scene);

        login.show();
    }
    
    public void changeScene(String fxml, Stage stg, int x, int y) throws IOException{
        Parent pane = FXMLLoader.load(getClass().getResource(fxml));
        stg.getScene().setRoot(pane);
        stg.setX(x);
        stg.setY(y);
    }
    
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        launch(args);
    }
}
