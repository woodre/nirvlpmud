#include "/players/fred/ansi.h"
inherit "obj/monster.c";
#define attacked (this_object()->query_attack())
object belt;

reset(arg)  {
  ::reset(arg);
  if(arg) return;

set_name("rabbit");
set_race("creature");
set_short(BOLD+"Kung-Fu"+NORM+" Rabbit");
set_long(
  " A large rabbit with deep brown fur. Somehow \n"+
  "this small woodland creature has learned the \n"+
  "fine art of Kung-Fu.\n");
 
set_level(18);
set_hp(450);
set_al(-100+random(-200));
set_ac(15);
set_wc(26);
set_dead_ob(this_object());
set_aggressive(0);
set_chat_chance(4);
  load_chat("The rabbit poises for combat!.\n");
set_a_chat_chance(10);
  load_a_chat("The rabbit stuns you with a flying crescent kick.\n");
  load_a_chat("The rabbit performs an opened handed palm strike on you.\n");
  load_a_chat("You thrown through the air from a locked-elbow throw.\n");
  load_a_chat("You are hit with a double fisted punch.\n");
set_spell_dam(15+random(10));
}
 
monster_died(){
  tell_object(attacked,
  "The belt around the rabbits waist loosens and falls\n"+
  "to the ground as it dies.\n\n");
  belt = clone_object("/players/fred/forest/Obj/rbelt.c");
  move_object(belt, this_object());
}   