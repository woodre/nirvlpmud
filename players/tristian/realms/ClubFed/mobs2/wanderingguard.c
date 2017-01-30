inherit "obj/monster.c";
#include "/players/tristian/lib/ClubFeddefine.h"
id(str) { return (::id(str) || str == "guard" ); }

reset(arg){
  ::reset(arg);
  if (arg) return;

  set_name("Prison Guard");
  set_alt_name("guard");
  set_race("human");
  set_alias("guard");
  set_gender("male");
  set_short("Prison Guard");
  set_long(
    "This is a run of the mill prison guard, he is walking the prison keeping\n"+
    "an eye on all the convicts. He is wearing a uniform, and a belt filled\n"+
    "with the normal prison guard items, including a billy club, mace, and handcuffs.\n\n");
  set_level(20);
  set_ac(50+random(10));
  set_wc(35+random(10));
  set_hp((1000)+random(200));
  set_al(-1);
  set_aggressive(1);
  set_heart_beat(1);
  set_wander(1);
  set_wander_interval(5);
  set_wander_realm("/players/tristian/realms/ClubFed/rooms/");
  add_money(3500+random(1500));
  set_chat_chance(10);
  load_chat(
    "The guard states:  'What are you doing out of your cell?'\n");
  set_a_chat_chance(10);
  load_a_chat(
    "The guard cries for help and sprays you with pepper spray.\n");


  set_dead_ob(this_object());
  set_chance(40);
  set_spell_dam(40+random(20));

  set_spell_mess1(
    HIC+"\nThe guard pounds on you with his billy club.\n"+NORM);
  set_spell_mess2(
    HIC+"\nThe guard pounds on you with his billy club.\n"+NORM);
}
