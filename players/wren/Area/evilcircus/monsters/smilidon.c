	/*Smiledon - tusked big feline ancestor*/

inherit "/obj/monster";
#include "/players/wren/ansi.h"

reset(arg)  {
     ::reset(arg);
     if(!arg)  {

set_name("smiledon");
set_alt_name("smile");
set_alias("tiger");
set_short("red striped smiledon");
set_race("smiledon");
set_gender("female");

set_long("A feral smiledon, a beast from our own history brought \n"+
	 "back either through sorcery or a world with fauna much \n"+
         "like that of our ancient history. This reddish feline  \n"+
         "watches your every move. Muscles taut under its smooth \n"+
         "fur, it appears ready to pounce at any time...         \n");

set_level(22);
set_ac(21+random(5));
set_wc(40+random(5));
set_hp(700+random(400));
set_al(-400);  			 /*alignment*/
/*set_aggressive(0);*/		 /*0 not, 1 is*/

set_chat_chance(1);		 /*chance per heartbeat load_chat messages*/
set_a_chat_chance(4);		 /*combat chance chance*/

load_chat("Smiledon sniffs the air cautiously.	\n");
load_chat("Smiledon roars mightily.		\n");

load_a_chat("Smiledon gouges deeply with its tusks into your side.  \n");
load_a_chat("You bleed excessively from the ragged claw scratches.  \n");
load_a_chat("Smiledon pounces and thrashes you with its rear claws. \n");

set_chance(10);
set_spell_dam(25+random(10));
set_spell_mess1("Smiledon roars and "+RED+"IMPALES"+NORM+" her opponent on if massive fangs. \n");    /*others*/
set_spell_mess2("Smiledon roars and "+RED+"IMPALES"+NORM+" you on her massive fangs.\n");    /*attacker*/

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
  say("The smiledon roars and leaps at you....\n"+
      " \n"+
      "You side step and it falls to the ground dead.\n");
  if(corpse)
  {
    corpse->set_long(
      "Corpse of smiledon. The striped fur is slick with blood\n"+
      "from many lacerations. The pelt is ruined but the tusks\n"+
      "could be worth redeeming.");
    corpse->set_short("The battered remains of a smiledon");
  
    ob = clone_object("/players/wren/Area/evilcircus/items/ivory.c");
         move_object(ob,this_object());   
   return 1;
   }
}

