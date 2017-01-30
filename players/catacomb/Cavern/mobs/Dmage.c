#include "/players/catacomb/misc/ansi.h"
inherit "obj/monster.c";
#define ATTACKED (this_object()->query_attack())
object robe;

reset(arg)  {
  ::reset(arg);
  if(arg) return;

set_name("mage");
set_race("creature");
set_short("A Durkor mage");
set_long(
  "  One of the Durkor elite being trained since birth in the arcane\n"+
  "art of magic, she is a forced to be reckoned with.  All the mages\n"+
  "are shrouded in large black robes.  Red glowing eyes flicker from\n"+
  "deep within the hood of the robe.\n");
 
set_level(19);
set_hp(425);
set_al(-500);
set_ac(16);
set_wc(27);
add_money(random(1000)+1750);
set_dead_ob(this_object());
set_aggressive(0);
set_chat_chance(3);
  load_chat(RED+"Red"+NORM+" eyes pierce your very soul.\n");
set_chance(35);
set_spell_dam(40);
set_spell_mess1(
  "The mage utters something then a large "+HIR+"pillar of flames "+NORM+"erupts around her enemy.\n");
set_spell_mess2(
  "The mage utters: Featulus. You are suddenly engulfed in a "+RED+"pillar of flame"+NORM+".\n");

}
 
monster_died(){
  object robe;
  tell_object(ATTACKED,
    "The robe suddenly falls to the ground.\n");
  robe = clone_object("/players/catacomb/Cavern/items/Mrobe.c");
  move_object(robe, this_object());
}   