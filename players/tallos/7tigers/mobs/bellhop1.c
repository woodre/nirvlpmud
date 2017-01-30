#include "/players/wocket/closed/ansi.h"
inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {

object gold;
  gold = clone_object("obj/money");
  gold->set_money(random(50) + 80);
  move_object(gold,this_object());

     set_name("bellhop");
     set_short("A Bell Hop");
     set_race("human");
     set_alias("hop");
     set_long("This appears to be a bellhop. He is moving about helping customers.\n");
     set_level(3);
     set_ac(4);
     set_wc(7);
     set_hp(50);
     set_al(0);
     set_aggressive(0);
     set_chat_chance(7);
     load_chat("The bell hop asks, \"Can I take your bags?\"\n");
     load_chat("The bell hop moves over and helps a person with their bags.\n");
   }
}
