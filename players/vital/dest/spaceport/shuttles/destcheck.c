#include "/players/vital/closed/headers/vital.h"
#define SPROOM "/players/vital/dest/spaceport/rooms/"


object shuttle, room;
mapping shuttle_objs;
string name, dest;
string *dest_keys;
mapping shuttle_dest;
mapping dest_path;
mapping timer;
int rtime;

id(str) { return str == "shuttle" || str == "checker"; }

drop() { return 1;}

short() {
    write("Shuttle Path Checker\n");
}

long() { 
    short();
}

reset(arg) {
    if (arg) return;
    dest_path = read_file("/players/vital/dest/spaceport/shuttles/dest_path",20);    /*set up destination locations*/
}

init() {
    add_action("check_map","check");
}

check_map() {
    int x;
    dest_keys = m_indices(dest_path);
    FOREACH(dest_keys,x) {
	write("\t"+dest_path[dest_keys]);
    }
}

