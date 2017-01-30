	/* Paranoia */

#include <ansi.h>
inherit "/obj/monster";

reset(arg)  {
     ::reset(arg);
     if(!arg)  {

set_name("paranoia");
set_short("Paranoia slinks around");
set_race("illusion");
set_long("A strange being that appeared after Lister caught a mutated flu strain.\n"+
	 "Unlike his counterpart this guy seems unhappy and reserved. He looks at \n"+
         "you through red eyes. He doesn't look like he gets much sleep. He twitches \n"+
         "as your eyes pass over him, it seems he is expecting to get hurt.\n");

set_level(14);
set_ac(11);
set_wc(18);
set_hp(220);
set_al(500);    	         /*alignment*/
set_aggressive(0);		 /*0 not, 1 is*/
set_chat_chance(5);		 /*chance per heartbeat load_chat messages*/
set_a_chat_chance(10);		 /*combat chance chance*/
load_chat("Paranoia says: 'Lister didn't finish potty training till he started school'.\n");
load_chat("Paranoia says: 'I bet you still wet the bed'.\n");
load_chat("Paranoia says: 'You suck!' \n");
load_a_chat("Paranoia snivels at you.\n");
load_a_chat("Paranoia says: 'You'd be better off commiting suicide'.\n");
load_a_chat("Paranoia says: 'You can't beat me, you are a complete loser'.\n");

    }
}
