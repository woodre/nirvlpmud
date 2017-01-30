	/*randall*/

#include <ansi.h>
inherit "/obj/monster";

reset(arg)  {
     ::reset(arg);
     if(!arg)  {
/*
object ob,ob2,ob3;
    ob = clone_object("/players/wren/Area/   .c");
         move_object(ob,this_object());
    ob2 = clone_object("/players/wren/Area/   .c");
         move_object(ob2,this_object());
    ob3 = clone_object("/players/wren/Area/    .c");
         move_object(ob3,this_object());
*/
set_name("randall");
set_alt_name("randall_npc");
set_alias("graves");
set_short("Randall Graves");
set_race("human");
set_gender("male");
set_long("Randall Graves is another of the clerks that works for RST Video   \n"+
         "and the Quickstop. He has been friends with Dante for a long time  \n"+
         "and they give each other a fair amount of grief. He is supposed to \n"+
         "be watching  the video store today but decided he would rather     \n"+
         "lock up and come bother Dante instead. He's leaning on the counter \n"+
         "reading the tabloids and messing with customers little minds.      \n");
set_level(18);
set_ac(16);
set_wc(28);
set_hp(400+random(100));
set_al(400);   			 /*alignment*/
set_aggressive(0);		 /*0 not, 1 is*/
set_chat_chance(5);		 /*chance per heartbeat load_chat messages*/
set_a_chat_chance(15);		 /*combat chance chance*/

load_chat("Randall says: 'This job would be much better if you could just rip into the occasional customer.'\n");
load_chat("Randall says: 'Lighten up Dante.'		\n");
load_chat("Randall says: 'Thirty-seven?' \n");
load_chat("Randall says: 'What are you looking at Grizzly Adams?' \n");
load_chat("Randall says: 'I hate people, but I love gatherings, isn't it ironic...' \n");

load_a_chat("Randall says: 'Try not so suck any dicks on the way out.'	\n");
load_a_chat("Randall throws snack foods at you.		\n");

set_chance(15);
set_spell_dam(20+random(30));
set_spell_mess1("Randall makes you watch 'Hemaphrodite Bondage' making you vomit painfully. \n");    /*others*/
set_spell_mess2("Randall inflicts the porn film 'Hemaphrodite Bondage' causing massive psychological trama. \n");    /*attacker*/
    }
}

