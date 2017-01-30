#include "/players/persephone/rooms.h"
inherit "obj/monster";
object helmt, gold;
reset(arg){
 ::reset(arg);
  if(!arg) {
   helmt=clone_object("players/persephone/armour/helmt.c");
   move_object(helmt, TOB);
   gold = clone_object("obj/money");
   gold->set_money(3000+random(2000));
   move_object(gold, TOB);
   set_name("leader");
   set_alias("warg");
   set_alias("wolf");
   set_short("Warg Leader");
   set_long("The leader of these wargs he seems to be tougher\n" +
           "and stronger than his counterparts, but just as mean\n" +
           "and loathsome\n");
   set_level (15);
   set_wc(20);
   set_ac(12);
   set_hp(225);
   set_al(-150);
   set_aggressive(0);
   set_gender(0);
   set_chat_chance(35);
   load_chat("Warg Leader screams: Come on you can do better than that\n");
   load_chat("The Warg Leader exclaims: USELESS!!!\n");
   load_chat("The Warg Leader belows: Kill those humans.\n");
   set_a_chat_chance(35);
   load_a_chat("The Warg Leader shouts: Come on wimps kill me\n");
   load_a_chat("The Warg Leader screams: Useless help, I cannot be killed\n");
   set_chance(10);
   set_spell_dam(15);
   set_spell_mess1("The Warg snarls savagely");
   set_spell_mess2("You have just been bitten by the warg. Ouch!!!");
 }
}
  
