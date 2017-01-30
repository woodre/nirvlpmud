inherit "/obj/monster";
int lvl,wcc;

reset(arg) {
   ::reset(arg);
   if (!arg) {
object ob2, ob3, gold;
 gold = clone_object("obj/money");
gold->set_money((875));
  move_object(gold,this_object());
     set_name("driver");
set_short("A Pizza Hut Driver");
     set_race( "human");
set_long("This is a delivery man, he looks like he might have some tip money on him.\n");
     set_level(15);
     set_ac(12);
     set_wc(20);
     set_hp(225);
     set_al(-500);
     set_aggressive(0);
     set_chat_chance(20);
     set_a_chat_chance(20);
      load_chat("The driver pushes you out of his way!\n");
      load_chat("The driver yells : What's my next delivery?!\n");
      load_chat("The driver tries to look busy while waiting for his next run.\n");
      load_chat("The driver mumbles something about getting stiffed again.\n");
      load_a_chat("The driver scratches you with his keys.\n");
      load_a_chat("Driver screams : See if I deliver to you ever again!\n");
      load_a_chat("Driver kicks you between the legs.\n");
   }
}
#include "/players/emerson/closed/def_hb.h"
