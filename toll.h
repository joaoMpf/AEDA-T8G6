#ifndef AEDA_T8G6_TOLL_H
#define AEDA_T8G6_TOLL_H

#include "lane.h"

using namespace std;

class Toll {
protected:
    string name, location;
    vector<Lane> lanes;
    bool exit; //SE FOR TRUE É SAIDA SENAO entrada
    string type1;

public:
    Toll(string n, string loc,bool type, vector<Lane> l):
        name(n), location(loc),exit(type), lanes(l){
        if (exit) {type1="Exit";}
        else type1="Entry";
    }

    ~Toll(){};

    const string &getName() const;

    const string &getLocation() const;

    const vector<Lane> &getLanes() const;

    const string &getType() const;

};


class In : public Toll {

};

class Out : public Toll {

};


#endif //AEDA_T8G6_TOLL_H
