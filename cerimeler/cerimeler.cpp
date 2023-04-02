#include <iostream>
using namespace std;
#include<map>
#include<list>

#include"mainClasses.h"
#include"penalties.h"
#include"database.h"


int main()
{
    Datetime d1(5, 11, 2021);
    Datetime d2(16, 6, 2020);
    Datetime d3(24, 1, 2003);
    Datetime d4(19, 10, 2005);
    Datetime d5(12, 6, 2008);
    Datetime d6(8, 9, 2011);
    list<Penalty> penalties =
    {
        RedLight(d1),
        RedLight(d2),
        DoubleLine(d3),
        DoubleLine(d4),
        Parking(d5),
        Parking(d6),
    };
    string carNumber = "77OO777";
    map<string, list<Penalty>> totalPenalties;
    totalPenalties.insert({ carNumber,penalties });

    Database database;
    database.set_totalPenalties(totalPenalties);
    database.showTotalPenalties();
}
