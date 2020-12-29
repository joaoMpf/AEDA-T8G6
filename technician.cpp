//
// Created by Pedro Figueiredo on 26/12/2020.
//

#include "technician.h"

RevisionTechnician::RevisionTechnician() {}

EletronicTechnician::EletronicTechnician() {}

InformaticTechnician::InformaticTechnician() {}

InvalidTechnicianType::InvalidTechnicianType(int type) {}

void Technician::addIntervention(int time) {
    performance=((performance*interventionCount)+time)/(interventionCount+1);
    interventionCount++;
}

bool Technician::operator<(const Technician o1) const {
    return performance<o1.performance;
}
