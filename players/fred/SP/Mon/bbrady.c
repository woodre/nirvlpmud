#include "/players/fred/ansi.h"
inherit "obj/monster.c";

object badge;
reset(arg)  {
  ::reset(arg);
  if(arg) return;

set_name("officer Barbrady");
set_alt_name("officer");
set_alias("barbrady");
set_race("human");
set_short("Officer Barbrady");
set_long(
  "  He is the only law enforcement officer in South Park.  He never\n"+
  "seems to have clue what is going on in the town and just assumes\n"+
  "that everything is okay.\n");
  
add_money(500);
set_level(12);
set_hp(180);
set_al(800);
set_wc(16);
set_ac(9);
set_aggressive(0);
set_chat_chance(8);
  load_chat("Officer Barbrady exclaims: Nothing to see here.\n");
  load_chat("Officer Barbrady says: Let's just keep it moving you"+
            " looky lous.\n");
   
	badge = clone_object("/players/fred/SP/Obj/badge.c");
      move_object(badge, this_object());
	command("wear badge", this_object());
}


