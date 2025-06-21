/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/javafx/FXMLController.java to edit this template
 */
package javafxmlapplication;

import java.io.IOException;
import java.net.URL;
import java.time.LocalDate;
import java.time.LocalTime;
import java.util.ArrayList;
import java.util.List;
import java.util.ResourceBundle;
import java.util.logging.Level;
import java.util.logging.Logger;
import javafx.beans.property.SimpleStringProperty;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.Button;
import javafx.scene.control.ComboBox;
import javafx.scene.control.Label;
import javafx.scene.control.TableColumn;
import javafx.scene.control.TableView;
import static javafxmlapplication.JavaFXMLApplication.checkAvailability;
import static javafxmlapplication.JavaFXMLApplication.date;
import static javafxmlapplication.JavaFXMLApplication.memberLoggedIn;
import javafxmlapplication.MainMenuController.FreeSlots;
import static javafxmlapplication.MainMenuController.*;
import model.Booking;
import model.Club;
import model.ClubDAOException;

/**
 * FXML Controller class
 *
 * @author peres
 */
public class CheckAvailabilityController implements Initializable {

    @FXML
    private ComboBox<String> timeCombo;
    @FXML
    private TableView<Booking> myTableView;
    @FXML
    private TableColumn<Booking, String> hourC;
    @FXML
    private TableColumn<Booking, String> courtC;
    @FXML
    private TableColumn<Booking, String> userC;
    
    public List<Booking> arrayListBooking = new ArrayList<>();
    private ObservableList<Booking> datos = null;
    
    /**
     * Initializes the controller class.
     */
    @Override
    public void initialize(URL url, ResourceBundle rb) {
        myTableView.setPlaceholder(new Label("No reservation has been made yet today!"));

        timeCombo.getItems().addAll("09:00", "10:00", "11:00", "11:00", "12:00", "13:00",
                "14:00","15:00","16:00","17:00","18:00","19:00","20:00","21:00","22:00");
        
        ArrayList<Booking> misdatos = new ArrayList<>();
        datos = FXCollections.observableList(misdatos);
        
        myTableView.setItems(datos);

        hourC.setCellValueFactory(bookCol -> new SimpleStringProperty(bookCol.getValue().getFromTime().toString()));
        courtC.setCellValueFactory(bookCol -> new SimpleStringProperty(bookCol.getValue().getCourt().getName()));
        userC.setCellValueFactory(bookCol -> new SimpleStringProperty(bookCol.getValue().getMember().getNickName()));
        
        try{onAllHours(null);}catch(Exception e){}
    }    

    @FXML
    private void onTimeCombo(ActionEvent event) throws ClubDAOException, IOException {
        datos.clear();
        String timeS = timeCombo.getSelectionModel().getSelectedItem();
        Club c = Club.getInstance();
        List<Booking> bookingListt = c.getForDayBookings(LocalDate.now());
        
        for(int i = 0; i < bookingListt.size(); i++){
            if(bookingListt.get(i).getFromTime().toString().equals(timeS)){
                datos.add(bookingListt.get(i));
            }
        }
    }

    @FXML
    private void onGoBackButton(ActionEvent event) {
        checkAvailability.close();
    }

    @FXML
    private void onAllHours(ActionEvent event) throws ClubDAOException, IOException  {
        datos.clear();
        Club c = Club.getInstance();
        List<Booking> bookingListt = c.getForDayBookings(LocalDate.now());
        for(int i = 0; i < bookingListt.size(); i++){
            datos.add(bookingListt.get(i));
        }
    }
    
}
