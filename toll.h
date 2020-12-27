#ifndef AEDA_T8G6_TOLL_H
#define AEDA_T8G6_TOLL_H

#include <utility>
#include <vector>
#include <iostream>
#include <cstdio>
#include "lane.h"
#include "algorithm"
#include "technician.h"

using namespace std;

typedef priority_queue<Technician> TechnicianQueue;

///Contains info about a Toll, such as name, location, position, price and lanes
///
///Parent of InToll and OutToll
///@see Lane
class Toll {
protected:
    ///Toll name
    string name;
    ///Toll location
    string location;
    ///Lanes of the Toll
    vector<Lane *> lanes;
    ///Position within the Highway
    ///
    ///@note for example, a Toll might be at kilometer 0 of the Highway or at kilometer 20 of the Highway
    int position; // this is the position within the highway ex: position = 0km, or 15km, etc
    ///Price corresponds to the distance between the beginning of Highway until current toll
    double price;
    ///Technicians associated to this toll
    TechnicianQueue technicians;

public:
    ///Creates Toll with undefined private attributes
    Toll();

    ///Creates a Toll with name, location, lanes, position and price\n
    ///lanes is a vector of pointers to Lane
    ///@see Lane
    Toll(string n, string loc, vector<Lane *> l, int pos, double pri) :
            name(std::move(n)), location(std::move(loc)), lanes(std::move(l)),
            position(std::move(pos)), price(pri) {};

    ///Destructor
    ~Toll() = default;

    ///Returns Toll name
    ///
    /// \return Toll name
    const string &getName() const;

    ///Returns Toll location
    ///
    /// \return Toll location
    const string &getLocation() const;

    ///Returns Toll's Lanes
    ///
    /// \return Toll's Lanes
    const vector<Lane *> &getLanes() const;

    virtual bool isExitToll() const { return false; };

    ///Returns Recommended Lane
    ///
    /// \param isViaVerde
    /// \return pointer to Lane
    Lane *getRecommendedLane(bool isViaVerde);

    ///Adds a new Technician
    ///
    /// \param technicianSpecialty specifies the technicians' specialty
    void addNewTechnician(int technicianSpecialty);

    ///Adds back a technician who was working
    ///
    /// \param technician1 is the technician in question
    void addTechnician(Technician technician1);

    ///Returns a technician for a repair if no technician is available returns NULL
    ///
    /// \param technicianSpecialty specifies the technicians' specialty
    Technician getTechnician(int technicianSpecialty);

    ///Returns ViaVerde Lanes or Normal Lanes as specified by isViaVerde
    ///
    /// \param isViaVerde specifies the type of Lanes to return
    /// \return ViaVerde Lanes or Normal Lanes
    vector<Lane *> getTypeLanes(bool isViaVerde);

    ///Returns ViaVerde Lanes
    vector<Lane *> getViaVerdeLanes();

    ///Returns Normal Lanes
    vector<Lane *> getNormalLanes();

    ///Returns Toll price
    ///
    /// \return price
    ///@note price returned corresponds to the distance between the previous toll and this one
    double getPrice() const;

    ///Adds Lane to Toll
    void addLane(Lane *lane);

    ///Removes Lane at index i
    ///
    /// \param i index
    void removeLaneAt(int i);

    ///Sets Toll Name
    ///
    /// \param basicString
    void setName(const string &basicString);

    ///Sets Toll Location
    ///
    /// \param basicString
    void setLocation(const string &basicString);

    ///Sets Toll Lanes
    ///
    /// \param lanes
    void setLanes(const vector<Lane *> &lanes);

    ///Sets Toll Position
    ///
    /// \param i
    void setPosition(int i);

    ///Sets Toll Price
    ///
    /// \param d
    void setPrice(double d);

    ///Returns ostream with Toll info
    ///
    /// \param os ostream
    /// \param toll
    /// \return ostream with the Toll's type, name, location, number of lanes, position and price
    friend ostream &operator<<(ostream &os, const Toll &toll);

    ///Returns istream with Toll info
    ///
    /// \param is istream
    /// \param toll
    /// \return istream with the Toll's type, name, location, number of lanes, position and price
    friend istream &operator>>(istream &is, Toll &toll);

    ///Adds ViaVerdeLane to Toll
    void addLane(ViaVerdeLane *lane);

    ///Prints Toll with index
    ///
    /// \param i index
    ///@note Prints toll at index i of the Highway's tolls vector
    void printTollNumbered(int i) const;

    ///Shows Toll's Lanes
    void viewLanes() const;

    istream &loadFromFile(istream &is);

    virtual Lane *loadLaneFromFile(istream &istream) { return nullptr; };
};

///Entry Toll
///
///Child of Toll
class InToll : public Toll {
public:
    InToll();

    InToll(const string &n, const string &loc, const vector<Lane *> &l, const int &pos, const double &price);

    bool isExitToll() const override;

    Lane *loadLaneFromFile(istream &is) override;
};

///Exit Toll
///
///Child of Toll
class OutToll : public Toll {
public:
    OutToll();

    OutToll(const string &n, const string &loc, const vector<Lane *> &l, const int &pos, const double &price);

    bool isExitToll() const override;

    Lane *loadLaneFromFile(istream &is) override;
};


#endif //AEDA_T8G6_TOLL_H
