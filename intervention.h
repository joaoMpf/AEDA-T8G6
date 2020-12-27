//
// Created by Pedro Figueiredo on 26/12/2020.
//

#ifndef PORTAGENS_INTERVENTION_H
#define PORTAGENS_INTERVENTION_H

#include "toll.h"

enum InterventionType{
    RevisionIntervention = 0,
    ElectronicIntervention = 1,
    InformaticIntervention = 2
};

class Intervention {
private:
    ///Initial Date in the format [day, month, year]
    int date[3]; // [dia, mes, ano]
    ///Duration in hours
    double duration; //
    ///Pointer to Toll
    Toll* toll;
    ///Uses enumerate InterventionType
    InterventionType type;
public:
    Intervention(int *date, double duration, Toll *toll, int type);
    double getDuration(){return duration;}
};

class Revision: public Intervention{
public:
    Revision(int *date, double duration, Toll *toll, int interventionType);
};

class Repair: public Intervention{
public:
    Repair(int *date, double duration, Toll *toll, int interventionType);
};

class ElectronicRepair: public Repair{
public:
    ElectronicRepair(int *date, double duration, Toll *toll, int interventionType);
};

class InformaticRepair: public Repair{
public:
    InformaticRepair(int *date, double duration, Toll *toll, int interventionType);
};


class InvalidInterventionDate{
public:
    InvalidInterventionDate(int date[3]);
};

class InvalidInterventionType{
public:
    InvalidInterventionType(int type);

};

#endif //PORTAGENS_INTERVENTION_H
