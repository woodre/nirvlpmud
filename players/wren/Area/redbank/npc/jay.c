	/*jay of the duo*/

#include <ansi.h>
inherit "/obj/monster";

reset(arg)  {
     ::reset(arg);
     if(!arg)  {

object ob;
    ob = clone_object("/players/wren/Area/redbank/items/bat.c");
         move_object(ob,this_object());
         command("wield bat",this_object());

set_name("jay");
set_alt_name("jay_mob");
set_alias("jay");
set_short("Jay");
set_race("human");
set_gender("male");

set_long("This is Jay. He is an excitable little stoner that has   \n"+
	 "had some very interesting adventures around New Jersey   \n"+
         "His hetero lifemate Silent Bob is always near by.        \n"+
         "Most of his day is spent lingering in front of the       \n"+
         "Quickstop bothering the clerks and selling drugs.	   \n");

set_level(15);
set_ac(14);
set_wc(21);
set_hp(300+random(80));
set_al(200);    	         /*alignment*/
set_aggressive(0);		 /*0 not, 1 is*/
set_chat_chance(5);		 /*chance per heartbeat load_chat messages*/
set_a_chat_chance(20);		 /*combat chance chance*/

load_chat("Jay says: 'Show some love Silent Bob.'\n");
load_chat("Jay says: 'Hey tub-of-guts what're we doing today?'\n");
load_chat("Jay says: 'Dude thats messed up.' \n");
load_chat("Jay says: 'Take some of this and I guarantee you'll see sailboats...' \n");
load_chat("Jay says: 'Time to drink some beers and smoke a bowl...'\n");
load_chat("Jay says: 'Snoogans'\n");

load_a_chat("Jay says: 'Naganootch!' \n");
load_a_chat("Jay says: 'Come on lunchbox, back me up!' \n");
load_a_chat("Jay blows a cloud of smoke in your face. \n");
load_a_chat("Jay yells: 'Come son of Kal'l, kneel before Zod! Snootchie Bootchies EHehHEhehehEHhehE!'\n");

set_chance(8);
set_spell_dam(20);
set_spell_mess1("Jay twirls his bat around expertly and cracks foe in the back of the head. \n");    /*others*/
set_spell_mess2("Jay cracks you across the back of the head with his bat. \n");    /*attacker*/
    }
}

