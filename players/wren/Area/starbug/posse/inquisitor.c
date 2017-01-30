	/*Inquisitor muhahaha*/

#include <ansi.h>
inherit "/obj/monster";

reset(arg)  {
     ::reset(arg);
     if(!arg)  {

object ob;

    ob = clone_object("/players/wren/Area/starbug/items/gauntlet.c");
         move_object(ob,this_object());
         command("wield gauntlet",this_object());

   
set_name("inquisitor");

set_alias("badass");

set_gender(1);

set_race("droid");

set_long("The Inquisitor. This rogue droid is said to have servived to the end of \n"+
	 "time and decided that there is no god or afterlife. He then constructed \n"+
         "his time gauntlet and began going through history removing anyone that  \n"+
         "had lived a useless life and replacing them with another possible form. \n"+	 
         "With the Red Dwarf crew he was kept busy for quite some time. \n");

set_level(18);

set_ac(16);

set_wc(26);

set_hp(425);

set_al(-10);    		 /*alignment*/

set_aggressive(0);		 /*0 not, 1 is*/

set_chat_chance(5);		 /*chance per heartbeat load_chat messages*/

set_a_chat_chance(5);		 /*combat chance chance*/


load_chat("Inquisitor says 'I am the omega. There is nothing else'.\n");
load_chat("Inquisitor sits watching you from his high throne.	   \n");
load_chat("Inquisitor asks 'Will you be found worthy or lacking'.  \n");

load_a_chat("Inquisitor says 'Have you lived a worthy life?'	\n");
load_a_chat("Inquisitor wearing the face of "+attacker_ob+" says 'Justify you existence'.\n");

set_chance(10);

    set_spell_dam(30);
    set_spell_mess1("Inquisitor shakes "+attacker_ob+"around like a rag doll.\n");
    set_spell_mess2("Inquisitor shakes you around roughly.\n");

   }
}
short(){if(attacker_ob) return attacker_ob->short();  else return "Inquisitor"; }
