//
// Created by Кирилл on 24.04.2022.
//
#include "alg_funcs.h"
#include "dbFuncs.h"
#include <vector>

std::vector<std::pair<std::string, std::string>> check(const std::string& gr, const std::string& day, const std::string& p) {
    std::vector<std::pair<std::string, std::string>> vec;
    std::string str1 = "select subj.NAME as sname, t.NAME as tname from SCHEDULE as sch"
                       " left join TEACHERS as t on sch.TEACHER_ID = t.T_ID"
                       " left join SUBJECT as subj on sch.SUBJECT_ID = subj.SUBJ_ID"
                       " where sch.GR_NAME = '";
    std::string str2 = "' and DAY = '";
    std::string str3 = "' and PAIR_ID = ";
    std::string str = str1 + gr + str2 + day + str3 + p;
    mySelect(str.c_str(), vec);
    return vec;
}

std::vector<std::pair<std::string, std::string>> idSubj(const std::string& gr, const std::string& subj) {
    std::vector<std::pair<std::string, std::string>> vec;
    std::string str1 = "select ID from SCHEDULE as sch"
                       " left join SUBJECT as subj on sch.SUBJECT_ID = subj.SUBJ_ID"
                       " where GR_NAME != '";
    std::string str2 = "' and subj.NAME = '";
    std::string str3 = "'";
    std::string str = str1 + gr + str2 + subj + str3;
    mySelect(str.c_str(), vec);
    return vec;
}

Node aToNode(A a) {
    std::vector<std::pair<std::string, std::string>> vec;
    std::string str1 = "select sch.ID, sch.GR_NAME, sch.DAY, sch.PAIR_ID, t.EASINESS from SCHEDULE as sch "
                       "left join SUBJECT as subj on sch.SUBJECT_ID = subj.SUBJ_ID "
                       "left join TEACHERS as t on sch.TEACHER_ID = t.T_ID "
                       "where sch.GR_NAME = '";
    std::string str2 = "' and subj.NAME = '";
    std::string str3 = "' and t.NAME = '";
    std::string str4 = "'";
    std::string str = str1 + a.gr + str2 + a.subj + str3 + a.newPrep + str4;
    mySelect(str.c_str(), vec);
    int id = atoi(vec[0].second.c_str());
    Node v = {id, vec[2].second, vec[3].second, a.subj, a.newPrep, std::stof(vec[4].second)};
    return v;
}

Node idToNode(int id) {
    std::vector<std::pair<std::string, std::string>> vec;
    std::string str1 = "select sch.ID, sch.GR_NAME, sch.DAY, sch.PAIR_ID, subj.NAME, t.NAME, t.EASINESS "
                       "from SCHEDULE as sch "
                       "left join SUBJECT as subj on sch.SUBJECT_ID = subj.SUBJ_ID "
                       "left join TEACHERS as t on sch.TEACHER_ID = t.T_ID "
                       "where sch.ID = '";

    std::string str2 = std::to_string(id);
    std::string str3 = "'";
    std::string str = str1 + str2 + str3;
    mySelect(str.c_str(), vec);
    Node v = {id, vec[2].second, vec[3].second, vec[4].second, vec[5].second, std::stof(vec[6].second)};
    return v;
}

std::vector<Node> nSubj(const std::string& gr, const std::string& subj) {
    std::vector<Node> v;
    std::vector<std::pair<std::string, std::string>> vec = idSubj(gr, subj);
    for(auto x : vec) {
        v.push_back(idToNode(atoi(x.second.c_str())));
    }
    return v;
}

std::vector<std::pair<std::string, std::string>> getSch(const std::string& gr) {
    std::vector<std::pair<std::string, std::string>> vec;
    std::string str1 = "select DAY, PAIR_ID, subj.NAME, t.NAME as TNAME, t.EASINESS, CLASSROOM from SCHEDULE as sch"
                       " left join SUBJECT as subj on sch.SUBJECT_ID = subj.SUBJ_ID"
                       " left join TEACHERS as t on sch.TEACHER_ID = t.T_ID"
                       " where sch.GR_NAME = '";
    std::string str2 = "'";
    std::string str = str1 + gr + str2;
    mySelect(str.c_str(), vec);
    return vec;
}

std::vector<Node> getYSch(const std::string& yourGr) {
    std::vector<Node> sch;
    std::vector<std::pair<std::string, std::string>> vec;
    std::string str1 = "select ID from SCHEDULE as sch"
                       " left join SUBJECT as subj on sch.SUBJECT_ID = subj.SUBJ_ID"
                       " left join TEACHERS as t on sch.TEACHER_ID = t.T_ID"
                       " where sch.GR_NAME = '";
    std::string str2 = "'";
    std::string str = str1 + yourGr + str2;
    mySelect(str.c_str(), vec);
    for(auto x : vec) {
        sch.push_back(idToNode(atoi(x.second.c_str())));
    }
    return sch;
}


Node getN(const std::string& yourGr, const std::string& subj) {
    std::vector<std::pair<std::string, std::string>> vec;
    std::string str1 = "select ID from SCHEDULE as sch"
                       " left join SUBJECT as subj on sch.SUBJECT_ID = subj.SUBJ_ID"
                       " left join TEACHERS as t on sch.TEACHER_ID = t.T_ID"
                       " where sch.GR_NAME = '";
    std::string str2 = "' and subj.NAME = '";
    std::string str3 = "'";
    std::string str = str1 + yourGr + str2 + subj + str3;
    mySelect(str.c_str(), vec);

    Node v = idToNode(atoi(vec[0].second.c_str()));
    return v;
}
