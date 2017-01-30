#include "/players/catacomb/misc/ansi.h"
inherit "obj/monster.c";
#define attacked (this_object()->query_attack())
object fangs;

reset(arg)  {
  ::reset(arg);
  if(arg) return;

set_name("snake");
set_race("creature");
set_short("A poisonous snake");
set_long(
  "  A fairly long snake, stretching to a full length of\n"+
  "ten feet, sits coiled hissing at you.\n");
 
set_level(9);
set_hp(135);
set_al(-100);
set_ac(7);
set_wc(13);
set_dead_ob(this_object());
set_aggressive(1);
set_chat_chance(2);
  load_chat("The snake coils up ready to strike.\n");
  }
 
monster_died(){
/*
  tell_object(attacked,
*/
  tell_room(environment(),
  "As the snake's body goes limp, its fangs fall from its mouth!\n");
  fangs = clone_object("/players/catacomb/barbtribe/Sfang.c");  
  move_object(fangs, this_object());
}   
