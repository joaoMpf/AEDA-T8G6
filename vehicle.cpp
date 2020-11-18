#include "vehicle.h"

const string &Vehicle::getLicensePlate() const {
    return licensePlate;
}

int Vehicle::getCategory() const {
    return category;
}

bool Vehicle::operator==(const Vehicle &rhs) const {
    return licensePlate == rhs.licensePlate;
}

bool Vehicle::operator!=(const Vehicle &rhs) const {
    return !(rhs == *this);
}

void Vehicle::startTrip(Toll *toll, Time *time) {
    if (!trips.empty() && !trips[trips.size() - 1]->isFinished()) {
        cout << "VEHICLE IS ALREADY IN A TRIP. "
             << "VEHICLE MUST PASS THROUGH AN EXIT TOLL "
             << "BEFORE ENTERING AGAIN\n";
        return;
    }
    trips.push_back(new Trip(toll, time));
}

double Vehicle::endTrip(Toll *toll, Time *time) {
    if ((!trips.empty() && trips[trips.size() - 1]->isFinished())) {
        cout << "VEHICLE NEVER ENTERED OR ALREADY EXITED.\n";
        return -1;
    }
    trips[trips.size() - 1]->setEnd(toll);
    trips[trips.size() - 1]->setEndTime(time);

    double price = 5.0;
    return price;
}

void Vehicle::printTrips() {
    if(!trips.empty()) {
        for (auto x:trips) {
            cout << "Trip Info:\n"
                 << "Started at: " <<
                 x->getBeginTime()->getHour() << ":" <<
                 x->getBeginTime()->getMinute() << ":"
                 << x->getBeginTime()->getSecond() << endl
                 << "Ended at: " <<
                 x->getEndTime()->getHour() << ":" <<
                 x->getEndTime()->getMinute() << ":"
                 << x->getEndTime()->getSecond() << endl;
        }
    }
    else{
        cout<<"NO TRIPS TO SHOW"<<endl<<endl;
    }
}

Vehicle::Vehicle(const string &licensePlate) : licensePlate(licensePlate) {}

Vehicle::Vehicle(const string &licensePlate, int category, bool viaVerde) : licensePlate(licensePlate),
                                                                            category(category), viaVerde(viaVerde) {}

bool Vehicle::isViaVerde() const{
    return viaVerde;
}

void Vehicle::printInfo() {
    cout<<"LICENSE PLATE: "<<licensePlate<<endl;
    cout<<"CATEGORY: "<<category<<endl;
    cout<<"VIA VERDE: ";
    if(viaVerde){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }

}

void Vehicle::addPayment(double price) {
    trips[trips.size()-1]->setPrice(price);
}

void Vehicle::changeViaVerde() {
    viaVerde=!viaVerde;
}

vector<Trip *> Vehicle::getTrips() {
    return trips;
}

Trip * Vehicle::getLastTrip() {
    return trips[trips.size()-1];
}