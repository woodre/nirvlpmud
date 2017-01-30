#include "/players/catacomb/misc/ansi.h"
inherit "obj/monster.c";
#define ATTACKED (this_object()->query_attack())
object ring;

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
add_money(random(1000)+2000);
set_dead_ob(this_object());
set_aggressive(0);
set_chat_chance(3);
  load_chat(RED+"Red"+NORM+" eyes pierce your very soul.\n");
set_chance(40);
set_spell_dam(30);
set_spell_mess1(
  "The mage utters something and watches as its foe grabs his head in pain.\n");
set_spell_mess2(
  "The mage utters: Mortriar. A blast of"+BLU+" psychic energy "+NORM+"cripples you.\n");

}
 
monster_died(){
  object ring;
  tell_object(ATTACKED,
    "The mage screams in protest then her cries are silent as a ring hits the floor.\n");
  ring = clone_object("/players/catacomb/Cavern/items/Mbring.c");
  move_object(ring, this_object());
}   