	/* Rimmer */

#include <ansi.h>
inherit "/obj/monster";

reset(arg)  {
     ::reset(arg);
     if(!arg)  {

object ob,ob2,ob3;

    ob = clone_object("/players/wren/Area/starbug/items/lightbee.c");
         move_object(ob,this_object());
    ob2 = clone_object("/players/wren/Area/starbug/items/arrogance.c");
         move_object(ob2,this_object());
         command("wield arrogance",this_object());
    ob3 = clone_object("/players/wren/Area/starbug/items/charisma.c");
         move_object(ob3,this_object());
         command("wear charisma",this_object());

set_name("rimmer");
set_alias("arnold");
set_short("Arnold Rimmer");
set_race("hologram");
set_long("Second Technician - Arnold Judas Rimmer. Holly notes that he's probably\n"+
         "got more teeth than braincells. He was revived as a hologram to help\n"+
         "keep Dave sane. Holly was clearly already senile by then. He is very\n"+
         "proud of his swiming certificates and wishes very much to be an officer.\n"+
         "Unfortunately he lacks natural aptitude and hasn't found a method of \n"+
         "cheating that works. He still works and argues with the vending machines.\n"+
         "Ironically on the day Lister went into stasis he was trying to explain \n"+
	 "to the captain why he hadn't fixed the drive plate which leaked and \n"+
	 "killed the crew.\n");

set_level(17);
set_ac(15);
set_wc(24);
set_hp(350);
set_al(500);    		 /*alignment*/
set_aggressive(0);		 /*0 not, 1 is*/
set_chat_chance(5);		 /*chance per heartbeat load_chat messages*/
set_a_chat_chance(5);		 /*combat chance chance*/
load_chat("Rimmer's nostrils flare threateningly.	\n");
load_chat("Rimmer says: 'I refer you to Space corp directive 258.432 stroke 9.'	\n");
load_chat("Rimmer begins his salute, his hand starts swirling in front of him... \n");
load_chat("Rimmer says: 'Oh hah hah'. \n");
load_chat("Rimmer finishes his salute and his hand flutters slowly back to his side.\n");
load_chat("Rimmer says: 'I'll go up the ziggerat lickity split'.\n");
load_a_chat("Rimmer yells: 'You're on report.\n");
load_a_chat("Rimmer tries to run from you. \n");
load_a_chat("Rimmer says: 'How do you like that m'lado?'  \n");
load_a_chat("Rimmer says: 'We surrender, 100% totally, and unconditionally.\n");

    }
}

