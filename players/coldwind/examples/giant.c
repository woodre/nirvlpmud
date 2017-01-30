#include "/players/coldwind/define.h"
inherit "obj/monster.c";

reset(arg)  {
  ::reset(arg);
  if(arg) return;
move_object(clone_object("/players/coldwind/examples/mace.c"),this_object());
init_command("wield weapon");
move_object(clone_object("/players/coldwind/examples/tunic.c"),this_object());
init_command("wear armor");

set_name("giant");
set_alt_name("slave");
set_race("giant");
set_short(HIR+"Red giant slave"+NORM);
set_long(HIR+
"  The red giant eyes you nervously as he walks slowly closer to you.\n"+ 
"His skin is bloody red, while his eyes, hair and beard have a darker wine \n"+  
"red color. He wears a red tunic and moves his huge mace angrily.\n"+
"It was said that a witch was able to control some giants by allowing the evil \n"+
"souls to take over their bodies and minds.\n"+NORM);
set_level(17);
set_hp(230);
set_al(0);
set_wc(28);
set_ac(15);
set_ac_bonus(3);
set_aggressive(0);
set_chat_chance(5);
  load_chat("The slave screams madly...\n"+
  "          GUAARAAAAHH\n");
  load_chat("You take a step to the back.\n");
  load_chat("The giant moves his weapon angrily.\n");
set_a_chat_chance(15);
  load_a_chat("The giant glares at you.\n");
  load_a_chat("The giant throws a wild swing at you!\n");
  load_a_chat("The slave turns to you and attacks...\n");

}

