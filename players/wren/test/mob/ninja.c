	/*Ninja. Basic first attempt at a monster*/

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

set_name("ninja");

set_short("A ninja cleverly disguised as a hedge");

set_race("ninja");

set_long ("These are the crafty ninja of The City's ninja franchise.\n"+
	  "This one must be on assignment to guard someone. He is \n"+
	  "cleverly disguised as a hedge with some well placed twigs \n"+
	  "on his headband. You have a strong urge to beat up this hedge.\n");

set_level(10);

set_ac(8);

set_wc(14);

set_hp(500);

set_al(-300);    			 /*alignment*/

set_aggressive(0);		 /*0 not, 1 is*/

set_chat_chance(10);		 /*chance per heartbeat load_chat messages*/

set_a_chat_chance(40);		 /*combat chance chance*/


load_chat("This is a Ninjitsu demonstration, there is nothing to see here...\n");
load_chat("The ninja unrolls his 'Opening Threat' and begins reciting.	\n");
load_chat("Ninja taunts you.\n");

load_a_chat("Complains about a bone bruise.\n");
load_a_chat("Oooh I hate those.\n");
load_a_chat("And then he threw a chimney at us...\n");


    }
}

