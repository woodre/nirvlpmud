#include "/players/catacomb/misc/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
  ::reset(arg);
  if(arg) return;

set_name("maijan");
set_race("creature");
set_short("A large maijan");
set_long(
  "  The creature appears to be a very large version of a beetle.  At \n"+
  "the end of all six of its legs are razor sharp claws.  It enjoys \n"+
  "dwelling in the dampness of this cave, feeding on all who would cross\n"+
  "its path.\n");
 
set_level(16);
set_hp(300);
set_al(0);
set_ac(13);
set_wc(22);
set_aggressive(1);
add_money(500+random(1000));
}
 
