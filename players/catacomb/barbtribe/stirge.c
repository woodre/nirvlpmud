#include "/players/catacomb/misc/ansi.h"
inherit "obj/monster.c";
#define ATN (this_object()->query_attack())
object beak;

reset(arg)  {
  ::reset(arg);
  if(arg) return;

set_name("stirge");
set_race("creature");
set_short("A giant stirge");
set_long(
  "  The stirge screeches at you defending its nest.  It\n"+
  "looks like a cross between a large bird of prey and a\n"+
  "mosquito, with it's enlonged beak.\n");
 
set_level(11);
set_hp(165);
set_al(-100);
set_ac(9);
set_wc(15);
set_dead_ob(this_object());
set_aggressive(0);
set_chance(8);
set_spell_dam(15);
set_spell_mess1(
  "The stirge flies in low at its enemy.  The stirge buries its\n"+
  "beak into their neck.\n");
set_spell_mess2(
  "The stirge flies low at you.  You feel the beak stab into your\n"+
  "neck.  "+HIR+"You feel your life energy leave you.\n"+NORM); 
}
 
monster_died(){
  tell_object(ATN,
  "The stirge lets out one last screech before it goes silent.\n"+
  "The beak falls off the creature when it hits the ground.\n");
  beak = clone_object("/players/catacomb/barbtribe/beak.c");
    move_object(beak, this_object());
}   