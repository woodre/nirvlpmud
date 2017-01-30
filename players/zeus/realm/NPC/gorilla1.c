inherit "/obj/monster";
#include "/players/zeus/closed/all.h"

reset(arg) {
   ::reset(arg);
   if (!arg) {

  set_name("gorilla");
  set_short("A black gorilla");
  set_race("gorilla");
  set_long(
"This fearsome creature is a lesser known breed of the black gorilla.\n"+
"It has a broad chest with large hands and feet, standing at about 6\n"+
"feet tall.  Most gorillas are vegetarians, however this breed feast\n"+
"on meat, and are considered superb hunters.\n");
  set_level(20);
  set_ac(20);
  set_heal(1,3);
  set_wc(30);
  set_hp(800);
  set_aggressive(0);
  set_chat_chance(5);
  set_a_chat_chance(5);
  load_chat("The black gorilla glares at you.\n");
  load_chat("The black gorilla watches you.\n");
  load_chat("The black gorilla watches the area closely.\n");
  load_a_chat("The black gorilla hits you with a crushing blow!\n");
  load_a_chat("The black gorilla smashes you with it's mighty fists!\n");
  set_chance(15);
  set_spell_dam(30);
  set_spell_mess1("The gorilla lunges at you!\n");
  set_spell_mess2("Th gorilla hits you with it's powerful fists!\n");
  set_dead_ob(this_object());
   }  
}

monster_died(){
  write("With your final hit you separate one of its hands from its arm.\n");
  MO(CO("/players/zeus/realm/OBJ/gorhand.c"), environment(TO));
  return 1; 
}
