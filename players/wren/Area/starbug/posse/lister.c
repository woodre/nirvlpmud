	/* Lister */

#include <ansi.h>
inherit "/obj/monster";

reset(arg)  {
     ::reset(arg);
     if(!arg)  {

object ob,ob2,ob3,ob4;

    ob = clone_object("/players/wren/Area/starbug/items/currie.c");
         move_object(ob,this_object());
    ob2 = clone_object("/players/wren/Area/starbug/items/dreds.c");
         move_object(ob2,this_object());
         command("wear dreds",this_object());
    ob3 = clone_object("/players/wren/Area/starbug/items/jacket.c");
         move_object(ob3,this_object());
         command("wear jacket",this_object());
    ob4 = clone_object("/players/wren/Area/starbug/items/guitar.c");
         move_object(ob4,this_object());
         command("wield guitar",this_object());

set_name("lister");
set_alias("dave");
set_short("Dave Lister");
set_race("human");
set_long("Dave Lister, last human in existance. Well that was true, recently \n"+
         "things have changed. He was put into stasis for smuggling a cat on \n"+
         "board through quarintine. It would've been a beauty of a plan, he'd\n"+
         "joined Space Corp for a free ride back to earth. This offense would\n"+
         "have net him 3 months without having to do anything. Unfortunaly.  \n"+
         "the stasis leak that killed the crew took 2 million years to dissipate.\n"+
         "Now he's one of the biggest slobs in the universe. Occupation BUM. \n"+
         "Beware his guitar playing, it hurts a lot. \n");

set_level(17);
set_ac(14);
set_wc(24);
set_hp(350);
set_al(500);   			 /*alignment*/
set_aggressive(0);		 /*0 not, 1 is*/
set_chat_chance(5);		 /*chance per heartbeat load_chat messages*/
set_a_chat_chance(5);		 /*combat chance chance*/
load_chat("Lister says: 'Oh aye, I remember that. Heh that was funny.'	\n");
load_chat("Lister says: 'Rimmer you're a total ponse you know that.'	\n");
load_chat("Lister says: 'Currie is the one thing that let me feel normal.' \n");
load_chat("Lister says: 'Anyone fancy a kabob or some vindaloo.' \n");
load_chat("Lister says: 'We don't loot, we just blast our way in and take what we need.'\n");
load_a_chat("Lister swings his guitar at you with all his might.\n");
load_a_chat("Lister says: 'You're such a smeghead'.		\n");
load_a_chat("You're ears bleed as Lister plays a power chord.\n");

    }
}

