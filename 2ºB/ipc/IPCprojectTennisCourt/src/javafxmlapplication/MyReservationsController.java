/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/javafx/FXMLController.java to edit this template
 */
package javafxmlapplication;

import java.io.IOException;
import java.net.URL;
import java.time.Duration;
import java.time.LocalDateTime;
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
import javafx.scene.control.TableColumn;
import javafx.scene.control.TableView;
import javafx.scene.text.Text;
import static javafxmlapplication.JavaFXMLApplication.*;
import model.Booking;
import model.Club;
import model.ClubDAOException;

/**
 * FXML Controller class
 *
 * @author angel
 */
public class MyReservationsController implements Initializable {

    @FXML
    private Button deleteReservationB;
    @FXML
    private Button exitB;
    @FXML
    private TableView<Booking> tableList2;
    @FXML
    private TableColumn<Booking, String> dateCol;
    @FXML
    private TableColumn<Booking, String> hourCol;
    @FXML
    private TableColumn<Booking, String> paidCol;
    @FXML
    private TableColumn<Booking, String> courtCol;
    @FXML
    private Text errorB;

    public static LocalDateTime dateNow = LocalDateTime.now();
    public static LocalDateTime datetimeB = null;

    /**
     * Initializes the controller class.
     */
         public List<Booking> books= new ArrayList<>();
         public ObservableList<Booking> myBookings = FXCollections.observableArrayList();

    
    @Override
    public void initialize(URL url, ResourceBundle rb) {
        try {
        Club c = Club.getInstance();
        books = c.getUserBookings(memberLoggedIn.getNickName());
        filter();
        
        hourCol.setCellValueFactory(personaFila->new SimpleStringProperty(personaFila.getValue().getFromTime().toString()));
        paidCol.setCellValueFactory(personaFila->new SimpleStringProperty(personaFila.getValue().getPaid().toString()));
        courtCol.setCellValueFactory(personaFila->new SimpleStringProperty(personaFila.getValue().getCourt().getName()));
        dateCol.setCellValueFactory(personaFila->new SimpleStringProperty(personaFila.getValue().getMadeForDay().toString()));
        
        tableList2.setItems(myBookings);
        }
        catch(Exception e){}
    }
    
    public void filter(){
        for(int i = 0; i < books.size(); i++){
            if(books.get(i).getBookingDate().compareTo(dateNow) > 0){
                myBookings.add(books.get(i));
            }
        }
    }

    @FXML
    private void onDeleteReservation() {
        if(books.isEmpty() || tableList2.getSelectionModel().getSelectedIndex() == -1){            
            bookingStatus = "Invalid selection.";
            errorB.setText(bookingStatus);
            return;
        }
        
        deleteReservationB.requestFocus();
        datetimeB = tableList2.getSelectionModel().getSelectedItem().getBookingDate();
        Duration duracion = Duration.between(dateNow, datetimeB);

        if (duracion.getSeconds() < 86400) {
            bookingStatus = "Can't delete the reservation, it's within the 24-hour threshold!";
            errorB.setText(bookingStatus);
        }
        else{
            try{
                bookingStatus = "";
                errorB.setText(bookingStatus);
                Booking book = tableList2.getSelectionModel().getSelectedItem();
                
                Club club = Club.getInstance();

                boolean k = club.removeBooking(book);
                // System.out.println(k);
                myBookings.remove(book);
                // System.out.println(book.getMadeForDay()+", "+book.getCourt().getName()+", "+book.getBookingDate()+", "+book.toString()+", "+book.getBookingDate());
                // System.out.println();
                
                tableList2.setItems(myBookings);
                JavaFXMLApplication c = new JavaFXMLApplication();
                c.changeScene("mainMenu.fxml", mainScreen, (int) mainScreen.getX(), (int) mainScreen.getY());
            }catch(IOException | ClubDAOException e){ e.printStackTrace();}
        }
    }

    @FXML
    private void onExit(ActionEvent event) {
        myReservations.close();
    }
    
}
