inherit "/obj/monster";
#include "/players/zeus/closed/all.h"

reset(arg) {
   ::reset(arg);
   if (!arg) {

  set_name("brown bear");
  set_alias("bear");
  set_short("A large brown bear");
  set_race("bear");
  set_long(
"This powerful creature is a large brown bear.  It has made it's home\n"+
"in The Fallen Lands and is now one of it's many guardians.  It has\n"+
"huge paws adorned with sharp claws.  Eyes, piercing red like the\n"+
"satanic fires of hell.  Truly a beast to fear, you have been warned.\n");
  set_level(20);
  set_ac(15+random(4));
  set_wc(33);
  set_hp(575);
  set_al(0);
  set_aggressive(0);
  set_chat_chance(5);
  set_a_chat_chance(5);
  load_chat("The bear glares at you.\n");
  load_chat("The bear breathes slowly.\n");
  load_chat("The bear growls deeply.\n");
  load_chat("The bear moves slowly around the room.\n");
  load_a_chat("The bear hits you with a crushing blow!\n");
  load_a_chat("The bear bites you with it's mighty jaws!\n");
  load_a_chat("The bear rips into you with it's claws!\n");
  set_chance(15);
  set_spell_dam(60);
  set_spell_mess1("The bear growls at you!\n");
  set_spell_mess2("The bear growls at you!\n");
  set_dead_ob(this_object());
   }  
}

monster_died(){
  write("As the brown bear collapses to "+
    "the ground a tuft of its fur falls out.\n");
  MO(CO("/players/zeus/realm/OBJ/beartuft.c"), environment());
  return 1; 
}
