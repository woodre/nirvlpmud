#include "/players/wocket/closed/ansi.h"
inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {

object gold;
  gold = clone_object("obj/money");
  gold->set_money(random(50) + 80);
  move_object(gold,this_object());

     set_name("maid");
     set_short("A Maid");
     set_race( "human");
     set_alias("woman");
     set_long("This appears to be a maid. She is moving around cleaning things.\n");
     set_level(3);
     set_ac(4);
     set_wc(7);
     set_hp(50);
     set_al(0);
     set_aggressive(0);
     set_chat_chance(7);
     set_a_chat_chance(5);
     load_chat("The maid asks, \"Can I help you?\"\n");
     load_chat("The maid cleans with her "+BLK+"broom"+NORM+".\n");
     load_a_chat("The maid hits you with her broom.\n");
     load_a_chat("The maid seems to panic.\n");
   }
}
