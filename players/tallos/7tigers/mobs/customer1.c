#include "/players/wocket/closed/ansi.h"
inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {

object gold;
  gold = clone_object("obj/money");
  gold->set_money(random(140) + 80);
  move_object(gold,this_object());

     set_name("customer");
     set_short("A Hotel Customer");
     set_race("human");
     set_alias("man");
     set_long("This is one of the many customers staying in the inn.\n");
     set_level(5);
     set_ac(5);
     set_wc(9);
     set_hp(80);
     set_al(0);
     set_aggressive(0);
     set_chat_chance(7);
     load_chat("The customer says, \"I love this place.\"\n");
     load_chat("A customer examines the paintings.\n");
   }
}
