/*Comorant mercenary and barterer*/
#include "/sys/lib.h"
#include "/sys/ansi.h"

inherit "/obj/monster";
reset(arg)  {
     ::reset(arg);
     if(!arg)  {
/*
object ob,ob2,ob3;

    ob = clone_object("/players/wren/   .c");
         move_object(ob,this_object());

    ob2 = clone_object("/players/wren/   .c");
         move_object(ob2,this_object());

    ob3 = clone_object("/players/wren/Area/    .c");
         move_object(ob3,this_object());
*/

set_name("cormorant");

set_short("Cormorant the Mercenary");

set_alias("merchant");

set_race("wolfen");

set_long("A roguish wolfen from the Northern Wastes. He wears a dark cloak   \n"+
         "over rugged leather jerkins and pants. He has pouches and scabbards\n"+
	 "hanging from belts around his waist and from a baldric slung across\n"+
         "his left shoulder. A quiver and bow hang across his right shoulder.\n"+
         "He is reported to deal in currency and sometimes shadier dealings. \n"+
         "If you need something moved quickly he can probably arrange it.    \n");

set_level(15);

set_ac(12);

set_wc(21);

set_hp(random(50)+250);

set_al(-20);    			 /*alignment*/

set_aggressive(0);		 /*0 not, 1 is*/

set_chat_chance(5);		 /*chance per heartbeat load_chat messages*/

set_a_chat_chance(10);		 /*combat chance chance*/


load_chat("Cormorant says 'What can I do for you?'\n");
load_chat("Cormorant smirks and polishes a silver goblet.\n");
load_chat("Cormorant says 'Be sure to watch out around that circus'.\n");
load_chat("Cormorant sniffs the air carefully.\n");

load_a_chat("Cormorant yells: 'You bastard, I'll kill you.'\n");
load_a_chat("Cormorant howls and strikes you viciously.	\n");
load_a_chat("Cormorant growls and chomps you with his sharp canines.\n");

set_chance(10);
set_spell_dam(20);
set_spell_mess1("Cormorant takes careful aim and lets fly an arrow. \n");              /*others*/
set_spell_mess2("Cormorant grins evilly as he nocks an arrow. He draws a bead \n"+
		"on you and fires. The arrow buries itself deep in your flesh.  \n");  /*attacker*/


    }
}

/*
   add function to hire. He will follow user in the area for 10k. won't
   fight but can be used to 'exchange' to. For say 40k he'll follow and add 
   hits with his bow. An occasional extra bit of damage around random(10)+5
   He'll periodically check to see if he'll stick around otherwise run back
   to starting point. Can be bought off to delay his departure.
*/ 
