/*  Changed to barterable item 8/17/02 - Eurale  */

#define tpn this_player()->query_name()  /* player name  */
#define ETP environment(this_player())
#include "/players/eurale/closed/ansi.h"
int number;

inherit "obj/treasure";

reset(arg) {
  if(arg) return;
set_id("fin");
set_alias("chunk");
set_short(HIG+"chunk of dimetrodon fin"+NORM);
set_long(
  "A sizeable chunk of dimetrodon fin that could be sold for profit or\n"+
  "bartered for greater profit.\n");

set_weight(1);
set_value(1000);
set_save_flag();
}

init() {
  ::init();
  add_action("Barter","barter");
}

Barter(str) {
int num;
if(!str) { write("Barter what?\n"); return 1; }
if(str == "fin" || str == "chunk") {
if(!present("sedjak",ETP)) { write("What?\n"); return 1; }
  num = 4700 + random(400);
  write("Sedjak takes the chunk of dimetrodon fin and cackles..\n"+
        "He hands you "+num+" coins and packs it away...\n");
  this_player()->add_money(num);
  destruct(this_object());
  return 1; }
}
