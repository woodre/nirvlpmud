#include "/players/eurale/closed/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
object ob;
  ::reset(arg);
  if(arg) return;

ob = clone_object("players/eurale/Fiend/OBJ/ivory_broach.c");
move_object(ob,this_object());
init_command("wear broach");
set_name("gremlin");
set_alias("gremlin 3");
set_race("creature");
set_short("Gremlin");
set_long(
	"  This two-foot high furry creature came from the Mogwai.  It\n"+
	"is a sinister looking little animal with long sharp teeth and\n"+
	"pointed ears.  It's glowing eyes allow it to see well in the\n"+
	"darkness.\n");

set_level(19);
  set_hp(595);
  set_al(-100);
  set_wc(28);
  set_ac(14);
  set_aggressive(1);

set_chat_chance(15);
  load_chat("The Gremlin chatters......\n");
set_a_chat_chance(15);
  load_a_chat("You feel the Gremlin STRANGLING you!!\n");

}
