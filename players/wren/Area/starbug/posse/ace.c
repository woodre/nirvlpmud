	/* Ace Rimmer*/

#include <ansi.h>
inherit "/obj/monster";

reset(arg)  {
     ::reset(arg);
     if(!arg)  {

object ob;
    ob = clone_object("/players/wren/Area/starbug/items/hair.c");
         move_object(ob,this_object());
         command("wear hair", this_object());
   
set_name("ace");
set_alt_name("hero");
set_alias("rimmer");
set_short("Ace Rimmer, Intergalatic Hero");
set_race("hologram");
set_long("This is Ace Rimmer. Galactic, Dimensional, and all around hero.\n"+
	 "His exploits are legendary. He started out as a test pilot in \n"+
         "the Space Corp. His new ship allowed him to cross dimensions as \n"+
         "well as space and he's sought out Rimmers and found none quite so \n"+
         "pathetic as this dimension's.  \n");
set_level(16);
set_ac(13);
set_wc(22);
set_hp(300);
set_al(500);   			 /*alignment*/
set_aggressive(0);		 /*0 not, 1 is*/
set_chat_chance(10);		 /*chance per heartbeat load_chat messages*/
set_a_chat_chance(8);		 /*combat chance chance*/
load_chat("Ace says: 'Smoke me a kipper, I'll be back for breakfast.\n");
load_chat("From somewhere a voice is heard. 'What a guy.'\n");
load_a_chat("Ace says: 'That's not very effective ol chum, you'll do more damage \n"+
            "           if you hit me here instead.		\n");
load_a_chat("Ace flashes his perfect smile.		\n");
    }
}
