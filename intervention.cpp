//
// Created by Pedro Figueiredo on 26/12/2020.
//

#include "intervention.h"

Intervention::Intervention(Time* date, Toll* toll, InterventionType type) : date(date), toll(toll), type(type) {
    duration = 0; done = false;
}

double Intervention::setDuration(double dur) {
    duration = dur;
}

bool Intervention::operator<(const Intervention &rhs) const {
    if( *date == *rhs.date)
        if( this->toll->getName() == rhs.toll->getName())
            return this->type < rhs.type;
        else
            return this->toll->getName() == rhs.toll->getName();
    else return (*date < *rhs.date);
}

bool Intervention::operator==(const Intervention &rhs) const {
    return date == rhs.date &&
           toll == rhs.toll &&
           type == rhs.type;
}

Time *Intervention::getDate() const {
    return date;
}

void Intervention::setDone(bool done) {
    Intervention::done = done;
}

Revision::Revision(Time *date, Toll *toll, InterventionType type = RevisionIntervention): Intervention(date, toll, type){}

Repair::Repair(Time *date, Toll *toll, InterventionType type): Intervention(date, toll, type) {}

InformaticRepair::InformaticRepair(Time *date, Toll *toll, InterventionType type = InformaticIntervention):Repair(date, toll, type) {}

ElectronicRepair::ElectronicRepair(Time *date, Toll *toll, InterventionType type = ElectronicIntervention):Repair(date,toll,type) {}

InvalidInterventionDate::InvalidInterventionDate(Time* time) {}

InvalidInterventionType::InvalidInterventionType(int type) {}
