#include "DEFS.h"
inherit "room/room";
int F;  /* variable to make sure only 1 fetch  */

reset(arg) {
F = 0;
  if(arg) return;
set_light(0);

short_desc = "The Abyss";
long_desc =
  "  You can feel yourself being drawn closer and closer to some pure\n"+
  "evil source.  The build up of fear that you feel is almost over-\n"+
  "whelming....but why?  Muffled screams can be heard faintly through\n"+
  "the thick darkness below.\n";

items = ({
});

dest_dir = ({
	"players/eurale/Abyss/a1.c","up",
	"players/eurale/Abyss/a3.c","down",
});

}

init() {
  ::init();
  add_action("listen","listen");
  add_action("west","west");
}

listen(str) {
if(!str || str == "screams") {
  write("You listen closely to the sounds from below.  Is that the \n"+
	"scream of a human or...... the wail of some unhuman source?\n");
  return 1; }
}

west() {
object ob;
if(F != 1) {
  call_other("players/eurale/Abyss/a7.c","???");
  ob = clone_object("players/eurale/Abyss/NPC/fetch1.c");
    ob->set_hp(this_player()->query_mhp() * 2);
    ob->set_al(TP->query_alignment());
    ob->set_wc(2 * TPL);
  move_object(ob,"/players/eurale/Abyss/a7.c");
  F = 1;
  TP->move_player("darkness#players/eurale/Abyss/a7.c");
  return 1; }
else {
  TP->move_player("darkness#players/eurale/Abyss/a7.c");
  return 1; }
}

realm() { return "NT"; }
