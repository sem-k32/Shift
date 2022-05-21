//
// Created by Кирилл on 24.04.2022.
//

#ifndef GREAT_PROJECT_ALG_FUNCS_H
#define GREAT_PROJECT_ALG_FUNCS_H

#include <string>
#include <vector>

struct Pair {
    std::string pairID;
    std::string sName;
    std::string tName;
    float easy;
    std::string room;
};

struct Node {
    int id;
    std::string day;
    std::string pairID;
    std::string subj;
    std::string prep;
    float easy;
};

struct A {
    std::string subj;
    std::string newPrep;
    std::string gr;
};

// возвращает предмет и препа, которые идут по расписанию у группы gr в день day, пару p
std::vector<std::pair<std::string, std::string>> check(const std::string& gr, const std::string& day, const std::string& p);
// возвращает id всех строк с предметом subj из расписания, но не у группы gr
std::vector<std::pair<std::string, std::string>> idSubj(const std::string& gr, const std::string& subj);
//по структуре A возвращает соответствующую структуру Node
Node aToNode(A a);
// по id строки возвращает соответствующую структуру Node
Node idToNode(int id);
//возвращает вектор структур Node с предметом subj, но не у группы gr
std::vector<Node> nSubj(const std::string& gr, const std::string& subj);

// возвращает расписание для группы gr
std::vector<std::pair<std::string, std::string>> getSch(const std::string& gr);

// возвращает расписание для группы yourgr
std::vector<Node> getYSch(const std::string& yourGr);

// возвращает Node с предметом subj из расписания твоей группы
Node getN(const std::string& yourGr, const std::string& subj);

#endif //GREAT_PROJECT_ALG_FUNCS_H