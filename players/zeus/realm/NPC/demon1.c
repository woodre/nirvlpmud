/*
/*-------------3 levels of demons------------------
Level	Hp	WC	AC	value	~exp
| 13   |  144   |   30    |    6   |      0     |  834
| 14   |  162   |   31    |    7   |      0     |  1400
| 15   |  180   |   32    |    8   |      0     |  1850
-------------------recommended----------------------
| 13   |  195   |   17    |   10   |    700     |
| 14   |  210   |   18    |   11   |    850     |
| 15   |  225   |   20    |   12   |    875     |
PLUS:	bonus initial damage 5+random(20)
*/

inherit "/obj/monster";
#include "/players/zeus/closed/all.h"
#define TIME 120+random(120)
int special;

reset(arg) {

int number;
 number = 8+random(3);

   ::reset(arg);
   if (!arg) {

  special = 1;		 /* starting bonus damage */
  set_name("a cursed demon");
  set_short("A cursed demon");
  set_race("demon");
  set_long(
"This is a small red demon.  It has a tough little body with gangly arms.\n"+
"It is hunched over, but looks only to be about two feet tall.  A constant\n"+
"grin adorns it's face, which is highlighted by it's burning eyes.  It's\n"+
"claws are razor sharp and caked with dry blood.  It is forever cursed\n"+
"to hunt the weak who would dare venture into the Fallen Lands.\n");
  set_level(number + 5);
  set_ac(number - 2);
  set_wc(number + 22);
  set_hp(number * 18);
  set_gender("creature");
  set_aggressive(1);
  set_al(-666);
  set_chat_chance(3);
  set_a_chat_chance(1);
  load_chat("The demon glares at you.\n");
  load_chat("The demon's eyes burn.\n");
  load_chat("The demon grins.\n");
  load_chat("The demon examines you.\n");
  load_a_chat("The demons eyes glaze over in bloodlust.\n");
  set_dead_ob(TO);
  call_out("destruct_demon", TIME);
}  }

id(str){ return str == "demon" || str == "daemon" || str == "cursed demon"
|| str == "a cursed demon"; }


monster_died(){
  object corpse;
  corpse = present("corpse", environment());
  say("The cursed demon bursts into flames!\n"+
    "Its charred body falls to the ground.\n");
  remove_call_out("destruct_demon");
  if(corpse)
  {
    corpse->set_long(
      "This is the charred remains of a cursed demon.  Its skin is mostly\n"+
      "black, spattered with blood.  Pieces of bone are protruding from\n"+
      "its flesh in numerous places.  A very pungent odor of rot and decay\n"+
      "surrounds the twisted corpse.");
    corpse->set_short("The charred remains of a cursed demon");
  }
  DD->add_kills(AO, 1);
}

destruct_demon(){
   if(!environment()) return 1;
   TR(environment(),
		"The cursed demon bursts into flames and is gone!\n");
   destruct(TO);
   return 1; 
}

attack_special(){
  if(!AO) return 0;
  if(!present(AO, environment())) return 0;
  tell_object(AO,  "The cursed demon slashes you with its claws!\n");
  TR(environment(), 
	  "The cursed demons eyes glaze over in bloodlust.\n", ({AO}));
  AO->hit_player(5+random(20));
}

heart_beat(){
  ::heart_beat();
  if(!environment()) 
    return ;
  if(!AO) 
    return ;
  if(special)
  {  
    attack_special(); 
    special = 0; 
  }
  else if(!random(12))
    attack_special();  
}
