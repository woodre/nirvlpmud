/*     Gurther blacksmith   */

inherit "/obj/monster";
#include "/players/zeus/closed/all.h"

reset(arg) {
   ::reset(arg);
   if (!arg) {

  set_name("blacksmith");
  set_alias("gurther");
  set_short("The gurther blacksmith");
  set_race("gurther");
  set_gender("male");
  set_long(
"This gurther has some signifigant differences from the other gurthers.\n"+
"He is a hulking creature, and has beautiful shiny black skin, however\n"+
"his front limbs are longer, and his fingers dont have long claws on\n"+
"them.  He has two large horns protruding from atop his narrow head.\n");
  set_level(21);
  set_hp(1200);
  set_ac(25);
  set_wc(40);
  set_al(random(400));
  set_aggressive(0);
  set_chat_chance(4);
  set_a_chat_chance(1);
  load_chat("The blacksmith works on some equipment.\n");
  load_chat("The blacksmith watches you closely.\n");
  load_chat("The blacksmith examines a sword.\n");
  load_chat("The blacksmith looks up at the sky.\n");
  load_chat("The blacksmith glances into the forest.\n");
  load_chat("The blacksmith asks: What is your business here?\n");
  load_a_chat("The blacksmith steps to the side.\n");
  set_dead_ob(TO);
   }
}


monster_died()
{
 write("With your final blow you break off one of the blacksmith's horns.\n");
  MO(CO("/players/zeus/realm/OBJ/ghorn.c"), environment());  
return 1; 
}
