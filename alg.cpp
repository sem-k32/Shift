//
// Created by Кирилл on 29.04.2022.
//

#include "alg.h"

std::vector<Node> vForOne;
std::vector<Node> vForOne2;
std::vector<std::string> noShift2;  // вектор предметов, которые запрещаются при проходе myDFS
std::vector<Node> fr;  // вектор осободившихся ячеек

std::vector<std::vector<Node>> alg(std::vector<A>& vec, const std::string& yourGr, std::vector<std::string>& noShift) {
    int n = vec.size();
    std::vector<std::vector<Node>> mt(n);
    // Создали матрицу с n строками, где n это кол-во переводов, которые нужно сделать.
    // Каждая строка это путь из ячеек, в которые нужно перевестись

    for(A a : vec) {
        if(a.gr == yourGr) {
            fprintf(stderr, "You are already in this group.");
            continue;
        }
        Node u0 = aToNode(a);
        Node uf = getN(yourGr, u0.subj);
        fr.push_back(uf);  // новая освобод-ся ячейка
        myDFS(u0, yourGr, noShift);
        mt.push_back(vForOne2);
        if(vForOne2.empty())
            fr.pop_back();  // т.е. перевод не удался => ячейка все таки не освобод-сь
        vForOne.clear();
        vForOne2.clear();
    }

    return mt;
}

void myDFS(Node u, const std::string &yourGr, std::vector<std::string> &noShift) {
    vForOne.push_back(u);
    for(Node x : fr) {       // если нужная ячейка была занята, но теперь освободилась
        if((u.day == x.day && u.pairID == x.pairID) && vForOne2.empty()) {
            vForOne2 = vForOne;
            return;
        }
    }
    if(check(yourGr, u.day, u.pairID).empty() && vForOne2.empty()) { // если время не занято
        vForOne2 = vForOne;
        return;
    }
    else {    // если у моей группы в день u.day и пару u.pairID есть пара,
        // то проверяем, разрешено ли поменять соответствующий этой паре предмет
        std::string subj = check(yourGr, u.day, u.pairID)[0].second;    // здесь получаем какой предмет в эту пару
        int i = 0;
        for(std::string x : noShift) {
            if(subj == x) {
                vForOne.pop_back();
                break;
            }
            ++i;
        }
        int j = 0;
        for(std::string x : noShift2) {
            if(subj == x) {
                vForOne.pop_back();
                break;
            }
            ++j;
        }
       if((i == noShift.size()) && (j == noShift2.size())) {  // т.е. если subj не совпал ни с кем из noShift и ни с кем
           // из noShift2 (значит разрешено)
           noShift2.push_back(u.subj);
           std::vector<Node> currSubj = nSubj(yourGr, subj);
           for(Node x : currSubj) {
               myDFS(x, yourGr, noShift);
           }

       }
    }
}
