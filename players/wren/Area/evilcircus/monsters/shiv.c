	/*Shiv the Evil Clown - has juggling pins per Jaraxle's suggestion*/

inherit "/obj/monster";
#include "/players/wren/ansi.h"

reset(arg)  {
     ::reset(arg);
     if(!arg)  {

object ob,ob2,ob3;

    ob = clone_object("/players/wren/Area/evilcircus/items/razor.c");
         move_object(ob,this_object());
         command("wield razor",this_object());

    ob2 = clone_object("/players/wren/Area/evilcircus/items/pouch.c");
         move_object(ob2,this_object());

    ob3 = clone_object("/players/wren/Area/evilcircus/items/clubs.c");
         move_object(ob3,this_object());

set_name("clown");
set_alias("shiv");
set_alt_name("clown");
set_race("vampire");
set_long("A big happy smile of red is painted across this clown's \n"+
	 "mouth. Blue rings his reddish eyes. He dances merrily   \n"+
         "to the delight of the children in the room. The world   \n"+
         "loves a clown right. 	  \n");

set_level(20);
set_ac(18);
set_wc(30+random(5));
set_hp(500+random(180));
set_al(-1000);    		 /*alignment*/
set_aggressive(1);		 /*0 not, 1 is*/
set_chat_chance(5);		 /*chance per heartbeat load_chat messages*/
set_a_chat_chance(10);		 /*combat chance chance*/

load_chat("The clown juggles a set of clubs, a knife, and a small poodle.\n");
load_chat("The clown's nose honks when squeezed by a little girl.\n");
load_chat("Floppy shoes get in the way and the clown falls flat on his back.\n");
load_chat("Shiv pulls a balloon platypus out of his sleeve.\n");

load_a_chat("Your blood chills a Shiv cackles menacingly.\n");
load_a_chat("Shiv slices across your throat drawing a thin red line.\n");
load_a_chat("The clown floats up in the air and leers at you.\n");
load_a_chat("MUAHAAHAHHAHHAHAHHAAAAHAHAAAHAHAAAAA!\n");
load_a_chat("Shiv bounces an indian club off your skull and catche it.\n");
load_a_chat("Shiv says: 'Time to die little fish. Hehehehe.'\n");
load_a_chat("Shiv says: 'I do hope your blood tastes sweet.'  \n");
load_a_chat("Shiv smiles revealing ivory fangs. \n");

set_chance(5);
set_spell_dam(20+random(20));
set_spell_mess1("The cheerful clown just sang its fangs into "+attacker_ob+"'s throat. \n");    /*others*/
set_spell_mess2("The clown grins and sinks its fangs deep into your throat. \n");    /*attacker*/

    }
}

short(){if(attacker_ob) return "Vampiric Clown";  else return "A clown entertaining the crowds"; }
