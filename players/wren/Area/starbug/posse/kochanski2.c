	/* Kochanski 2*/

#include <ansi.h>
inherit "/obj/monster";

reset(arg)  {
     ::reset(arg);
     if(!arg)  {


set_name("kochanski");

set_alias("kristine");

set_short("Kristine Kochanski");

set_race("human");

set_long("Kristine Kochanski. The woman that Lister has been obsessed with for \n"+
         "centuries. This incarnation of her was in the first few adventures and\n"+
         "was thought to have died with the crew. Lister is confronted by Rimmer \n"+
         "diguised as her at one point and several halucinations have featured \n"+
         "her. Most prominently are the psirens suggestions. She then vanishes \n"+
         "to be replaced later by a different incarnation.\n");

set_level(12);

set_ac(9);

set_wc(16);

set_hp(200);

set_al(500);    	 	 /*alignment*/

set_aggressive(0);		 /*0 not, 1 is*/

set_chat_chance(5);		 /*chance per heartbeat load_chat messages*/

set_a_chat_chance(5);		 /*combat chance chance*/


load_chat("Kochanski says: 'What happened to me. Where'd I go'.	\n");
load_chat("Kochanski says: 'Did I marry Dave?'.	\n");
load_chat("Kochanski says: 'Who are these people? What happened to Rimmer?'. \n");


load_a_chat("Kochanski hits you.\n");
load_a_chat("Kochanski punches you in the nose. OUCH.\n");
load_a_chat("Kochanski says 'I saved back three rounds one for me and each of the boys, but you deserve them.\n");


    }
}

