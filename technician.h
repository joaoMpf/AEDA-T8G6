#ifndef PORTAGENS_TECHNICIAN_H
#define PORTAGENS_TECHNICIAN_H


enum TechnicianSpecialty{
    RevisionTechnician = 0,
    EletronicTechnician = 1,
    InformaticTechnician = 2
};

class Technician {
    ///Uses emumerate TechnicianSpecialty
    int specialty;
    ///Performance is the average repair time in hours
    double performance;
    int interventionCount;
public:
    Technician(){}
    Technician(int type):specialty(type){}
    int getSpecialty() const {return specialty;}
    double getPerformance(){return performance;}
    void addIntervention(int time);
    bool operator<(const Technician o1) const;
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