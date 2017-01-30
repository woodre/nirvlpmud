	/* Gelf1 */

#include <ansi.h>
inherit "/obj/monster";

reset(arg)  {
     ::reset(arg);
     if(!arg)  {

object ob,ob2;

    ob = clone_object("/players/wren/Area/starbug/items/ogunit.c");
         move_object(ob,this_object());
    ob2 = clone_object("/players/wren/Area/starbug/items/levis.c");
         move_object(ob2,this_object());

set_name("gelf");
set_alias("chief");
set_alias("kinitawowi");
set_short("Gelf Chief of Kinitawowi");
set_race("gelf");
set_long("The gelf chieftan of the Kinitawowi. A tribe where not skinning \n"+
         "you alive on first contact is considered high honor. These mutated \n"+
         "creatures were meant to be used for terraforming planets but they \n"+
         "broke free and established colonies all around the wildest depths \n"+
         "of space. He brokered a deal between the the Dwarfers for a new OG \n"+
         "Unit at the price of Lister's hand in marriage to his daughter. \n"+
         "Things didn't work out well. He appears like a gorrila crossed \n"+
         "with a hippo with a lineman's armpit must look like. \n");

set_level(14);
set_ac(11);
set_wc(18);
set_hp(240);
set_al(-200);  			 /*alignment*/
set_aggressive(0);		 /*0 not, 1 is*/
set_chat_chance(20);		 /*chance per heartbeat load_chat messages*/
set_a_chat_chance(5);		 /*combat chance chance*/

load_chat("Chieftan says: 'OG nah, ech ot nah..eh hetagah ech?'\n");
load_chat("Chieftan watches for a response and points to his daughter.\n");

load_a_chat("Chieftan shouts: 'Ech-ech-ech-ech-ech!'\n");
load_a_chat("Chieftan tackles you with his rolling flesh. Gross.\n");

    }
}

