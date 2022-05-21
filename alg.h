//
// Created by Кирилл on 29.04.2022.
//

#ifndef GREAT_PROJECT_ALG_H
#define GREAT_PROJECT_ALG_H

#include "alg_funcs.h"
#include "dbFuncs.h"
#include <stdlib.h>
#include <set>

//
void myDFS(Node u, const std::string &yourGr, std::vector<std::string> &noShift);

// возвращает матрицу множеств цветов, в которые покрашены ребра
// vec -- куда хотим перевестись
// noShift -- вектор предметов, по которым запрещаем переводы
std::vector<std::vector<Node>> alg(std::vector<A>& vec, const std::string& yourGr, std::vector<std::string>& noShift);


#endif //GREAT_PROJECT_ALG_H
