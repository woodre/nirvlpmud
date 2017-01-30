	/*scutter 1*/

#include <ansi.h>
inherit "/obj/monster";

reset(arg)  {
     ::reset(arg);
     if(!arg)  {

object ob;

    ob = clone_object("/players/wren/Area/starbug/items/cowboyhat.c");
         move_object(ob,this_object());

    
set_name("scutter");

set_alias("bob");

set_short("Scutter wearing a cowboy hat");

set_race("robot");

set_long("This is 'Bob' the scutter. He's one of the most useful little robots	\n"+
	 "to be found on the ship. Scutters are the service robots that go where \n"+
         "humanoids have trouble getting into. They look like three fingered hands\n"+
         "on rectangular bases. A multi function optic device on the back of\n"+
         "their hands provides input. They follow directions fairly well though\n"+
         "these two have had time to break programming. They love John Wayne movies \n"+
         "and playing cowboys and indians.\n");

set_level(5);

set_ac(6);

set_wc(10);

set_hp(80);

set_al(500);    		 /*alignment*/

set_aggressive(0);		 /*0 not, 1 is*/

set_chat_chance(5);		 /*chance per heartbeat load_chat messages*/

set_a_chat_chance(10);		 /*combat chance chance*/


load_chat("Scutter checks a wiring connection.	\n");
load_chat("Scutter paints the walls.		\n");
load_chat("Scutter checks to see if Rimmer is watching, then heads to the movies.\n");

load_a_chat("Scutter shoots his cap gun at you.	\n");
load_a_chat("Scutter gives you a two finger salute.\n");



    }
}

