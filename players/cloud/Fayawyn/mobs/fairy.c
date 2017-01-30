/*
 * Evil Fairy
 * Cloud 2009
 */

 
#include "/obj/ansi.h"

inherit "/obj/monster";

reset(arg) 
{
   ::reset(arg);
   if (!arg) 
   {

		object gold;
		gold = clone_object("obj/money");
		gold->set_money(random(100) + 2000);
		move_object(gold,this_object());

     	set_name("fairy");
     	set_short(""+HIK+"An evil fairy"+NORM+"");
     	set_race( "Fay");
     	set_gender("male");
     	set_long("The fairy hovers just inches off the platform supplying you\n"+
              "with an evil grin. His tattered wings flutter rapidly.\n");     
     	set_level(17);
     	set_ac(14);
     	set_wc(24 + random(2));
     	set_hp(340);
     	set_al(-500);
     	set_aggressive(0);
     	set_chat_chance(1);
     	set_a_chat_chance(10);
     	load_chat("The fairy lands and rests his wings.\n");
     	load_a_chat("The fairy curses loudly.\n");
   }
}
