#ifndef MAIN_H
#define MAIN_H

#include <QString>

struct sportsman {
    int id;
    QString name;
    QString region;
    QString range;
    int status;
    QString category;
    QString age;
    QString weight;
    bool operator<(const sportsman& obj){
        if(category == obj.category){
            if(age == obj.age){
                if(weight == obj.weight){
                    return name > obj.name;
                }
                return weight < obj.weight;
            }
            return age < obj.age;
        }
        return category < obj.category;
    }

};

#endif // MAIN_H
