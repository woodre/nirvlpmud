	/* Darth WREN, no offense meant. I thought it would be amusing.       */
        /*             could easily be set up to accomodate other wizes too.  */
        /*             mostly intended as a test mob for special damage types */

#include <ansi.h>
inherit "/obj/monster";

reset(arg)  {
     ::reset(arg);
     if(!arg)  {

set_name("darth");

set_alias("wren");

set_alias("sith");

set_short("Jedi taste funny - says Darth Wren the SITH. (lord of evil).");

set_race("elf");

set_long("Jedi taste funny - says Darth Wren the SITH. (lord of evil) (male) \n"+
         "Darth Wren. A student of Vertebraker,a destroyer of worlds, a	\n"+
	 "breaker of code. It is clear the world has been to harsh and \n"+
         "pushed this once good wizard to the dark side. He stands ready \n"+
         "to slay at whim so beware. It would be wise not to vex him. \n"+
         "==> wizard. \n"+
         "Wren is an elf, 5 feet 2 inches tall, 209 lbs.\n"+
         "Wren is in good shape.\n"+
         "Wren is spiffy evil.\n"+
         "Wren has a small "+YEL+"gold star"+NORM+" tattoo on his inside right ankle.\n"+
         "Wren is an ally of the Servants of Shardak. \n"+
         "        Wren is carrying: \n"+
         "Lightsabre.\n"+
         "a "+HIK+"pe"+HIW+"ngu"+HIK+"in"+NORM+" handpuppet (wielded).\n"+
         "Wren's Wiztool.\n"+
         "The Mark of an ally.\n"+
         "A lump of magical clay.\n")+


set_level(28);

set_ac(26);

set_wc(52);

set_hp(1800);

set_al(-10000);			 /*alignment*/

set_aggressive(0);		 /*0 not, 1 is*/

set_chat_chance(1);		 /*chance per heartbeat load_chat messages*/

set_a_chat_chance(5);		 /*combat chance chance*/


load_chat("Wren scans the area.\n");
load_chat("Wren looks at the board.\n");
load_chat("Wren nods solemnly.\n");

load_a_chat("Wren scans your mind.\n");
load_a_chat("Wren chuckles as he plots your demise.\n");

set_chance(10);
set_spell_dam(30);

set_spell_mess1("Wren lashes out with "+HIB+"DARK LIGHTNING"+NORM+". \n");
set_spell_mess2("Wren strikes you down with "+HIB+"DARK LIGHTNING"+NORM+". \n");

set_chance(20);
set_spell_dam(15);

set_spell_mess1("Wren catches his attacker in a force choke.\n");
set_spell_mess2("Wren chokes you with a gesture .\n");

set_chance(5);
set_spell_dam(50);

set_spell_mess1("Wren "+HIK+ "SLICES"+NORM+" his foe with his lightsaber.\n");
set_spell_mess2("Wren "+HIK+ "SLICES"+NORM+" you with his lightsaber.\n");



    }
}

