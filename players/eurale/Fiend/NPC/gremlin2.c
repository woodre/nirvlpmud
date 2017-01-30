#include "/players/eurale/closed/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
  ::reset(arg);
  if(arg) return;

if(!present("china cup")) {
move_object(clone_object("players/eurale/Fiend/OBJ/china_cup.c"),
  this_object()); }
set_name("gremlin");
set_alias("gremlin 2");
set_race("creature");
set_short("Gremlin");
set_long(
	"  This two-foot high furry creature came from the Mogwai.  It\n"+
	"is a sinister looking little animal with long sharp teeth and\n"+
	"pointed ears.  It's glowing eyes allow it to see well in the\n"+
	"darkness.\n");

set_level(19);
  set_hp(500);
  set_al(-100);
  set_wc(28);
  set_ac(15);
  set_aggressive(1);

set_chat_chance(15);
  load_chat("The Gremlin chatters......\n");
set_a_chat_chance(15);
  load_a_chat("\nThe Gremlin KICKS you HARD!!\n\n");

}
