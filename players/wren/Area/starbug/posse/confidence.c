	/* Confidence */

#include <ansi.h>
inherit "/obj/monster";

reset(arg)  {
   ::reset(arg);
   if(!arg)  {

set_name("confidence");
set_short("Confidence struts his stuff");
set_race("illusion");
set_long("A strange being that appeared after Lister caught a mutated flu strain.\n"+
	 "This guy oozes confidence. He looks much like a used car salesman in \n"+
         "his aweful plaid leisure suit. He looks at you and clicks his tongue. \n"+
         "He's checking you out like he's got a plan to sell you something you don't \n"+
         "want or need. Better watch your wallet.\n");

set_level(14);
set_ac(11);
set_wc(18);
set_hp(220);
set_al(500);   			 /*alignment*/
set_aggressive(0);		 /*0 not, 1 is*/
set_chat_chance(5);		 /*chance per heartbeat load_chat messages*/
set_a_chat_chance(10);		 /*combat chance chance*/
load_chat("Confidence says: 'Another bright idea from the mind that brought you Beeeerr Milkshakes'.\n");
load_chat("Confidence says: 'Oxygen, you don't need that thats just a myth they\n"+
          "              tell whimps...here let me help you get that helmet off'.\n");
load_chat("Confidence flashes his most winning smile. You try not to laugh.\n");
load_a_chat("Confidence says: 'Where would you be without me?'		\n");
load_a_chat("Confidence says: 'Paranoia, oh I fed him into the garbage disposal. You don't need him. \n"+
            "                       He just wants to hold you back.\n");
load_a_chat("Confidence kicks you viciously in the groin.\n");

    }
}

