#include <iostream>
#include <string>

using namespace std;

class Station {
private:
    string stationName;
    int price;

public:
    Station(string name, int p) {
        stationName = name;
        price = p;
    }

    void displayStationInfo(int index) {
        cout << index << ". " << stationName << " - Price: " << price << endl;
    }

    string getStationName() {
        return stationName;
    }

    int getPrice() {
        return price;
    }
};

class MetroSystem {
public:
    void displayStations(Station s1, Station s2, Station s3, Station s4, Station s5, Station s6) {
        s1.displayStationInfo(1);
        s2.displayStationInfo(2);
        s3.displayStationInfo(3);
        s4.displayStationInfo(4);
        s5.displayStationInfo(5);
        s6.displayStationInfo(6);
    }

    void getRouteAndSlip(Station station) {
        cout << "Please pay small money. If you have, give coin of 5." << endl;
        cout << "Route Number: OML-001" << endl;
        cout << "Has the slip been given? (yes/no): ";
        string slip;
        cin >> slip;
        if (slip == "yes") {
            cout << "Thank you for using Orange Metro Line!" << endl;
        } else {
            cout << "Please collect your slip from the counter." << endl;
        }
    }

    void rechargeCard() {
        int amount;
        cout << "Please use only Rs.10, 20, 50, 100 notes. No other notes accepted separately." << endl;
        cout << "Enter amount to recharge: ";
        cin >> amount;

        if (amount < 10) {
            cout << "Please enter a valid amount (10 or above)." << endl;
        } else if (amount == 1000) {
            string reply;
            cout << "Do you have 10 notes of Rs.100? (yes/no): ";
            cin >> reply;
            if (reply == "yes") {
                cout << "Recharge successful! Your card has been recharged with Rs. 1000." << endl;
            } else {
                cout << "Please go and get change of Rs.1000 in Rs.100 notes." << endl;
            }
        } else {
            cout << "Recharge successful! Your card has been recharged with Rs. " << amount << "." << endl;
        }
    }
};

int main() {
    MetroSystem metroSystem;

    Station s1("Thokar Niaz Baig", 45);
    Station s2("Ali Town", 50);
    Station s3("Shalimar Garden", 35);
    Station s4("Railway Station", 60);
    Station s5("Town Ship", 50);
    Station s6("Wapda Town", 40);

    int choice;
    cout << "Welcome to Orange Metro Line Service\n";
    cout << "1. Recharge Metro Card\n";
    cout << "2. Buy Token\n";
    cout << "Enter your choice (1 or 2): ";
    cin >> choice;

    if (choice == 1) {
        metroSystem.rechargeCard();
    } else if (choice == 2) {
        cout << "Select your destination station:" << endl;
        metroSystem.displayStations(s1, s2, s3, s4, s5, s6);

        int stationChoice;
        cout << "Enter your choice: ";
        cin >> stationChoice;

        Station selectedStation = s1;
        switch (stationChoice) {
            case 1: selectedStation = s1;
             break;
            case 2: selectedStation = s2; 
            break;
            case 3: selectedStation = s3;
             break;
            case 4: selectedStation = s4;
             break;
            case 5: selectedStation = s5;
             break;
            case 6: selectedStation = s6;
             break;
            default:
                cout << "Invalid station choice. Please try again." << endl;
                return 1;
        }

        cout << "You have selected " << selectedStation.getStationName() << endl;
        cout << "Price: Rs. " << selectedStation.getPrice() << endl;
        metroSystem.getRouteAndSlip(selectedStation);
    } else {
        cout << "Invalid input. Please enter 1 or 2." << endl;
    }

    return 0;
}
