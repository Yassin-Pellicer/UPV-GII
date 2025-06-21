/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/javafx/FXMLController.java to edit this template
 */
package javafxmlapplication;

import java.io.File;
import java.io.IOException;
import java.net.URL;
import java.util.ResourceBundle;
import java.util.Set;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.TextField;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.input.MouseEvent;
import javafx.scene.text.Text;
import javafx.stage.FileChooser;
import static javafxmlapplication.JavaFXMLApplication.*;
import static javafxmlapplication.SignUpScreenController.*;
import model.Club;
import model.ClubDAOException;
import model.Member;

/**
 * FXML Controller class
 *
 * @author yassi
 */
public class CheckDataController implements Initializable {

    @FXML
    private Text nameMember;
    @FXML
    private TextField nameField;
    @FXML
    private Text surnameMember;
    @FXML
    private TextField familyNameField;
    @FXML
    private Text phoneMember;
    @FXML
    private TextField phoneField;
    @FXML
    private Text errorPhone;
    @FXML
    private Text usernameMember;
    @FXML
    private TextField userField;
    @FXML
    private Text passwordMember;
    @FXML
    private TextField passwordField;
    @FXML
    private TextField cardField;
    @FXML
    private Text creditCardMember;
    @FXML
    private Text csvMember;
    @FXML
    private TextField csvField;
    @FXML
    private Text errorPassword;
    @FXML
    private Text errorCardNumber;
    @FXML
    private Text signUpSuccessful;
    @FXML
    private Button userIcon;
    @FXML
    private Button doneButton;
    @FXML
    private Button exitButton;
    @FXML
    private Text imagePath;
    @FXML
    private Text errorCSV;
    @FXML
    private ImageView iconMember;
    @FXML
    private Button resetButton;
    @FXML
    private Button cardInfoResetButton;
    
    public boolean resetCard;
    public boolean resetIcon;
    public boolean setIcon;
    public Image defaultIcon = new Image("img/Avatar_icon_green.svg.png");

    /**
     * Initializes the controller class.
     */
    @Override
    public void initialize(URL url, ResourceBundle rb) {
        resetIcon = false;
        resetCard = false;
        setIcon = false;
        
        nameMember.setText(memberLoggedIn.getName());
        surnameMember.setText(memberLoggedIn.getSurname());
        phoneMember.setText(memberLoggedIn.getTelephone());
        usernameMember.setText(memberLoggedIn.getNickName());
        passwordMember.setText(memberLoggedIn.getPassword());
        creditCardMember.setText(memberLoggedIn.getCreditCard());
        csvMember.setText(""+memberLoggedIn.getSvc());
        
        if(memberLoggedIn.getImage() != null){
            iconMember.setImage(memberLoggedIn.getImage());
        }
    }    

    @FXML
    private void onUserIconClicked() {
        FileChooser fc = new FileChooser();
        fc.getExtensionFilters().addAll(new FileChooser.ExtensionFilter("PNG files","*.png"),
        new FileChooser.ExtensionFilter("JPEG files","*.jpeg"),
        new FileChooser.ExtensionFilter("All images","*.jpeg", "*.png"));
        imagePath.setText("Wait while the image is loaded...");
        String prevmessage = signUpSuccessful.getText();
        signUpSuccessful.setText("The image is loading... the screen may be unresponsive.");
        File selectedFile = fc.showOpenDialog(signup);
        
        if(selectedFile != null){
            Image image = new Image(selectedFile.getPath());
            icon = image;
            imagePath.setText("File uploaded successfully!");
            signUpSuccessful.setText(prevmessage);
            setIcon = true;
        }
        else{imagePath.setText("");signUpSuccessful.setText(prevmessage);}
    }

    @FXML
    private void onClickDoneLogin() {
        if(!phoneField.getText().equals("")&&!checkNumber(phoneField.getText())){errorPhone.setText("Non-numeric character introduced.");}
        else{errorPhone.setText("");}

        if(!passwordField.getText().equals("")&&passwordField.getText().length() < 6){errorPassword.setText("Must be at least 6 char. long.");}
        else{errorPassword.setText("");}

        if(!cardField.getText().equals("")&&(!checkNumber(cardField.getText()) || cardField.getText().length() != 16)){errorCardNumber.setText("Incorrect input.");}
        else{errorCardNumber.setText("");}

        if(!csvField.getText().equals("")&&(!checkNumber(csvField.getText())|| csvField.getText().length() != 3)){errorCSV.setText("Incorrect input.");}
        else{errorCSV.setText("");}

        if(errorCardNumber.getText().equals("")&& errorPhone.getText().equals("")&& errorPassword.getText().equals("")
        && errorCSV.getText().equals(""))
        {
            if(!nameField.getText().equals("")){memberLoggedIn.setName(nameField.getText());}
            if(!familyNameField.getText().equals("")){memberLoggedIn.setSurname(familyNameField.getText());}
            if(!passwordField.getText().equals("")){memberLoggedIn.setPassword(passwordField.getText());}
            if(!cardField.getText().equals("")){memberLoggedIn.setCreditCard(cardField.getText());}
            if(!csvField.getText().equals("")){memberLoggedIn.setSvc(Integer.parseInt(csvField.getText()));}
            if(!phoneField.getText().equals("")){memberLoggedIn.setTelephone(phoneField.getText());}
            
            if(setIcon){
                memberLoggedIn.setImage(icon);
                setIcon = false;
            }
            
            if(resetIcon){
                memberLoggedIn.setImage(defaultIcon);
                icon = defaultIcon;
                resetIcon = false;
            }
            
            if(resetCard){        
                memberLoggedIn.setSvc(-1);
                memberLoggedIn.setCreditCard("");
                resetCard = false;
            }
            
            initialize(null, null);

            JavaFXMLApplication c = new JavaFXMLApplication();
            try{
            c.changeScene("mainMenu.fxml", mainScreen, (int) mainScreen.getX(), (int) mainScreen.getY());
            }catch(IOException e){}
            
            signUpSuccessful.setText("Changes applied successfully.");
        }
        else{signUpSuccessful.setText("Solve errors before changing data or resetting card");}
    }

    @FXML
    private void onClickExitButton(ActionEvent event) {
        checkData.close();
    }

    @FXML
    private void onClickResetButton(ActionEvent event) {
        resetIcon = true;
        imagePath.setText("Image reset to default.");
        signUpSuccessful.setText("");
    }

    @FXML
    private void onClickCardInfoReset(ActionEvent event) {
        resetCard = true;
        cardField.setText("");
        csvField.setText("");
        cardField.setPromptText("Card reset");
        csvField.setPromptText("Card reset");
        signUpSuccessful.setText("");
    }
    
}
