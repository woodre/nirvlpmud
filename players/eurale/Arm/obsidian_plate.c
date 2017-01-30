#define TO this_object()
#define TP this_player()
#define ETO environment(this_object())
#include "/players/eurale/closed/ansi.h"
inherit "obj/armor";
reset(arg) {
  set_name("plate");
set_alias("obsidian plate");
set_short(BOLD+"Obsidian Plate"+NORM);
  set_long(
	"This smooth, black obsidian plate will cover your body from\n"+
	"head to foot leaving very little exposed.  It is durable and\n"+
	"one of the toughest armors available.\n");
  set_ac(4);
  set_type("armor");
  set_weight(3);
  set_value(1850);
set_no_clean(1);
}

/*  Added this init code because I moved this object into
    ~/Space/OBJ/plate.c and I didn't want those who it stored
    to have trouble getting it out.  7/21/00  
*/

init() {
if(ETO) {
  move_object(clone_object("players/eurale/Space/OBJ/plate.c"),TP);
  destruct(TO); }
}
