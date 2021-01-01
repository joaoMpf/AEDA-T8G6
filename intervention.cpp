//
// Created by Pedro Figueiredo on 26/12/2020.
//

#include "intervention.h"

Intervention::Intervention(int date[3], Toll *toll, int interventionType) : duration(0), toll(toll), type(type), done(false) {
    this->date[0] = date[0];
    this->date[1] = date[1];
    this->date[2] = date[2];
}

int Intervention::getDuration() const {
    return duration;
}

bool Intervention::operator==(const Intervention &rhs) const {
    return date == rhs.date && toll == rhs.toll && type == rhs.type;
}

bool Intervention::operator<(const Intervention &rhs) const {
    if( *date == *rhs.date)
        if( this->toll->getName() == rhs.toll->getName())
            return this->type < rhs.type;
        else
            return this->toll->getName() == rhs.toll->getName();
    else return (*date < *rhs.date);
}

bool Intervention::operator!=(const Intervention &rhs) const {
    return !(*this == rhs);
}

void Intervention::setDuration(int duration) {
    Intervention::duration = duration;
}

void Intervention::setDone(bool done) {
    Intervention::done = done;
}


void Intervention::setType(int type) {
    Intervention::type = type;
}

void Intervention::setTollName(string name) {
    toll->setName(name);
}

void Intervention::setDate(int date[3]) {
    *Intervention::date = *date;
}
ostream &operator<<(ostream &os, const Intervention &intervention) {
    os << intervention.date[0] << " " << intervention.date[1] << "" << intervention.date[2] <<" "<< intervention.duration
    <<" "<< intervention.toll->getName() <<" "<< intervention.type << " " << intervention.done;
    return os;
}

void Intervention::setToll(Toll *toll) {
    Intervention::toll = toll;
}

Toll *Intervention::getToll() const {
    return toll;
}


Revision::Revision(int *date, Toll *toll) : Intervention(date, toll, RevisionIntervention) {}

Repair::Repair(int *date, Toll *toll, int interventionType) : Intervention(date, toll,
                                                                                         interventionType) {}

ElectronicRepair::ElectronicRepair(int *date, Toll *toll) : Repair(date, toll, ElectronicIntervention) {}

InformaticRepair::InformaticRepair(int *date, Toll *toll) : Repair(date, toll, InformaticIntervention) {}

InvalidInterventionDate::InvalidInterventionDate(int date[3]) {}

InvalidInterventionType::InvalidInterventionType(int type) {}

void InterventionTree::insert(Intervention inter) {
    interventions.insert(inter);
}

Intervention InterventionTree::find(Intervention inter) {
    return interventions.find(inter);
}

bool InterventionTree::remove(Intervention inter) {
    return interventions.remove(inter);
}

const BST<Intervention> &InterventionTree::getInterventions() const {
    return interventions;
}

bool InterventionTree::isEmpty() {
    return interventions.isEmpty();
}
