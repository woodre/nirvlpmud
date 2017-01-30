/*
 * Evil Fairy Matriarch
 * Cloud 2007
 */

 
#include "/obj/ansi.h"

inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {

object gold;
  gold = clone_object("obj/money");
  gold->set_money(random(100) + 2000);
  move_object(gold,this_object());

     set_name("matriarch");
     set_alt_name("fairy");
     set_short(""+HIK+"An evil fairy matriarch"+NORM+"");
     set_race( "Fay");
     set_gender("female");
     set_long("A well dressed fairy with something on her mind. She\n"+
              "seems to be planning something over and over in her head.\n");     
     set_level(17);
     set_ac(15);
     set_wc(24 + random(3));
     set_hp(360);
     set_al(-500);
     set_aggressive(0);
     set_chat_chance(1);
     set_a_chat_chance(10);
     load_chat("The fairy counts quietly to herself.\n");
     load_a_chat("The fairy smacks you across the face with her wing.\n");
   }
}
