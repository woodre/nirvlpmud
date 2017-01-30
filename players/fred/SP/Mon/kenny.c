#include "/players/fred/ansi.h"
inherit "obj/monster.c";

object hood;
reset(arg)  {
  ::reset(arg);
  if(arg) return;

set_name("kenny");
set_alias("kenny");
set_race("human");
set_short("Kenny");
set_long(
  "  This is the beloved Kenny that for some reason gets killed in\n"+
  "almost every episode.  Because of his large orange hood he has\n"+
  "a hard time talking and mumbles constantly.  You can see his eyes\n"+
  "darting around rapidly, hoping to avoid the next disaster.\n");

add_money(200);
set_level(9);
set_hp(135);
set_al(0);
set_wc(13);
set_aggressive(0);

	hood  = clone_object("/players/fred/SP/Obj/ohood.c");
      move_object(hood, this_object());
	command("wear hood", this_object());
set_ac(7);
}


