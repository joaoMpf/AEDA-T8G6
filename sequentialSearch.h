#ifndef PORTAGENS_SEQUENTIALSEARCH_H
#define PORTAGENS_SEQUENTIALSEARCH_H

#include <vector>
using namespace std;

template <class Comparable>
int sequentialSearch(const vector<Comparable *> &v, const Comparable *x)
{
    for (unsigned int i = 0; i < v.size(); i++)
        if (*v[i] == *x)
            return i;   // encontrou
    return -1;     // não encontrou
}

#endif //PORTAGENS_SEQUENTIALSEARCH_H
