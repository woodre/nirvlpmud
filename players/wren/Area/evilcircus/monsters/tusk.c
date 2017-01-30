	/*Tusk the troll cannonball*/

inherit "/obj/monster";
#include "/players/wren/ansi.h"

reset(arg)  {
     ::reset(arg);
     if(!arg)  {
/*
object ob,ob2,ob3;

    ob = clone_object("/players/wren/Area/evilcircus/items/pouch.c");
         move_object(ob,this_object());

    ob2 = clone_object("/players/wren/Area/evilcircus/items/helm   .c");
         move_object(ob2,this_object());

    ob3 = clone_object("/players/wren/Area/evilcircus/items/flask    .c");
         move_object(ob3,this_object());
*/
set_name("tusk");
set_alt_name("cannonball");
set_alias("trollcannonball");
set_short("Tusk the TrollCannonball");
set_race("troll");
set_gender("male");

set_long("Tusk is a squat squarely built Kanyon Troll. His height tops \n"+
	 "at 4'5''. A tough hide covers his heavily muscled frame. His \n"+
         "incredible resistance to damage led him to a career in stunts\n"+
         "which is what he does here at the circus. Tusk blows himself \n"+
         "out of a cannon to speed from one side of the arena to the other.\n"+
         "He seems to be enjoying himself and is grinning showing off the \n"+
         "pronounced dental features that gave him his name. \n");

set_level(16);

set_ac(12+random(6));
set_res(20+random(30));

set_armor_params("magical",20,10,"spec");

set_wc(18+random(8));
set_hp(300+random(300));
set_heal(20,20);
set_al(-10);   			 /*alignment*/
set_aggressive(0);		 /*0 not, 1 is*/
set_chat_chance(1);		 /*chance per heartbeat load_chat messages*/
set_a_chat_chance(1);		 /*combat chance chance*/

load_chat("Tusk waves to the audience and pats the cannon.\n");
load_chat("The show lights gleem off Tusk's tusks.\n");

load_a_chat("Tusk punches you squarely in the jaw.\n");
load_a_chat("You get roundhoused by Tusk.\n");
load_a_chat("Tusk puts you into a headlock.\n");

set_chance(10);
set_spell_dam(10+random(20));
set_spell_mess1("Tusk fires himself out of the cannon into his attacker.\n");    /*others*/
set_spell_mess2("BOOM! Tusk flies from the cannon barreling into you. \n");    /*attacker*/

    }
}

spec() {
    write("The trolls tough hide resists the mystic assault.\n");
    return 1812;
        }

