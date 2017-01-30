#include "/players/mythos/closed/ansi.h"

string id_s, short_desc;

id(str) { return str == "chip" || str == id_s; }

drop() { return 0; }

get() { return 1; }

short() { return short_desc; }

long() { write("A "+id_s+" splinter.\n"); }

set_short(str) { short_desc = str; }

set_id(str) { id_s = str; }

