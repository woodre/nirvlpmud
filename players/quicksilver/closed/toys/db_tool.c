#include "/players/quicksilver/std/std.h"
#include DB_FUNS

inherit "obj/treasure";

mapping db;


id(str) { return str == "db_tool"; }
short() {
   return "A database tool";
}

long() {
    write(short()+"\n");
}

init() {    
    add_action("load_db", "getdb");
    add_action("dump_db", "printdb");
}
 
load_db(str) {
	write((db = get_db_from_file(str)) ? "Ok.\n" : "Failed to open "+str+"\n");
    return 1;
}

dump_db() {
	print_db(db);
    return 1;
}
