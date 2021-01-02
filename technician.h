#ifndef PORTAGENS_TECHNICIAN_H
#define PORTAGENS_TECHNICIAN_H
using namespace std;
#include "iostream"

enum TechnicianSpecialty{
    RevisionTechnician = 0,
    EletronicTechnician = 1,
    InformaticTechnician = 2
};

class Technician {
    ///Uses emumerate TechnicianSpecialty
    int specialty;
    ///Performance is the average repair time in hours
    double performance=0;
    int interventionCount=0;
public:
    Technician(){}
    Technician(int type):specialty(type){}
    void setSpecialty(int spec);
    void setInterventionCount(int iC);
    void setPerformance(double p);
    int getSpecialty() const {return specialty;}
    double getPerformance(){return performance;}
    void addIntervention(int time);
    bool operator<(const Technician o1) const;
    friend ostream &operator<<(ostream &os, const Technician &technician);
    friend istream &operator>>(istream &is,Technician &technician);
};

class RevisionTechnician: public Technician{
public:
    RevisionTechnician();
};

class EletronicTechnician: public Technician{
public:
    EletronicTechnician();
};

class InformaticTechnician: public Technician{
public:
    InformaticTechnician();
};

class InvalidTechnicianType{
public:
    InvalidTechnicianType(int type);
};

#endif //PORTAGENS_TECHNICIAN_H