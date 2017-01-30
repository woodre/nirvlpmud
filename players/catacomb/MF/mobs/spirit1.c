#include "/players/catacomb/misc/ansi.h"
inherit "obj/monster.c";
#define attacked (this_object()->query_attack())
object belt;

reset(arg)  {
  ::reset(arg);
  if(arg) return;

set_name("spirit");
set_race("undead");
set_short("A wandering spirit");
set_long(
  "  The lifeless soul of one of the Shamot elves.  Left for dead\n"+
  "by a hunting party in his previous life, the spirit wants nothing\n"+
  "but to destroy anything living.\n");
 
set_level(17);
set_hp(350);
set_al(-100);
set_ac(14);
set_wc(24);
add_money(random(1500)+1000);
set_aggressive(0);
set_chat_chance(5);
  load_chat("The spirit lets out a low gutteral groan.\n");
set_chance(5);
set_spell_dam(20);
set_spell_mess1(
    "The spirit lets out a wail making "+attacked+"'s ears bleed.\n");
  set_spell_mess2(
    "\nThe spirit lets out a wail making your ears bleed.\n");  


}
 
