#include "/players/wocket/closed/ansi.h"
inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {

object gold;
  gold = clone_object("obj/money");
  gold->set_money(random(50) + 80);
  move_object(gold,this_object());

     set_name("patron");
     set_short("A Bar Patron");
     set_race("human");
     set_alias("man");
     set_long("This is a patron who has had one to many drinks.\n");
     set_level(3);
     set_ac(4);
     set_wc(7);
     set_hp(50);
     set_al(0);
     set_aggressive(0);
     set_chat_chance(7);
     load_chat("The patron says, \"I'm not as trunk as you dink I am.\"\n");
     load_chat("A patron burps loadly.\n");
   }
}
