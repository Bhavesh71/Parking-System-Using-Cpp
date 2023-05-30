#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// Maximum number of parking slots
int MAX_SLOTS = 27;

struct Vehicle{
    string licensePlate;
    string brand;
};

// Creating a displaymenu function to display the operations available to choose
void displayMenu(){
    cout<<"  PARKING SYSTEM  "<<endl;
    cout<<"1. Vehicle Entry"<<endl;
    cout<<"2. Vehicle Exit"<<endl;
    cout<<"3. View Free Slots"<<endl;
    cout<<"4. Exit"<<endl;
    cout<<endl;
    cout<<"ENTER THE OPTION: ";
}

// Creating a vehicleentry function to book a slot for the vehicles entering
void vehicleEntry(Vehicle parkingLot[]){
    for (int i = 0; i<MAX_SLOTS; i++){
        if(parkingLot[i].licensePlate.empty()){
            cout<<"Enter License Plate: ";
            cin>>parkingLot[i].licensePlate;
            cout<<"Enter Vehicle Brand: ";
            cin>>parkingLot[i].brand;
            cout<<"Vehicle parked at slot "<<i + 1<<endl;
            return;
        }
    }
    cout<<"Parking lot is full. No free slots available."<<endl;
}

// Creating a vehicleexit function to remove the vehicle from the booked slot when it exit
void vehicleExit(Vehicle parkingLot[]){
    string licensePlate;
    cout<<"Enter License Plate: ";
    cin>>licensePlate;

    for(int i = 0; i < MAX_SLOTS; i++){
        if(parkingLot[i].licensePlate == licensePlate){
            cout<<"Vehicle with license plate "<<licensePlate<<" exited from slot "<<i + 1<<endl;
            parkingLot[i].licensePlate = "";
            parkingLot[i].brand = "";
            return;
        }
    }
    cout<<"Vehicle with license plate "<<licensePlate<<" not found in any slot."<<endl;
}

// Creating a viewfreeslots function to display overall parking lot map and free slots available
void viewFreeSlots(const Vehicle parkingLot[]){
    cout<<"Free Slots: "<<endl;
    cout<<"+----+----+----+  "<<"+----+----+----+  "<<"+----+----+----+"<<endl;
    cout<<"| 1  | 2  | 3  |  "<<"| 10 | 11 | 12 |  "<<"| 19 | 20 | 21 |"<<endl;
    cout<<"+----+----+----+  "<<"+----+----+----+  "<<"+----+----+----+"<<endl;
    cout<<"| 4  | 5  | 6  |  "<<"| 13 | 14 | 15 |  "<<"| 22 | 23 | 24 |"<<endl;
    cout<<"+----+----+----+  "<<"+----+----+----+  "<<"+----+----+----+"<<endl;
    cout<<"| 7  | 8  | 9  |  "<<"| 16 | 17 | 18 |  "<<"| 25 | 26 | 27 |"<<endl;
    cout<<"+----+----+----+  "<<"+----+----+----+  "<<"+----+----+----+"<<endl;


    cout<<"Available Slots: ";
    bool found = false;

    for(int i = 0; i < MAX_SLOTS; i++){
        if (parkingLot[i].licensePlate.empty()){
            cout<<"["<<i + 1 <<"] ";
            found = true;
        }
    }

    if(!found){
        cout<<"No free slots available.";
    }

    cout<<endl;
}

// Main
int main(){
    Vehicle parkingLot[MAX_SLOTS];
    int opt;

    // Getting the input from the user and doing the certain operations
    while(true){
        displayMenu();
        cin >> opt;

        switch(opt){
            case 1:
                vehicleEntry(parkingLot);
                break;

            case 2:
                vehicleExit(parkingLot);
                break;

            case 3:
                viewFreeSlots(parkingLot);
                break;

            case 4:
                cout<<"Exiting the program."<<endl;
                return 0;
                
            default:
                cout<<"Invalid option. Please try again."<<endl;
                break;
        }
        
        cout<<endl;
    }
}
