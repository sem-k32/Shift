//
// Created by Кирилл on 22.04.2022.
//

#ifndef GREAT_PROJECT_DBFUNCS_H
#define GREAT_PROJECT_DBFUNCS_H

#include <cstdio>
#include <string>
#include <cstring>
#include <vector>

// выполнить все кроме select (на самом деле select тоже может, но записывает в stdout, поэтому для select не использую)
void myNoSelect(const char * sql);
// выполнить select для бд (записывает в vector vec)
void mySelect(const char * sql, std::vector<std::pair<std::string, std::string>>& vec);

#endif //GREAT_PROJECT_DBFUNCS_H