#include "/players/catacomb/saiyan/def.h"
inherit "obj/monster.c";
object spear, gloves;

reset(arg)  {
  ::reset(arg);
  if(arg) return;

set_name("aviera");
set_race("durkor");
set_short("Aviera Jacor");
set_long(
  "  This maiden is one of the Jacors house guards.  She gave up\n"+
  "normal life in order to become one with her spear.  Now she \n"+
  "helps guard the leader of the House Jacor.\n");
 
set_level(20);
set_hp(550);
set_al(-50);
set_dead_ob(this_object());
set_aggressive(0);
add_money(2000+random(1500));
set_chance(10);
set_spell_dam(random(30)+15);
set_spell_mess1(			
  "\nAviera enters into a rage getting hit after hit on her enemy.\n");
set_spell_mess2(			
  "\nAviera hits you with vicious onslaught of hits with her spear.\n");

spear = clone_object("players/catacomb/Sivart/items/Aspear.c");
move_object(spear, this_object());
command("wield spear",this_object());
set_wc(29 + random(4));

gloves = clone_object("/players/catacomb/Sivart/items/Agloves.c");
move_object(gloves, this_object());
init_command("wear gloves", this_object());
set_ac(17);

}
  