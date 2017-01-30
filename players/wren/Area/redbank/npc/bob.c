	/*silent bob*/

#include <ansi.h>
inherit "/obj/monster";

reset(arg)  {
     ::reset(arg);
     if(!arg)  {

object ob;
    ob = clone_object("/players/wren/Area/redbank/items/golfclub.c");
         move_object(ob,this_object());
         command("wield club",this_object());

set_name("bob");
set_alt_name("bob_mob");
set_alias("silent bob");
set_short("Silent Bob");
set_race("human");
set_gender("male");
set_long("Silent Bob the compatriat of Jay and brains of the duo. He \n"+
	 "very seldom speaks but when he does it is often profound   \n"+
         "and useful advice. His black trenchcoat is rumored to have \n"+	 
         "extra-dimensional capabilities for from it have been pulled \n"+
         "many an item that has saved these two from the perils of the \n"+
         "mall and its evil security team. \n");

set_level(15);
set_ac(14);
set_wc(21);
set_hp(300+random(80));
set_al(200);    			 /*alignment*/
set_aggressive(0);		 /*0 not, 1 is*/
set_chat_chance(2);		 /*chance per heartbeat load_chat messages*/
set_a_chat_chance(15);		 /*combat chance chance*/

load_chat("Silent Bob takes a long draw on his cigarette. \n");
load_chat("Silent Bob nods at Jay.		\n");
load_chat("Silent Bob looks around.\n");
load_chat("Silent Bob looks skeptically at Jay\n");

load_a_chat("Silent Bob tries to use Jedi Force powers on you.	\n");
load_a_chat("Silent Bob swings at you with a sock full of quarters.	\n");
load_a_chat("Silent Bob says: 'Do or do not, there is no try.' \n");

set_chance(15);
set_spell_dam(30+random(20));
set_spell_mess1("Silent Bob pulls a golf driver from his coat and cracks his opponent hard in the chest. \n");    /*others*/
set_spell_mess2("Silent Bob pulls a golf driver from his coat and cracks you painfully in the chest. \n");    /*attacker*/
    }
}

