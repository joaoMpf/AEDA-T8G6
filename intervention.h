//
// Created by Pedro Figueiredo on 26/12/2020.
//

#ifndef PORTAGENS_INTERVENTION_H
#define PORTAGENS_INTERVENTION_H

#include "toll.h"
#include "time.h"

enum InterventionType{
    RevisionIntervention = 0,
    ElectronicIntervention = 1,
    InformaticIntervention = 2
};

class Intervention {
private:
    ///Initial Date using class Time
    ///
    ///Hour, minute and second are not used here
    Time* date;
    ///Duration in hours
    double duration; //
    ///Pointer to Toll
    Toll* toll;
    ///Uses enumerate InterventionType
    InterventionType type;
    ///True is the Intervention was done
    ///
    ///Is false when the Intervention is initially scheduled
    bool done;
public:
    Intervention(Time *date, Toll * toll, InterventionType type);
    double setDuration(double dur);
    double getDuration(){return duration;}

    void setDone(bool done);

    Time *getDate() const;

    bool operator<(const Intervention &rhs) const;

    bool operator==(const Intervention &rhs) const;
};

class Revision: public Intervention{
public:
    Revision(Time *date, Toll *toll, InterventionType type);
};

class Repair: public Intervention{
public:
    Repair(Time *date, Toll *toll, InterventionType type);
};

class ElectronicRepair: public Repair{
public:
    ElectronicRepair(Time *date, Toll *toll, InterventionType type);
};

class InformaticRepair: public Repair{
public:
    InformaticRepair(Time *date, Toll *toll, InterventionType type);
};


class InvalidInterventionDate{
public:
    InvalidInterventionDate(Time* time);
};

class InvalidInterventionType{
public:
    InvalidInterventionType(int type);
}

class InterventionNotFound{
private:
    Intervention* i;
public:
    InterventionNotFound(Intervention* i);
};

#endif //PORTAGENS_INTERVENTION_H
