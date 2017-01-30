	/* Lister2 */

#include <ansi.h>
inherit "/obj/monster";

reset(arg)  {
     ::reset(arg);
     if(!arg)  {

object ob,ob2;

    ob = clone_object("/players/wren/Area/starbug/items/bat.c");
         move_object(ob,this_object());
         command("wield bat",this_object());
    ob2 = clone_object("/players/wren/Area/starbug/items/jacket.c");
         move_object(ob2,this_object());
         command("wear jacket",this_object());

set_name("lister");
set_alias("dave");
set_short("Dave Lister");
set_race("human");
set_long("Dave Lister is looking a bit psychotic here. It would appear that \n"+
         "something has taken all fear from him. He's got his war paint on \n"+
         "and looks like he's ready to do some serious damage with that ballbat\n"+
         "he's leaning on.  \n");

set_level(17);
set_ac(14);
set_wc(24);
set_hp(350);
set_al(500);   			 /*alignment*/
set_aggressive(0);		 /*0 not, 1 is*/
set_chat_chance(5);		 /*chance per heartbeat load_chat messages*/
set_a_chat_chance(5);		 /*combat chance chance*/

load_chat("Lister says: 'I say we go down to the weapons locker get out a nuke,' \n"+
          "                 strap it to me forehead, and I'll nut the smegger.' \n"+
          "                 into oblivion.'  	\n");
load_chat("Lister says: 'Rimmer you're a total ponse you know that.'	\n");
load_chat("Lister says: 'Too much talk, time for some action.' \n");
load_chat("Lister says: 'Let's clobber something!' \n");

load_a_chat("Lister swings his ballbat full force at you.\n");
load_a_chat("Lister says: 'You're such a smeghead'.\n");
load_a_chat("Lister twirls the bat badly and cracks himself in the groin.\n");

    }
}
