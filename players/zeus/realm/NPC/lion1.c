inherit "/obj/monster";
#include "/players/zeus/closed/all.h"

reset(arg) {
   ::reset(arg);
   if (!arg) {

  set_name("lion");
  set_short("A majestic lion");
  set_race("lion");
  set_long(
"The monster before you is a large golden lion.  It has a large head\n"+
"with a very beautiful mane.  Its jaw is lined with razor sharp teeth,\n"+
"and it's paws are huge.  Its eyes are watching you, studying you.\n"+
"It would appear as though it is thinking, planning, plotting.\n");
  set_level(20);
  set_ac(17);
  set_wc(35);
  set_heal(1,1);
  set_hp(475+random(25));
  set_aggressive(0);
  set_chat_chance(5);
  set_a_chat_chance(5);
  load_chat("The lion watches you closely.\n");
  load_chat("The lion sits quietly.\n");
  load_chat("The lion looks into the forest.\n");
  load_a_chat("The lion hits you with a crushing blow!\n");
  load_a_chat("The lion rips into you with it's claws!\n");
  set_chance(15);
  set_spell_dam(25);
  set_spell_mess1("The lion lunges at you!\n");
  set_spell_mess2("The lion scratches your face!\n");
  set_dead_ob(this_object());
   }  
}

monster_died(){
  write("With your final blow the lion's mane is ripped from its body.\n");
  MO(CO("/players/zeus/realm/OBJ/lionmane.c"), environment());
  return 1; 
}
