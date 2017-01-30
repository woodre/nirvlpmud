/*
 * Pissed Fairy
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
  		gold->set_money(random(100) + 1500);
  		move_object(gold,this_object());

     	set_name("fairy");
     	set_short(""+HIK+"A pissed-off fairy"+NORM+"");
     	set_race( "Fay");
     	set_gender("female");
     	set_long("The fairy looks very pissed-off. Her wings flutter \n"+
         	     "rapidly as she stares directly at your face.\n");     
     	set_level(15);
     	set_ac(12);
     	set_wc(20);
     	set_hp(250);
     	set_al(-500);
     	set_aggressive(1);
     	set_a_chat_chance(10);
     	load_a_chat("The fairy curses at you loudly.\n");
   }
}