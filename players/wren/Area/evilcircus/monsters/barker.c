	/*Barker , illithid with charm and cruelty*/

inherit "/obj/monster2";
#include "/players/wren/ansi.h"

reset(arg)  {
     ::reset(arg);
     if(!arg)  {
/*
object ob,ob2,ob3;

    ob = clone_object("/players/wren/Area/evilcircus/items/pouch.c");
         move_object(ob,this_object());

    ob2 = clone_object("/players/wren/Area/   .c");
         move_object(ob2,this_object());

    ob3 = clone_object("/players/wren/Area/    .c");
         move_object(ob3,this_object());
*/
set_name("barker");
set_alt_name("squiggles");
set_alias("ill");
set_short("An illithid barker");
set_race("illithid");
set_gender("nueter");

set_long("This tenacled creature works the front door and does its best to entice  \n"+
	 "patrons into seeing the shows. Using a mixture of telepathy and normal \n"+
         "communications it can speak with almost anyone. His sharp clothes fail to \n"+
         "fully disguise the strange unpleasantness of its facial features.	  \n");

set_level(20);
set_ac(15+random(4));
set_wc(28+random(6));
set_hp(480+random(100));
set_al(-200);    		 /*alignment*/
set_aggressive(0);		 /*0 not, 1 is*/

set_chat_chance(10);		 /*chance per heartbeat load_chat messages*/
set_a_chat_chance(5);		 /*combat chance chance*/

set_armor_params("physical", 15, 20, "psy_defense");

set_assist("/players/wren/Area/evilcircus/hound", 10, 1, 4); 

load_chat(HIC+"	  Welcome ladies and gentleman	"+NORM+"\n");
load_chat(HIC+"	  Check out the amazing jugglers	"+NORM+"\n");
load_chat(HIC+"	  See the fierce creatures perform for your entertainment	"+NORM+"\n");
load_chat(HIC+"	  Enjoy the antics of the clowns 	"+NORM+"\n");
load_chat(HIC+"	  Give generously to the performers	"+NORM+"\n");
load_chat(HIC+"   You'll not believe your eyes		"+NORM+"\n");
load_chat(HIC+"	  Watch the show and you will not want to leave	"+NORM+"\n");
load_chat("Illithid laughs in a gurgling voice.	\n");
load_chat("Squiggles says: Go on in folks, fun for all.	\n");
load_chat("Squiggles says: Don't feed the animals, they might bite.	\n");

load_a_chat("Squiggles snickers waterly .\n");
load_a_chat("The illithid thrashes violently at its opponent.	\n");

set_chance(10);
set_spell_dam(20+random(30));
set_spell_mess1("Squiggles stares intently at his foe. \n");    /*others*/
set_spell_mess2("Squiggles scrapes through your mind with a psychic blast. \n");    /*attacker*/

    }
}

int 
psy_defense() {

   if(!random(5)) {
         tell_room(environment(),
              HIC+"Psychic energy"+NORM+" ripples around the illithid defending it from harm. \n");
              return 4002; 
            }
}

