//
// Created by Pedro Figueiredo on 26/12/2020.
//

#ifndef PORTAGENS_TECHNICIAN_H
#define PORTAGENS_TECHNICIAN_H


#include "intervention.h"
enum TechnicianSpecialty{
    RevisionTechnician = 0,
    EletronicTechnician = 1,
    InformaticTechnician = 2
};

class Technician {
    ///Uses emumerate TechnicianSpecialty
    TechnicianSpecialty specialty;
    ///Vector of pointers to previous Interventions
    vector<Intervention*> previousInterventions;
    ///Performance is the average repair time in hours
    int performance;
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
