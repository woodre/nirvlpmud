#include "/players/jamila/define.h"

inherit "/obj/monster.c";

reset(arg) {
  ::reset(arg);
  set_dead_ob(this_object());
  if(arg) return;
  set_name("woman cashier");
  set_alt_name("woman");
  set_alias("cashier");
  set_short("A Woman Cashier");
  set_long(
"This is the woman who runs the shop.  Right now she is\n"+
"tending to the cash register.  She barely notices your\n"+
"existance as she counts her coins happily.  She is proof\n"+
"that money can buy some amount of happiness.\n"
  );
  set_gender("female");
  set_race("human");
  set_level(19);
  set_wc(28);
  set_ac(16);
  set_hp(400+random(50));
  set_al(300);
  set_chat_chance(6);  
  set_a_chat_chance(10);
  load_chat("The woman counts the coins in the register.\n");
  load_a_chat("The woman dodges trying to evade your attack.\n");
  set_chance(7);
  set_spell_mess1(
"\n\tThe woman screams as she is charged and the sound\n"+
"\t\tpierces her opponents ears.\n\n"
  ); /* 3RD PERSON */
  set_spell_mess2(
"\n\tThe woman screams as you charge at her and your ears\n"+
"\t\tburn as the sound pierces them.\n\n"
  ); /* 1ST PERSON */
  set_spell_dam(10);
}
monster_died() {
object gold;
tell_room(environment(this_object()),
  "The woman drops the coins that she was counting as death\n"+
  "takes her and she falls to the ground.\n");
  gold = clone_object("obj/money");
  gold->set_money(3000+random(500));
  move_object(gold,environment(this_object()));
return 1; }
