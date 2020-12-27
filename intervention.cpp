//
// Created by Pedro Figueiredo on 26/12/2020.
//

#include "intervention.h"

Intervention::Intervention(int date[3], double duration, Toll *toll, int interventionType) : duration(duration),
                                                                                        toll(toll), type(type) {
    this->date[0] = date[0];
    this->date[1] = date[1];
    this->date[2] = date[2];
}

Revision::Revision(int *date, double duration, Toll *toll, int interventionType) : Intervention(date, duration, toll,
                                                                                             interventionType) {}

Repair::Repair(int *date, double duration, Toll *toll, int interventionType) : Intervention(date, duration, toll,
                                                                                         interventionType) {}

ElectronicRepair::ElectronicRepair(int *date, double duration, Toll *toll, int interventionType) : Repair(date, duration,
                                                                                                       toll,
                                                                                                       interventionType) {}

InformaticRepair::InformaticRepair(int *date, double duration, Toll *toll, int interventionType) : Repair(date, duration,
                                                                                                       toll,
                                                                                                       interventionType) {}

InvalidInterventionDate::InvalidInterventionDate(int date[3]) {}

InvalidInterventionType::InvalidInterventionType(int type) {}
