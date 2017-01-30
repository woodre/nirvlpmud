	/* DarthNovowels, no offense meant. I thought it would be amusing.       */
        /*                could easily be set up to accomodate other wizes too.  */
        /*                mostly intended as a test mob for special damage types */

#include <ansi.h>
inherit "/obj/monster";
int Z;

reset(arg)  {
     ::reset(arg);
     if(!arg)  {

set_name("novowels");

set_alias("darth");

set_short(" ------------- Novowels ------------- (paladin) ");

set_race("sith");

set_long("------------- Novowels ------------- (paladin) (male) \n"+
         "Darth Novowels. A creation from Wren's Evil Cloning Labs(tm).	\n"+
	 "Beware of the clone invasion. Their approach is nigh unstoppable. \n"+
         " \n"+
         " \n"+
         "Novowels is human, 5 feet 11 inches tall, 211 lbs.\n"+
         "Novowels is in good shape.\n"+
         "Novowels has a small "+YEL+"gold star"+NORM+" tattoo on his inside right ankle.\n"+
         "Novowels is surrounded by a foreboding aura.\n"+
         "Novowels has a [maltell]. \n"+
         "Novowels has a long tail and whiskers.\n"+
         "He is wearing a pair of black leather pants.\n"+
         "        Novowels is carrying: \n"+
         "Lightsabre (wielded).\n"+
         "Attitude (depressed).\n"+
         "A ball 'o string.\n"+
         "A lump of magical clay.\n");


set_level(28);

set_ac(26);

set_wc(52);

set_hp(1800);

set_al(-10000);			 /*alignment*/

set_aggressive(0);		 /*0 not, 1 is*/

set_chat_chance(1);		 /*chance per heartbeat load_chat messages*/

set_a_chat_chance(5);		 /*combat chance chance*/


load_chat("Novowels scans the area.\n");
load_chat("Novowels looks at the board.\n");
load_chat("Novowels nods solemnly.\n");

load_a_chat("Novowels scans your mind.\n");
load_a_chat("Novowels chuckles as he plots your demise.\n");


Z = random(60);
set_chance(Z);


if(Z>=41) { 

    set_spell_dam(15);
    set_spell_mess1("Novowels catches his attacker in a force choke.\n");
    set_spell_mess2("Novowels chokes you with a gesture.\n");
          }

if(Z>=20 && Z<=40) {

    set_spell_dam(30);
    set_spell_mess1("Novowels lashes out with "+HIB+"DARK LIGHTNING"+NORM+". \n");
    set_spell_mess2("Novowels strikes you down with "+HIB+"DARK LIGHTNING"+NORM+". \n");
                  }

if(Z<20) {

    set_spell_dam(50);
    set_spell_mess1("Novowels "+HIK+ "SLICES"+NORM+" his foe with his lightsaber.\n");
    set_spell_mess2("Novowels "+HIK+ "SLICES"+NORM+" you with his lightsaber.\n");
         }


    }
}

