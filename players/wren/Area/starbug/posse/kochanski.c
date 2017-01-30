	/* Kochanski */

#include <ansi.h>
inherit "/obj/monster";

reset(arg)  {
     ::reset(arg);
     if(!arg)  {

object ob,ob2;

    ob = clone_object("/players/wren/Area/starbug/items/wrench.c");
         move_object(ob,this_object());
         
    ob2 = clone_object("/players/wren/Area/starbug/items/cottagecheese.c");
         move_object(ob2,this_object());
         

set_name("kochanski");

set_alias("kristine");

set_short("Kristine Kochanski");

set_race("human");

set_long("Kristine Kochanski. The woman that Lister has been obsessed with for \n"+
         "centuries. This incarnation of her was trapped here when Lister's gelf \n"+
         "in-laws blew up the transdimensional causeway. She is a smart officer \n"+
         "which still leaves the galaxy wondering what she see's in Lister. The \n"+
         "primitive conditions on ship have left her a bit frazzled. She is curled \n"+
         "up with a bowl of cottage cheese with pine apple chunks in and a pipe wrench \n"+
         "to 'adjust' the noisy plumbing.  \n");

set_level(17);

set_ac(14);

set_wc(24);

set_hp(350);

set_al(500);    	 	 /*alignment*/

set_aggressive(0);		 /*0 not, 1 is*/

set_chat_chance(5);		 /*chance per heartbeat load_chat messages*/

set_a_chat_chance(5);		 /*combat chance chance*/


load_chat("Kochanski says: 'I just want a hot bath and clean clothes is that too much to ask'.	\n");
load_chat("Kochanski says: 'I have got to get back to my dimension'.	\n");
load_chat("Kochanski says: 'Screlunkle, Retut, Hanunga...where did Krechle come from'. \n");


load_a_chat("Kochanski hits you with her wrench.\n");
load_a_chat("You are distracted by the strange creaks and rattles from the ships plumbing.\n");
load_a_chat("Kochanski kicks you in the nose. OUCH.\n");



    }
}

