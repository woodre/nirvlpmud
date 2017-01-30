#include "/players/wocket/closed/ansi.h"
inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {

object gold;
  gold = clone_object("obj/money");
  gold->set_money(random(160) + 100);
  move_object(gold,this_object());

     set_name("Adventurer");
     set_short("Wayward Adventurer");
     set_race( "human");
     set_alias("adventurer");
     set_long("This appears to be a beginning adventurer. He has come here to further his experience.\n");
     set_level(6);
     set_ac(5 + random(3));
     set_wc(10);
     set_hp(70 + random(40));
     set_al(0);
     set_aggressive(0);
     set_chat_chance(7);
     set_a_chat_chance(5);
     load_chat("The adventurer says, \"I'm going to be strong one day!\"\n");
     load_chat("The adventurer sharpens his "+BLK+"blade"+NORM+".\n");
     load_a_chat("The adventurer Lunges at you!\n");
     load_a_chat("\"I will slay you!\", the adventurer yells.\n");
   }
}
