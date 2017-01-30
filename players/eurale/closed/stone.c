
#include "/players/eurale/closed/ansi.h"
#define Mv call_other(this_player(),"move_player"

inherit "obj/weapon.c";
reset(arg) {
  ::reset(arg);
  if (arg) return;
set_name("stone");
set_alias("hearthstone");
set_short("A beautiful "+BOLD+"Hearthstone"+NORM);
set_long(
	"This beautiful black stone has been worn smooth and polished\n"+
	"to a glassy sheen by constant rubbing.  If you should ever \n"+
	"want to return to the guild, just [rub stone].\n");
set_class(5);
set_weight(1);
set_value(1);
}

query_auto_load() { return "players/eurale/closed/stone.c:"; }

drop() { return 0; }

init() {
  ::init();
  add_action("rub","rub");
}

rub(str) {
if(str == "stone" || str == "hearthstone") {

if(environment(this_player())->realm() == "NT") {
  write("You rub the stone and a strange sensation tells you that you\n"+
        "cannot utilize the stone from this location...\n");
  return 1; }

else {
  write("You rub the stone... your head feels light... and you teleport\n"+
	"back to the guild.\n");
  Mv,"drift off#players/mythos/closed/guild/assembly.c");
  this_player()->heal_self(- random(40));
  return 1; }
return 1; }
}
