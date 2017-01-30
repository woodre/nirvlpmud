	/* Kryten */

#include <ansi.h>
inherit "/obj/monster";

reset(arg)  {
     ::reset(arg);
     if(!arg)  {

object ob,ob2,ob3;

    ob = clone_object("/players/wren/Area/starbug/items/laundry.c");
         move_object(ob,this_object());
    ob2 = clone_object("/players/wren/Area/starbug/items/groinal.c");
         move_object(ob2,this_object());
    ob3 = clone_object("/players/wren/Area/starbug/items/sparehead.c");
         move_object(ob3,this_object());
         command("wield head",this_object());

set_name("kryten");
set_alias("badass");
set_short("Kryten, tidying up");
set_race("mechanoid");
set_long("Kryten is a service android built to do cleaning and light labor \n"+
         "around the home. Unfortunately he was alone on an asteroid for \n"+
         "too long and became a bit off. Lister has been trying to teach \n"+
         "him how to break his programming and he has learned several bad \n"+
         "habits of which he is quite proud.\n");

set_level(17);
set_ac(14);
set_wc(24);
set_hp(350);
set_al(500);    	         /*alignment*/
set_aggressive(0);		 /*0 not, 1 is*/
set_chat_chance(5);		 /*chance per heartbeat load_chat messages*/
set_a_chat_chance(5);		 /*combat chance chance*/
load_chat("Kryten stomps around looking for his eternal enemy the dust bunny.\n");
load_chat("Kryten says: 'Smeeeeeeeehhhheeeeeeeee!'\n");
load_chat("Krtyen says: 'Space Corp directive 258.432 stroke 9, sir. Interesting but\n"+
          "               I don't see how sacrificing poultry will fix the navi com.'\n");
load_chat("Kryten slaps the sci scan. \n"+
          "Kryten says: 'One moment sirs. Model 345 still outperformed 346 in 8 of 9 benchtests.' \n");
load_a_chat("Kryten says: 'I'm sorry but this is going to delay lunch.\n");
load_a_chat("Kryten says: 'But who's going to do the laundry, I've got gussets to scrub'.\n");
load_a_chat("Kryten holds Lister's dirty laundry under your nose, you retch painfully. \n");
load_a_chat("Kryten demonstrates his anger with mindless violence skill.\n");

    }
}

