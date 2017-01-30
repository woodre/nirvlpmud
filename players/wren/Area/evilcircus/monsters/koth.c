	/*Koth the Ghoul Mime - man have I ever mentioned how much I*/
        /*                      really dislike mimes, gah, so damn  */
        /*                      creepy they are. Smack them around. */

inherit "/obj/monster";
#include "/players/wren/ansi.h"

reset(arg)  {
     ::reset(arg);
     if(!arg)  {

object ob;
    ob = clone_object("/players/wren/Area/evilcircus/items/pouch.c");
         move_object(ob,this_object());

set_name("mime");
set_alias("clown");
set_alt_name("koth");
set_race("ghoul");
set_long("A mime painted out in white and black. This lithe preformer is \n"+
	 "working his way through the traditional mime routine. 'Walking \n"+ 
         "into the wind', 'Pulling on a rope', and 'trapped in a box'.   \n"+
         "Something about this preformer is really creapy though and you \n"+
         "feel a strong desire to eliminate him.	  \n");

set_level(20);
set_ac(19);
set_wc(32+random(4));
set_hp(500+random(200));
set_al(-1000);    		 /*alignment*/
set_aggressive(1);		 /*0 not, 1 is*/

set_chat_chance(2);		 /*chance per heartbeat load_chat messages*/
set_a_chat_chance(6);		 /*combat chance chance*/

load_chat("Mime strains against an invisible rope and seems to loose ground.\n");
load_chat("Koth traces the outline of the box its in.		\n");
load_chat("Mime leans on something that isn't there. \n");
load_chat("Mime smiles biggly and tries to walk against what appears to be a hurricane gale.\n");

load_a_chat("Mime wraps around you scratching and biting with whicked dexterity.\n");
load_a_chat("You suddenly feel confined, as though a force is restricting you to a box.	\n");
load_a_chat("Slime drips from the jagged teeth of the ghoulish mime.  \n");
load_a_chat("Mime shoves you away with some unseen force. \n");
load_a_chat("Koth tilts his head to the side and cartwheels around the ring.\n");

set_chance(10);
set_spell_dam(10+random(30));
set_spell_mess1("Mime bends reality and telekinetically flattens foe with a gesture.\n");    /*others*/
set_spell_mess2("Koth flicks his hand and you are pounded by telekinetics into the ground.\n");    /*attacker*/

    }
}

short(){if(attacker_ob) return "Ghoulish Mime";  else return "A performing mime"; }
