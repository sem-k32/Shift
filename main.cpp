#include "dbFuncs.h"
#include "alg_funcs.h"
#include <iostream>
#include <map>
#include <stdlib.h>
#include "mapSch.h"
#include "alg.h"


int main() {
/*
    std::map<std::string, std::vector<Pair>> mp = mapSch("B05-001");
    std::cout << "For B05-001:" << std::endl;
    for(auto x : mp) {
        std::cout << x.first << ": " << std::endl;
        for(auto t : x.second) {
            std::cout << t.pairID << " " <<t.sName << " " << t.tName << " " << t.easy << " " << t.room << " ";
            std::cout << std::endl;
        }
    }
    mp = mapSch("B05-002");
    std::cout << "For B05-002:" << std::endl;
    for(auto x : mp) {
        std::cout << x.first << ": " << std::endl;
        for(auto t : x.second) {
            std::cout << t.pairID << " " <<t.sName << " " << t.tName << " " << t.easy << " " << t.room << " ";
            std::cout << std::endl;
        }
    }
    std::cout << "End Schedule" << std::endl;
*/

    std::vector<std::vector<Node>> vec;   // возвращаемая матрица переводов
    std::vector<A> vecA = {{"TFS", "Mark", "B05-001"}};
    std::vector<std::string> noShift = {"Calculus"};
    vec = alg(vecA, "B05-002", noShift);
    for(auto x : vec) {
        for(Node t: x) {
            std::cout << t.id << " " << t.day << " " << t.pairID << " " << t.subj << " " << t.prep << " " << t.easy;
            std::cout << std::endl;
        }
    }

    //myNoSelect("insert into SCHEDULE values (6, 'B05-001', 'Friday', 2, 3, 1, '417gk')");
   return 0;
}