	/*Oliphant - big primitive ancestor of elephant and mammoth*/

inherit "/obj/monster";
#include "/players/wren/ansi.h"

reset(arg)  {
     ::reset(arg);
     if(!arg)  {

set_name("oliphant");
set_alt_name("oli");
set_alias("mammoth");
set_short("shaggy oliphant");
set_race("oliphant");
set_gender("male");
set_long("Another strange beast brought to perform at the circus. This is a  \n"+
         "very large and very ill tempered creature that evolved parellel to \n"+
	 "the elephant. They came from a cold high-gravity planet. Thick fur \n"+
         "covers an even denser hide. It towers above the keeper and has an  \n"+
         "almost sinister gleem in its dark eyes. A powerful trunk between   \n"+
         "two massive tusks would make this creature dangerous even to an    \n"+
         "armored vehicle. Caution should be exercised when irritating it.   \n");

set_level(23);
set_ac(20+random(4));
set_wc(40+random(4));
set_hp(900+random(300));
set_al(-600);    		 /*alignment*/
/*set_aggressive(0);  */ 	 /*0 not, 1 is*/
set_chat_chance(1);		 /*chance per heartbeat load_chat messages*/
set_a_chat_chance(5);		 /*combat chance chance*/

load_chat("Oliphant snuffles at something in the sawdust.\n");
load_chat("The oliphant eyes a young boys bag of peanuts.\n");

load_a_chat("Oliphant trumpets angrily.\n");
load_a_chat("Oliphant stomps heavily on you.\n");

set_chance(10);
set_spell_dam(30);
set_spell_mess1("You watch in horror as the Oliphant tramples "+attacker_ob+" into the dust. \n");    /*others*/
set_spell_mess2("You watch in horror as the Oliphant tramples "+attacker_ob+" into the dust. \n");    /*attacker*/

set_dead_ob(this_object());
    }
}
heart_beat() {
  ::heart_beat(); /* This calls the heart_beat in monster.c to handle attacks. */
  if(!present("keeper_mob")) {set_aggressive(1); /*else set_aggressive(0);*/}  /*0 not, 1 is*/
             }

monster_died() {
  object corpse,ob;
  corpse = present("corpse", environment());
  say("The oliphant bugles and charges at you, it staggers\n"+
    "though and crashed to the ground at your feet.\n");
  if(corpse)
  {
    corpse->set_long(
      "Corpse of oliphant. The furry behemoth lies dead though \n"+
      "only the dark matted patches of fur reveal any damage was \n"+
      "done. The hide is rough and wouldn't bring a price. But  \n"+
      "you think with as much ivory is in the tusks they could  \n"+
      "be worth retrieving.");
    corpse->set_short("The massive remains of an oliphant");
  
    ob = clone_object("/players/wren/Area/evilcircus/items/tusks.c");
         move_object(ob,this_object());   
   return 1;
   }
}

