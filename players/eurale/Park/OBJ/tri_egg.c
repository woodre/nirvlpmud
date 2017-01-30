/*  Changed to barterable item 8/17/02 - Eurale  */

#define tpn this_player()->query_name()  /* player name  */
#define ETP environment(this_player())
#include "/players/eurale/closed/ansi.h"

id(str) { return str == "triceratop egg" || str == "egg"; }
short() { return "triceratop egg"; }
query_save_flag() { return 1; }
query_value() { return 1000 + random(2000); }
long() {
  write("This is the egg of the fearsome triceratops.  It is about\n"+
	"18 inches long and 25 inches in circumference.  You can either\n"+
	"sell it or  barter it in.\n"); }

reset(arg) {
  if(arg) return;
}

init() {
  add_action("Barter","barter");
}

Barter(str) {
int num;
if(!str) { write("Barter what?\n"); return 1; }
if(str == "egg") {
if(!present("sedjak",ETP)) { write("What?\n"); return 1; }
  num = 4300 + random(400);
  write("Sedjak takes the egg.  He tells you, 'Haven't seen one of\n"+
        "these in a while, I'll take it' and he hands you "+num+" coins\n"+
        "for it.\n");
  this_player()->add_money(num);
  destruct(this_object());
  return 1; }
}


get() { return 1; }

query_weight() { return 2; }
