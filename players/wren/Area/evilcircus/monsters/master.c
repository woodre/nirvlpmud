	/*Ring Master, Vidiak master of ceremonies, Lord of the Circus */

inherit "/obj/monster";
#include "/players/wren/ansi.h"

reset(arg)  {
     ::reset(arg);
     if(!arg)  {
/*
object ob,ob2,ob3;

    ob = clone_object("/players/wren/Area/evilcircus/items/twhip.c");
         move_object(ob,this_object());
         command("wield whip",this_object()); 

    ob2 = clone_object("/players/wren/Area/   .c");
         move_object(ob2,this_object());

    ob3 = clone_object("/players/wren/Area/evilcircus/items/pouch.c");
         move_object(ob3,this_object());
*/
set_name("vidiak");
set_alt_name("master");
set_alias("ring_master");
set_short("Circus Ring Master");
set_race("dwarf");
set_gender("male");

set_long("Adorned in a fine "+RED+"red tail-coat"+NORM+" and top hat, the ring master cuts a \n"+
	 "flashy figure even for a dwarf. His dark hair is braided and tied  \n"+
         "with a "+RED+"red bow"+NORM+" as is his beard. Vidiak projects a calm strength from  \n"+
         "the performance area and it is clear that he rules this venue.  \n");

set_level(25);
set_ac(25);
set_wc(42+random(6));
set_hp(900+random(300));
set_al(-800);  			 /*alignment*/
set_aggressive(0);		 /*0 not, 1 is*/
set_heal(50,10);
set_chat_chance(5);		 /*chance per heartbeat load_chat messages*/
set_a_chat_chance(10);		 /*combat chance chance*/

load_chat("Vidiak calls: 'Welcome ladies, gentlemen and children of all ages '\n"+
            "              '  to the greatest show on earth or any other plane.'\n");
load_chat("Ring Master watches the proceedings with a warm smile.\n");
load_chat("Ring Master calls: 'Please direct your attention to the second ring.'  \n");
load_chat("Vidiak calls: 'Give a big round of applause to our performers.' \n");
load_chat("Vidiak leads the crowd in chearing for the clowns. \n");

load_a_chat("Vidiak stares through your soul.	\n");
load_a_chat("Ring Master says: 'I can't let you stop me. I've worked too hard on this.'	\n");
load_a_chat("Vidiak roundhouses you in the midsection. \n");
load_a_chat("Vidiak growls: 'I've squashed much bigger pests than you in my ten centuries.'\n");
load_a_chat("Ring Master chants quiet words of healing \n");

set_chance(15);
set_spell_dam(25+random(40));
set_spell_mess1("Vidiak's eyes flash "+HIR+"crimson"+NORM+" and his opponent screams. \n");    /*others*/
set_spell_mess2("Vidiak's eyes flash "+HIR+"crimson"+NORM+" and you feel fire running through your veins. \n");  /*attacker*/

    }
}

