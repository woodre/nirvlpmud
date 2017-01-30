#define DB_FUN_OBJ "players/quicksilver/lib/db_funs.c"

/* database functions-- ~/lib/db_funs.c */
get_db_from_file(string file, string *separator) { return DB_FUN_OBJ->get_db_from_file(file, separator); }
print_db(mixed db) { return DB_FUN_OBJ->print_db(db, 0); }

