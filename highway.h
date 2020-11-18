//
// Created by Pedro Figueiredo on 11/11/2020.
//

#ifndef PORTAGENS_HIGHWAY_H
#define PORTAGENS_HIGHWAY_H

#include "toll.h"

class Highway {
private:
    string name;
    vector<Toll*> tolls;
public:
    Highway(string n): name(n){}
    const string &getName() const;
    void printTollsNumbered();
    void printTollsNumbered(bool exit);
    Toll* getTollAt(int i,bool exit);
    void addToll(Toll* toll);
    vector<Toll*> &getTolls();
    void eraseTollAt(int i){tolls.erase(tolls.begin()+i);}
};


#endif //PORTAGENS_HIGHWAY_H
