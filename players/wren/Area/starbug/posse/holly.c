	/* Holly on the cart, hehe */

#include <ansi.h>
inherit "/obj/monster";

reset(arg)  {
     ::reset(arg);
     if(!arg)  {


set_name("holly");
set_alias("holly 2");
set_alt_name("holly2");
set_alias("cart");
set_short("Holly on his cart");

set_race("ai");

set_long("This is Holly's mobile form. He can wheel around all over the 	\n"+
	 "place to catch up with the Dwarfers when they are off ship. It \n"+
         "can go zero to ten in twenty minutes. Not much offensive power \n"+
         "though. He's distracted trying to master light speed travel.	 \n");

set_level(12);

set_ac(9);

set_wc(16);

set_hp(180);

set_al(500);    			 /*alignment*/

set_aggressive(0);		 /*0 not, 1 is*/

set_chat_chance(10);		 /*chance per heartbeat load_chat messages*/

set_a_chat_chance(10);		 /*combat chance chance*/


load_chat("Holly bangs his head on the screen to count. 'Ten'.	\n");
load_chat("Holly says: 'You know, theory of relativity. Its the theory \n"+
          "             you only tell your relatives.		\n");
load_chat("Holly says: I have an IQ of 4000, roughly the equivilent of 4000 PE teachers.  \n");

load_a_chat("Holly runs over your toes.	\n");
load_a_chat("Holly says: 'Explain this...'\n");
load_a_chat("Holly says: 'You can't can you.\n");



    }
}

