#include "/players/catacomb/misc/ansi.h"
inherit "obj/monster.c";
#define attacked (this_object()->query_attack())
object belt;

reset(arg)  {
  ::reset(arg);
  if(arg) return;

set_name("spirit");
set_race("undead");
set_short("A wandering spirit);
set_long(
  "  The spirit is of a small elven child.  This unfortunate soul\n"+
  "travelled too far into the forest, and the minions of the cursed\n"+
  "forest took out their anger on him.  The ghost wanders about \n"+
  "trying to understand its new life.  The poor child seems to let\n"+
  "out an almost inaudible wimper with each step\n");
 
set_level(15);
set_hp(250);
set_al(100);
set_ac(12);
set_wc(20);
add_money(random(1200))
set_aggressive(0);

}
 
