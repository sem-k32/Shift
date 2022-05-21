//
// Created by Кирилл on 13.05.2022.
//

#ifndef GREAT_PROJECT_MAPSCH_H
#define GREAT_PROJECT_MAPSCH_H

#include <string>
#include <vector>
#include <map>
#include <stdlib.h>
#include "alg_funcs.h"

// возвращает словарь (день, вектор пар) для группы gr
std::map<std::string, std::vector<Pair>> mapSch(const std::string& gr);

#endif //GREAT_PROJECT_MAPSCH_H
