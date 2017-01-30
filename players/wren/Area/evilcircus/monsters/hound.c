	/*Hell hounds that guard the entrance*/

inherit "/obj/monster";
#include "/players/wren/ansi.h"

reset(arg)  {
     ::reset(arg);
     if(!arg)  {

set_name("hound");
set_alt_name("dog");
set_alias("hellhound");
set_short("Fiery-red hound");
set_race("hellhound");
set_gender("female");

set_long("Great vicious dogs from one of the infernal dimensions.  \n"+
	 "The firey red color of their coats matches their temperament.\n"+
         "Fire is a part of the hellhounds native environs and it is \n"+
         "both familiar with and capable of using this element.	  \n");

set_level(15);
set_ac(12);
set_wc(20+random(4));
set_hp(250+random(100));
set_al(-200);  			 /*alignment*/
set_aggressive(1);		 /*0 not, 1 is*/
set_chat_chance(1);		 /*chance per heartbeat load_chat messages*/
set_a_chat_chance(10);		 /*combat chance chance*/
set_armor_params("physical", 10, 5, "fire_defense");


load_chat("The hell hound sniffs the air.	\n");
load_chat("Dark flames curl around the hell hound.\n");

load_a_chat("You are scortched by the extreme heat radiating from the hellhound.\n");
load_a_chat("The hell hound sinks it incisors into your leg.	\n");

set_chance(5);
set_spell_dam(10+random(20));
set_spell_mess1("Flames roar up around the hell hound roasting its foe. \n");    /*others*/
set_spell_mess2("Flames roar up, burning your lungs and scortching your garb. \n");    /*attacker*/

    }
}

int 
fire_defense() {

   if(!random(5)) {
         tell_room(environment(),
              RED+"Fires"+NORM+" roar to life around the hounds, forcing you to fall back. \n");
              return 3001; 
            }
}

heart_beat()
{
    object ob;

    if (attacker_ob || random(5))
       return;
    ob = first_inventory(environment(this_object()));
    while(ob) {
       if (ob != this_object() && living(ob) && !call_other(ob, "query_ghost") && ob != "barker")
       {
           attack_object(ob);
           say("Hell hound attacks " + call_other(ob, "query_name", 0) + " viciously.\n");
           return;
       }
       ob = next_inventory(ob);
    }
}
