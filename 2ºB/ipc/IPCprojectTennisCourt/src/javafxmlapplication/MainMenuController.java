/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/javafx/FXMLController.java to edit this template
 */
package javafxmlapplication;

import java.io.IOException;
import java.net.URL;
import java.time.Duration;
import java.time.LocalDate;
import java.time.LocalDateTime;
import java.time.LocalTime;
import java.util.ArrayList;
import java.util.List;
import java.util.ResourceBundle;
import java.util.function.Function;
import javafx.beans.property.SimpleStringProperty;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.fxml.Initializable;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.DatePicker;
import javafx.scene.control.Label;
import javafx.scene.control.TableColumn;
import javafx.scene.control.TableView;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.text.Text;
import javafx.stage.Modality;
import javafx.stage.Stage;
import static javafxmlapplication.JavaFXMLApplication.*;
import static javafxmlapplication.MyReservationsController.dateNow;
import static javafxmlapplication.MyReservationsController.datetimeB;
import model.Booking;
import model.Club;
import model.ClubDAOException;
import model.Court;

/**
 * FXML Controller class
 *
 * @author yassi
 */
public class MainMenuController implements Initializable {

    @FXML
    private ImageView userPictureBanner;
    @FXML
    private Text usernameFieldBanner;
    @FXML
    private Button signOutButton;
    @FXML
    private Button checkInfoButton;
    @FXML
    private DatePicker dateSelector;
    @FXML
    private Text nameSurnameFieldBanner;
    @FXML
    private Button previousDayB;
    @FXML
    private Button reservationB;
    @FXML
    private Button NorthCourt;
    @FXML
    private Button SouthCourt;
    @FXML
    private Button WestCourt;
    @FXML
    private Button EastCourt;
    @FXML
    private Button PondCourt;
    @FXML
    private Button MillCourt;
    @FXML
    private TableView<Booking> TableList;
    @FXML
    private TableColumn<Booking, String> HourCol;
    @FXML
    private TableColumn<Booking, String> PaidCol;
    @FXML
    private TableColumn<Booking, String> CourtCol;
    @FXML
    private TableColumn<Booking, String> NameCol;
    @FXML
    private TableView<FreeSlots> TableList1;
    @FXML
    private TableColumn<FreeSlots, String> HourCol1;
    @FXML
    private TableColumn<FreeSlots, String> CourtCol1;
    @FXML
    private Button viewAllCourts;
    @FXML
    private Button nextDayB;
    @FXML
    private Text courtSelected;
    @FXML
    private Text DatePrompt;
    @FXML
    private Text ErrorBooking;
    @FXML
    private Button myReservationsButton;
    
    public List<Booking> arrayListBooking = new ArrayList<>();
    public ObservableList<Booking> bookingList = FXCollections.observableArrayList();
    public ObservableList<FreeSlots> availableHours = FXCollections.observableArrayList();

    @Override
    public void initialize(URL url, ResourceBundle rb) {

        usernameFieldBanner.setText("@"+memberLoggedIn.getNickName());
        nameSurnameFieldBanner.setText(memberLoggedIn.getName()+" "+memberLoggedIn.getSurname());
        userPictureBanner.setImage(memberLoggedIn.getImage());
        dateSelector.setValue(date);
        courtSelected.setText(selectedCourtText);
        DatePrompt.setText(date.toString());
        ErrorBooking.setText(bookingStatus);
        TableList.setPlaceholder(new Label("No reservation has been made yet today!"));
        TableList1.setPlaceholder(new Label("No available bookings here..."));
        
        refresh(selectedCourtText);
        
        HourCol1.setCellValueFactory(personaFila->new SimpleStringProperty(personaFila.getValue().getHour()));
        CourtCol1.setCellValueFactory(personaFila->new SimpleStringProperty(personaFila.getValue().getCourt()));
        
        // DateCol.setCellValueFactory(personaFila->new SimpleStringProperty(personaFila.getValue().getBookingDate().toString().substring(0, personaFila.getValue().getBookingDate().toString().length() - 6)));
        HourCol.setCellValueFactory(personaFila->new SimpleStringProperty(personaFila.getValue().getFromTime().toString()));
        PaidCol.setCellValueFactory(personaFila->new SimpleStringProperty(personaFila.getValue().getPaid().toString()));
        CourtCol.setCellValueFactory(personaFila->new SimpleStringProperty(personaFila.getValue().getCourt().getName()));
        NameCol.setCellValueFactory(personaFila->new SimpleStringProperty(personaFila.getValue().getMember().getNickName()));
    }
    
    @FXML
    private void onClickNorthCourt() {
        bookingList.clear();
        selectedCourtText = "North Court";
        try{
            Club c = Club.getInstance();
            arrayListBooking = c.getCourtBookings("North Court", date);
            bookingList = FXCollections.observableArrayList(arrayListBooking);
            TableList.setItems(bookingList);
        }catch(Exception e){}
        courtSelected.setText(selectedCourtText);
        setDefaultSpecificCourt(2);        
    }
    
    @FXML
    private void onClickSouthCourt() {
        bookingList.clear();
        selectedCourtText = "South Court";
        try{
            Club c = Club.getInstance();
            arrayListBooking = c.getCourtBookings("South Court", date);
            bookingList = FXCollections.observableArrayList(arrayListBooking);
            TableList.setItems(bookingList);
        }catch(Exception e){}
        courtSelected.setText(selectedCourtText);
        setDefaultSpecificCourt(4);
    }
    
    @FXML
    private void onClickMillCourt() {
        bookingList.clear();
        selectedCourtText = "Mill Court";
        try{
            Club c = Club.getInstance();
            arrayListBooking = c.getCourtBookings("Mill Court", date);
            bookingList = FXCollections.observableArrayList(arrayListBooking);
            TableList.setItems(bookingList);
        }catch(Exception e){}
        courtSelected.setText(selectedCourtText);
        setDefaultSpecificCourt(1);
    }

    @FXML
    private void onClickWestCourt() {
        bookingList.clear();
        selectedCourtText = "West Court";
        try{
            Club c = Club.getInstance();
            arrayListBooking = c.getCourtBookings("West Court", date);
            bookingList = FXCollections.observableArrayList(arrayListBooking);
            TableList.setItems(bookingList);
        }catch(Exception e){}
        courtSelected.setText(selectedCourtText);
        setDefaultSpecificCourt(5);
    }

    @FXML
    private void onClickEastCourt() {
        bookingList.clear();
        selectedCourtText = "East Court";
        try{
            Club c = Club.getInstance();
            arrayListBooking = c.getCourtBookings("East Court", date);
            bookingList = FXCollections.observableArrayList(arrayListBooking);
            TableList.setItems(bookingList);
        }catch(Exception e){}
        courtSelected.setText(selectedCourtText);
        setDefaultSpecificCourt(0);
    }

    @FXML
    private void onClickPondCourt() {
        bookingList.clear();
        selectedCourtText = "Pond Court";
        try{
            Club c = Club.getInstance();
            arrayListBooking = c.getCourtBookings("Pond Court", date);
            bookingList = FXCollections.observableArrayList(arrayListBooking);
            TableList.setItems(bookingList);
        }catch(Exception e){}
        courtSelected.setText(selectedCourtText);
        setDefaultSpecificCourt(3);
    }
    
    @FXML
    private void onViewAllCourts() {    
        bookingList.clear();
        selectedCourtText = "All Courts";
        try{
            Club c = Club.getInstance();
            arrayListBooking = c.getForDayBookings(date);
            bookingList = FXCollections.observableArrayList(arrayListBooking);
            TableList.setItems(bookingList);
        }catch(Exception e){}
        courtSelected.setText(selectedCourtText);
        setDefaultAll();
    }

    @FXML
    private void onSignOutButtonClicked() {
        date = LocalDate.now();
        ErrorBooking.setText("");
        icon = new Image("img/Avatar_icon_green.svg.png");
        try {
            mainScreen.close();
            FXMLLoader fxmlLoader = new FXMLLoader();
            fxmlLoader.setLocation(MainMenuController.this.getClass().getResource("FXMLDocument.fxml"));
            Scene scene = new Scene(fxmlLoader.load());
            login = new Stage();
            login.setResizable(true);
            login.setTitle("Login");
            login.setScene(scene);
            login.show();
        }catch (IOException e){}
    }

    @FXML
    private void onCheckInfoButtonClicked() {
        ErrorBooking.setText("");
        try {
            FXMLLoader fxmlLoader = new FXMLLoader();
            fxmlLoader.setLocation(MainMenuController.this.getClass().getResource("CheckData.fxml"));
            Scene scene = new Scene(fxmlLoader.load());
            checkData = new Stage();
            checkData.setResizable(true);
            checkData.setTitle("Checking Data");
            checkData.setScene(scene);
            checkData.initModality(Modality.APPLICATION_MODAL);
            checkData.show();
        }catch (IOException e){}
    }
    
    public void setDefaultAll(){
        availableHours.clear();
        
        String[] hours = {"9:00","10:00","11:00",
            "12:00","13:00","14:00","15:00","16:00","17:00","18:00","19:00",
            "20:00","21:00","22:00"};
        
        try{
            Club c = Club.getInstance();
            List<Court> listCourts = c.getCourts();
            arrayListBooking = c.getForDayBookings(date);
            
            for (int i = 0; i < 6; i++) {
                for(int j = 0; j < 14; j++){
                    LocalTime n = LocalTime.of(Integer.parseInt(hours[j].substring(0, hours[j].length()-3)),0);
                    FreeSlots f = new FreeSlots(hours[j], listCourts.get(i).getName(), n);
                    
                    if(LocalDate.now().compareTo(date) <= 0 && !alreadyExistsHour(f)){
                        if(LocalDate.now().compareTo(date) == 0 && LocalTime.now().compareTo(n) < 0) availableHours.add(f);
                        else if (LocalDate.now().compareTo(date) < 0){availableHours.add(f);}
                    }
                    
                    for(int k = 0; k < arrayListBooking.size(); k++){
                        if(arrayListBooking.get(k).getCourt().getName().equals(listCourts.get(i).getName()) &&
                        arrayListBooking.get(k).getFromTime().equals(n)){
                            availableHours.remove(f);
                        }
                    }
                }
            }
        }catch(Exception e){}
        
        TableList1.setItems(availableHours);
        
        HourCol1.setCellValueFactory(personaFila->new SimpleStringProperty(personaFila.getValue().getHour()));
        CourtCol1.setCellValueFactory(personaFila->new SimpleStringProperty(personaFila.getValue().getCourt()));
    }
    
    public void setDefaultSpecificCourt(int i){
        availableHours.clear();
        
        String[] hours = {"9:00","10:00","11:00",
            "12:00","13:00","14:00","15:00","16:00","17:00","18:00","19:00",
            "20:00","21:00","22:00"};
        
        try{
            Club c = Club.getInstance();
            List<Court> listCourts = c.getCourts();
            arrayListBooking = c.getForDayBookings(date);
            
            for(int j = 0; j < 14; j++){
                    LocalTime n = LocalTime.of(Integer.parseInt(hours[j].substring(0, hours[j].length()-3)),0);
                    FreeSlots f = new FreeSlots(hours[j], listCourts.get(i).getName(), n);
                    
                    if(LocalDate.now().compareTo(date) <= 0 && !alreadyExistsHour(f)){
                        if(LocalDate.now().compareTo(date) == 0 && LocalTime.now().compareTo(n) < 0) availableHours.add(f);
                        else if (LocalDate.now().compareTo(date) < 0){availableHours.add(f);}
                    }
                    
                    for(int k = 0; k < arrayListBooking.size(); k++){
                        if(arrayListBooking.get(k).getCourt().getName().equals(listCourts.get(i).getName()) &&
                        arrayListBooking.get(k).getFromTime().equals(n)){
                            availableHours.remove(f);
                        }
                    }
                }
        }catch(Exception e){}
        
        TableList1.setItems(availableHours);
        
        HourCol1.setCellValueFactory(personaFila->new SimpleStringProperty(personaFila.getValue().getHour()));
        CourtCol1.setCellValueFactory(personaFila->new SimpleStringProperty(personaFila.getValue().getCourt()));
    }
    
    @FXML
    private void onDateSelected() {
        String court = courtSelected.getText();
        
        date = dateSelector.getValue();
        DatePrompt.setText(date.toString());
        
        refresh(court);
    }
    
    public boolean isBackToBack(Booking b){
        try{
            Club c = Club.getInstance();
            List<Booking> bookingLists = c.getUserBookings(memberLoggedIn.getNickName());
            if(bookingLists.size() < 3){
                return false;
            }
            else{
                for(int i = 0; i < bookingLists.size(); i++){
                    Booking first = bookingLists.get(i);
                    Booking second =  bookingLists.get(i+1);
                    Booking third = bookingLists.get(i+2);
                    
                    if(first.getMadeForDay().equals(second.getMadeForDay()) &&
                    first.getMadeForDay().equals(third.getMadeForDay()) &&
                    first.getCourt().equals(second.getCourt()) && first.getCourt().equals(third.getCourt())
                    && first.getFromTime().plusHours(1).equals(second.getFromTime())
                    && first.getFromTime().plusHours(2).equals(third.getFromTime())){
                        bookingStatus = "Can't make more than 2 bookings back to back.";
                        ErrorBooking.setText(bookingStatus);
                        return true;
                    }
                }
            }
        }
        catch(Exception e){}
        return false;
    }
    
    public boolean existsOnAnotherCourt(Booking b){
        try{
            Club c = Club.getInstance();
            List<Booking> bookingLists = c.getUserBookings(memberLoggedIn.getNickName());
            for(int i = 0; i < bookingLists.size(); i++){
                if(b.getBookingDate().equals(bookingLists.get(i).getBookingDate())
                && !b.getCourt().equals(bookingLists.get(i).getCourt())){
                    bookingStatus = "Can't book 2 courts at the same hour!";
                    ErrorBooking.setText(bookingStatus);
                    return true;
                }
            }
        }
        catch(Exception e){}
        return false;
    }
    
    public boolean alreadyExistsHour(FreeSlots f){
        try{
            Club c = Club.getInstance();
            List<Booking> bookingLists = c.getUserBookings(memberLoggedIn.getNickName());
        
            for(int i = 0; i < bookingLists.size(); i++){
                if(f.getTime().equals(bookingLists.get(i).getFromTime()) && bookingLists.get(i).getMadeForDay().equals(date)){
                    return true;
                }
            }
        }catch(Exception e){}
        return false;
    }

    @FXML
    private void onMakeReservation() {
        String court  = courtSelected.getText();
        try{
            bookingStatus = "";
            Club c = Club.getInstance();
            Court selected = c.getCourt(TableList1.getSelectionModel().getSelectedItem().getCourt());
            LocalTime t = TableList1.getSelectionModel().getSelectedItem().getTime();
            LocalDateTime datetime = LocalDateTime.of(date, t);
            
            if(datetime != null && t != null && selected != null){
                
                if(datetime.compareTo(LocalDateTime.now()) > 0){
                    Booking b = c.registerBooking(datetime, date, t, false, selected , memberLoggedIn);
                    
                    if(memberLoggedIn.getSvc() == -1 && memberLoggedIn.getCreditCard().equals("")){ b.setPaid(false); }
                    else{b.setPaid(true);}

                    boolean isBackToBack = isBackToBack(b);
                    boolean existsOnAnotherCourt = existsOnAnotherCourt(b);
                    System.out.println(isBackToBack && existsOnAnotherCourt);
                    if(isBackToBack || existsOnAnotherCourt){System.out.println("booking removed"); c.removeBooking(b);}
                    else{
                        bookingStatus = "Booking made successfully!";
                        ErrorBooking.setText(bookingStatus);                   
                    }
                }
                else{
                    bookingStatus = "Cannot make a reservation in the past!";
                    ErrorBooking.setText(bookingStatus);
                }
            }
            else{ErrorBooking.setText("Invalid Selection");}
            
            refresh(court);
            myReservations.close();
        }
        catch(Exception e){}
    }

    @FXML
    private void onMyReservations() throws IOException {
        String court = courtSelected.getText();
        
        refresh(court);
        
        FXMLLoader fxmlLoader = new FXMLLoader(getClass().getResource("myReservations.fxml"));
        Scene scene = new Scene(fxmlLoader.load());
        myReservations = new Stage();
        myReservations.setTitle("Main Menu");
        myReservations.setResizable(true);
        myReservations.setScene(scene);
        myReservations.centerOnScreen();
        myReservations.show();
    }
    
    public class FreeSlots {

        public String getHour() {
            return hour;
        }

        public String getCourt() {
            return court;
        }

        public LocalTime getTime() {
            return time;
        }

       private final String hour;
       private final String court;
       private LocalTime time;

       public FreeSlots(String hour, String court, LocalTime time) {
           this.hour = hour;
           this.court = court;
           this.time = time;
        }
    }
    
    @FXML
    private void onDayplus1() {
        ErrorBooking.setText("");
        String court = courtSelected.getText();
        
        date = date.plusDays(1);
        dateSelector.setValue(date);
        DatePrompt.setText(date.toString());
        
        refresh(court);
    }

    @FXML
    private void onDayminus1() {
        ErrorBooking.setText("");
        String court = courtSelected.getText();
        
        date = date.minusDays(1);
        dateSelector.setValue(date);
        DatePrompt.setText(date.toString());
        
        refresh(court);
    }
    
    public void refresh(String t){
        String court = t;
        
        switch (court){
            case "North Court":
                onClickNorthCourt();
            break;
            case "South Court":
                onClickSouthCourt();
            break;
            case "West Court":
                onClickWestCourt();
            break;
            case "East Court":
                onClickEastCourt();
            break;
            case "Pond Court":
                onClickPondCourt();
            break;
            case "Mill Court":
                onClickMillCourt();
            break;
            case "All Courts":
                onViewAllCourts();
        }
    }
}
