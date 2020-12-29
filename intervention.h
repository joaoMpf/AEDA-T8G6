//
// Created by Pedro Figueiredo on 26/12/2020.
//

#ifndef PORTAGENS_INTERVENTION_H
#define PORTAGENS_INTERVENTION_H
#include "toll.h"
#include "bst.h"

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
    int duration; //
    ///Pointer to Toll
    Toll* toll;
    ///Uses enumerate InterventionType
    InterventionType type;

    bool done;
public:
    int getDuration() const;
    void setDuration(int duration);

    void setDone(bool done);

    Intervention(){};

    Intervention(int *date, Toll *toll, int type);

    bool operator==(const Intervention &rhs) const;
    bool operator!=(const Intervention &rhs) const;
    bool operator<(const Intervention &rhs) const;
};



class Revision: public Intervention{
public:
    Revision(int *date, Toll *toll);
};

class Repair: public Intervention{
public:
    Repair(int *date, Toll *toll, int interventionType);
};

class ElectronicRepair: public Repair{
public:
    ElectronicRepair(int *date, Toll *toll);
};

class InformaticRepair: public Repair{
public:
    InformaticRepair(int *date, Toll *toll);
};


class InvalidInterventionDate{
public:
    InvalidInterventionDate(int date[3]);
};

class InvalidInterventionType{
public:
    InvalidInterventionType(int type);

};

class InterventionNotFound{
    Intervention* inter;
public:
    InterventionNotFound(Intervention* inter): inter(inter){};

};

class InterventionTree {
    BST<Intervention> interventions;
public:
    InterventionTree(): interventions(Intervention()){};
    void insert(Intervention inter);
    Intervention find(Intervention inter);
    bool remove(Intervention inter);
    const BST<Intervention> &getInterventions() const;
};

#endif //PORTAGENS_INTERVENTION_H
