inherit "/obj/monster";
#include "/players/zeus/closed/all.h"

object armor, bsword;

reset(arg) {
   ::reset(arg);
   if (!arg) {

 armor = CO("/players/zeus/realm/OBJ/tunic.c");
 MO(armor, TO);
   init_command("wear tunic");

 bsword = CO("/players/zeus/realm/OBJ/bsword.c");
 MO(bsword, TO);
   init_command("wield sword");

  set_name("hunter");
  set_short("A hunter");
  set_race("human");
  set_long(
"This is a master hunter of the forest.  He has spent his life hunting\n"+
"in these parts.  He is a very tough, grizzled man.  His face is one of\n"+
"rock hard determination.  He is wearing a leather tunic which looks\n"+
"as though it has been around longer than he has.  He is a great fighter.\n");
  set_gender("male");
  set_level(19);
  set_ac(16);
  add_money(random(1000));
  set_wc(30+random(3));
  set_hp(500);
  set_al(-10);
  set_aggressive(0);
  set_chat_chance(4);
  set_a_chat_chance(5);
  load_chat("The hunter watches you.\n");
  load_chat("The hunter examines you.\n");
  load_chat("The hunter looks into the forest.\n");
  load_chat("The hunter scratches his neck.\n");
  load_chat("The hunter glances behind him.\n");
  load_a_chat("The hunter hits you with a crushing blow!\n");
  load_a_chat("The hunter growls at you.\n");
  set_chance(40);
  set_spell_dam(20);
  set_spell_mess1("The hunter evades the attack.\n");
  set_spell_mess2("The hunter slices you with a critical attack!\n");
} }
