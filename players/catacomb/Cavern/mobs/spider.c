#include "/players/catacomb/misc/ansi.h"
inherit "obj/monster.c";
#define attacked (this_object()->query_attack())

reset(arg)  {
  ::reset(arg);
  if(arg) return;

set_name("spider");
set_race("creature");
set_short("A fairly large venomous spider");
set_long(
  "  It looks like any other spider you may have seen, except that\n"+
  "this one is roughly the size of a small halfling.  Its teeth \n"+
  "drip with poison and blood.\n");
 
set_level(15);
set_hp(250);
set_al(-100);
set_ac(12);
set_wc(20);
set_dead_ob(this_object());
set_aggressive(0);
set_chat_chance(5);
  load_chat("The spider sits poised to attack at any moment.\n");
}   
monster_died(){
  object silk;
  tell_object(attacked,
  "As the spider dies, silk escapes its abdomen.\n");
  silk = clone_object("/players/catacomb/Cavern/items/silk.c");
  move_object(silk, this_object());
}   