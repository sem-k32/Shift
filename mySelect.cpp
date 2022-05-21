//
// Created by Кирилл on 22.04.2022.
//
#include <cstdio>
#include "sqlite3.h"
#include "dbFuncs.h"
#include <vector>

static int callback(void *dataPtr, int argc, char **argv, char **azColName){
    auto vec = static_cast<std::vector<std::pair<std::string, std::string>>*>(dataPtr);
    int i;
    for(i=0; i<argc; i++){
        vec->push_back({azColName[i], argv[i] ? argv[i] : "NULL"});
    }
    return 0;
}

void mySelect(const char * sql, std::vector<std::pair<std::string, std::string>> & vec) {
    sqlite3 *db;
    char *zErrMsg = nullptr;
    int rc;

/* Open database */
    rc = sqlite3_open("data_base.db", &db);
    if (rc) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        exit(0);
    } else {
        fprintf(stdout, "Opened database successfully\n");
    }

/* Create SQL statement */
// sql

/* Execute SQL statement */
    rc = sqlite3_exec(db, sql, callback, &vec, &zErrMsg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    } else {
        fprintf(stdout, "Success\n");
    }
    /* Close database */
    sqlite3_close(db);
}