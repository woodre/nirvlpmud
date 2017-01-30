	/*Dwayne Dibbly*/

#include <ansi.h>
inherit "/obj/monster";

reset(arg)  {
     ::reset(arg);
     if(!arg)  {

object ob,ob2;
    ob = clone_object("players/wren/Area/starbug/items/thermos.c");
         move_object(ob,this_object());
    ob2 = clone_object("players/wren/Area/starbug/items/lunchbox.c");
         move_object(ob2,this_object());

set_name("dwayne");
set_alt_name("dork");
set_alias("dibbly");
set_short("Dwayne Dibbly, the utter dork");
set_race("cat");
set_long("Dwayne Dibbly, the duke of dork. He stands before you in a sensible shirt\n"+
         "plaid pants, and squeeky leather shoes. This is the uncool version of the Cat	\n"+
	 "This accident prone geek sports the fashionable bowl haircut and buck teeth\n"+
         "that could double as bottle openers.	  \n");
set_level(16);
set_ac(14);
set_wc(22);
set_hp(300);
set_al(500);   			 /*alignment*/
set_aggressive(0);		 /*0 not, 1 is*/
set_chat_chance(5);		 /*chance per heartbeat load_chat messages*/
set_a_chat_chance(8);		 /*combat chance chance*/
load_chat("Dwayne says: 'Lemme see if I got everything, got my thermos, \n"+
          "              got my lunchbox, and got one triple thick \n"+
          "              condom, cause you never know *winks*	\n");
load_chat("Dwayne says: 'Suck my thermos, I don't want to stay like this.\n");
load_a_chat("Dwayne says: 'Throw it, but I throw like a girl.\n");
load_a_chat("Dwayne trips over something and smashes your foot. OUCH	\n");
    }
}
