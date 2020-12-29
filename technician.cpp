//
// Created by Pedro Figueiredo on 26/12/2020.
//

#include "technician.h"

RevisionTechnician::RevisionTechnician() {}

EletronicTechnician::EletronicTechnician() {}

InformaticTechnician::InformaticTechnician() {}

InvalidTechnicianType::InvalidTechnicianType(int type) {}

void Technician::addIntervention(Intervention *intervention1) {
    performance=(previousInterventions.size()*performance+intervention1->getDuration())/(previousInterventions.size()+1);
    previousInterventions.push_back(intervention1);
}
