//
// Created by Кирилл on 13.05.2022.
//
#include "mapSch.h"

std::map<std::string, std::vector<Pair>> mapSch(const std::string& gr) {
    std::vector<std::pair<std::string, std::string>> vec = getSch(gr);
    std::map<std::string, std::vector<Pair>> mp;
    int n = vec.size();
    for(int i = 0; i < n; i+=6) {       // цикл по дням
        Pair p;
        p.pairID = vec[i + 1].second;
        p.sName = vec[i + 2].second;
        p.tName = vec[i + 3].second;
        p.easy = atof(vec[i + 4].second.c_str());
        p.room = vec[i + 5].second;
        mp[vec[i].second].push_back(p);
    }
    return mp;
}