	/* Gelf2 */

#include <ansi.h>
inherit "/obj/monster";

reset(arg)  {
   ::reset(arg);
     if(!arg)  {

object ob,ob2;
    ob = clone_object("/players/wren/Area/starbug/items/veil.c");
         move_object(ob,this_object());
    ob2 = clone_object("/players/wren/Area/starbug/items/bouquet.c");
         move_object(ob2,this_object());
set_name("gelf");
set_alt_name("kinitawowi");
set_alias("daughter");
set_short("Gelf Chieftain's Daughter");
set_race("gelf");
set_alt_name("gelf2");
set_long("The gelf chieftans daughter. This is Ech-ech-ech-ech-ech-ech-ech \n"+
         "-ech-ech, she's the looker in the family apparently. Lister says \n"+
         "her beauty is comparable to his arm pit after several rounds of  \n"+
         "tennis. She takes a shine to Lister right off and likes the idea \n"+
         "of their wedding. She doesn't want to take no for an answer on \n"+
         "the honeymoon which leads to the plan revision of 'lets leg it'\n"+
         "She managed to track him into null space and her battleship \n"+
         "destroyed the causeway that stranded Kachanski in this dimension.\n"+
         "Removing the walrus mustache might help her looks.\n");
set_level(14);
set_ac(11);
set_wc(18);
set_hp(240);
set_al(-200);  			 /*alignment*/
set_aggressive(0);		 /*0 not, 1 is*/
set_chat_chance(5);		 /*chance per heartbeat load_chat messages*/
set_a_chat_chance(5);		 /*combat chance chance*/
load_chat("Ech-ech-ech grins lustily at you. '\n");
load_chat("Ech-ech-ech sizes you up and smiles. Your stomach lurches.\n");
load_a_chat("Gelf Translation Running: 'He left me on my wedding night'\n");
load_a_chat("Ech-ech-ech grabs you in a fleshy bear hug.\n");
load_a_chat("Gelf Translation Running: 'Men they're all bastards!'\n");
    }
}
