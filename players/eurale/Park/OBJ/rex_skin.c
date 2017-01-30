/*  Moved inherit above the #includes   10/04/2006 - Rumplemintz  */

inherit "obj/armor";
#include "/open/ansi.h"
reset(arg) {
  if(arg) return;

set_id("skin");
set_short(GRN+"tyrannosaurus rex skin"+NORM);
set_long(
	"  This thick, leathery skin came from the world's fiercest \n"+
	"fighter.  It is valuable, too bad one couldn't craft it into \n"+
	"armor. \n");

set_ac(3);
set_type("armor");
set_weight(4);
set_value(4000);
}

init() {
  ::init();
  add_action("Craft","craft");
}

Craft(str) {
object plate;
  if(this_player()->query_attrib("int") < 20)
	{ write("Sorry, not intelligent enough to do that... \n"); return 1; }
  if(str == "skin") {
  write("You take the near-steel skin....... \n");
  write("     and with great care..... \n");
  write("           craft a fine set of leather plate armor.\n");
  plate = clone_object("/players/eurale/Park/OBJ/rex_plate.c");
  move_object(plate, environment(this_object()));
  destruct(this_object());
/* -2004.09.05 fixed to account for carry check -Forbin
  destruct(this_object());
    plate = clone_object("players/eurale/Park/OBJ/rex_plate.c");
    move_object(plate,this_player());
*/
  return 1;}
}
