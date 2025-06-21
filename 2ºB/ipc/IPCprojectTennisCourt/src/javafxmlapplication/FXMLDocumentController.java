/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package javafxmlapplication;

import com.sun.javafx.logging.PlatformLogger.Level;
import java.awt.Toolkit;
import java.io.IOException;
import java.lang.System.Logger;
import java.net.URL;
import java.util.List;
import java.util.ResourceBundle;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.fxml.Initializable;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.PasswordField;
import javafx.scene.control.TextField;
import javafx.scene.input.MouseEvent;
import javafx.scene.text.Text;
import javafx.stage.Modality;
import javafx.stage.Stage;
import static javafxmlapplication.JavaFXMLApplication.*;
import model.Club;
import model.ClubDAOException;
import model.Court;
import model.Member;

/**
 *
 * @author jsoler
 */
public class FXMLDocumentController implements Initializable {
    
    @FXML
    private TextField UsernameField;
    @FXML
    private PasswordField PasswordField;
    @FXML
    private Button LoginButton;
    @FXML
    private Button SignupButton;
    @FXML
    private Text errorUsername;
    @FXML
    private Text errorPassword;
    
    //=========================================================
    // you must initialize here all related with the object 
    @Override
    public void initialize(URL url, ResourceBundle rb) {
        /*
        try{
            Club c = Club.getInstance();
            c.setName("Tenis World");
            List<Court> list = c.getCourts();
            list.get(0).setName("North Court");
            list.get(1).setName("South Court");
            list.get(2).setName("West Court");
            list.get(3).setName("East Court");
            list.get(4).setName("Pond Court");
            list.get(5).setName("Mill Court");
        }catch(Exception e){}
        */
    }    

    @FXML
    private void OnClickedLogin() {
        try{
            Club c = Club.getInstance();
            if(c.existsLogin(UsernameField.getText())){
                errorUsername.setText("");
                String password = null;
                try{
                    memberLoggedIn = c.getMemberByCredentials(UsernameField.getText(), PasswordField.getText());
                    password = memberLoggedIn.getPassword();
                }catch(Exception e){errorPassword.setText("Password is wrong or the field is empty.");}
                if(password.equals(PasswordField.getText())){
                    login.close();
                    FXMLLoader fxmlLoader = new FXMLLoader();
                    fxmlLoader.setLocation(FXMLDocumentController.this.getClass().getResource("mainMenu.fxml"));
                    Scene scene = new Scene(fxmlLoader.load());
                    mainScreen = new Stage();
                    mainScreen.setTitle("Main Menu");
                    mainScreen.setScene(scene);
                    mainScreen.centerOnScreen();
                    String css = this.getClass().getResource("/style/style.css").toExternalForm();
                    mainScreen.getScene().getStylesheets().add(css);
                    mainScreen.show();
                    /*
                    errorPassword.setText("");
                    JavaFXMLApplication main = new JavaFXMLApplication();
                    main.changeScene("mainMenu.fxml",1000, 700);
                    */
                }
            }
            else{errorUsername.setText("This user is not registered in our system.");
            errorPassword.setText("");
            PasswordField.setText("");}
        }catch(IOException | NumberFormatException | ClubDAOException e){}
    }

    @FXML
    private void OnClickedSignup() {
        try {
            FXMLLoader fxmlLoader = new FXMLLoader();
            fxmlLoader.setLocation(FXMLDocumentController.this.getClass().getResource("SignupScreen.fxml"));
            Scene scene = new Scene(fxmlLoader.load());
            signup = new Stage();
            signup.setResizable(true);
            signup.setTitle("Sign Up");
            signup.setScene(scene);
            signup.initModality(Modality.APPLICATION_MODAL);
            signup.show();
        }catch (IOException e) {
        }
    }
    
        @FXML
    private void onButtonAvailability(ActionEvent event) throws IOException {
        FXMLLoader fxmlLoader = new FXMLLoader();
        fxmlLoader.setLocation(FXMLDocumentController.this.getClass().getResource("CheckAvailability.fxml"));
        Scene scene = new Scene(fxmlLoader.load());
        checkAvailability = new Stage();
        checkAvailability.setResizable(true);
        checkAvailability.setScene(scene);
        checkAvailability.initModality(Modality.APPLICATION_MODAL);
        checkAvailability.show();
    }

    
}
