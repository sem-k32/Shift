//
// Created by Кирилл on 25.04.2022.
//
#include <cstdio>
#include "sqlite3.h"
#include "dbFuncs.h"

static int callback(void *NotUsed, int argc, char **argv, char **azColName){
    int i;
    for(i=0; i<argc; i++){
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

void myNoSelect(const char * sql) {
    sqlite3 *db;
    char *zErrMsg = nullptr;
    int rc;
    //char * sql;

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
    rc = sqlite3_exec(db, sql, callback, nullptr, &zErrMsg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    } else {
        fprintf(stdout, "Success\n");
    }
    /* Close database */
    sqlite3_close(db);
}