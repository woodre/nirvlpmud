#include "/players/catacomb/misc/ansi.h"
inherit "obj/monster.c";
object platter;

reset(arg)  {
  ::reset(arg);
  if(arg) return;

set_name("chilror");
set_race("durkor");
set_short("Chilror Shaigan");
set_long(
  "  The serving girl of Gloom's Breath.  Her pale skin accents her\n"+
  "mysterious beauty.  The alluring silhouette of the durkor female\n"+
  "often results in a patron leaving on their back.  She has been \n"+
  "toughened through the years of working at the tavern and now she\n"+
  "treats all who offend her to a old fashioned ass kicking.\n");
 
set_level(18);
set_hp(400);
set_al(100);
set_dead_ob(this_object());
set_aggressive(0);
set_ac(15);
set_wc(25 + random(5));
add_money(1500 + random(1000));
set_chat_chance(3);
  load_chat("Chilror asks you: What do you want?\n");
set_a_chat_chance(2);
  load_a_chat("Chilror says: Is that all you got?\n");
  load_a_chat("Chilror yells: Jortar, we got another live one!\n");

set_chance(5);
set_spell_dam(20+random(30));
set_spell_mess1(			
  "Chilror introduces her fist to her enemy's face.\n");
set_spell_mess2(			
  "Chilror pummels you with a barrage of punches, "+RED+"red takes over your vision.\n"+NORM);

platter = clone_object("players/catacomb/Sivart/items/platter.c");
move_object(platter, this_object());


}
  