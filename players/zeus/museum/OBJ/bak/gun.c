/*********************************************************************/ 
/*  Heavy, non-storable wep w/ limited charges and no way to recharge.
/*  Can do damage to wielder. Does much less dmg if sta and str are
/*  not at 20.  Lasts about 175 rounds.   Assuming sta + str = 40:
/*  VS ac 0 npc:   average dmg: 18.76
/*  VS ac 8 npc:   average dmg: 15.33
/*  VS ac 17 npc:  average dmg: 11.24
/*                 Damage: 1729  Rounds: 191  Average: 9.52
/*                 Damage: 2068  Rounds: 173  Average: 11.953
/*********************************************************************/

inherit "/obj/weapon.c";
#include "/players/zeus/closed/all.h"
#define TQN  target->query_name()
#define HM tell_object(environment()
#define MH tell_room(environment(environment())
int charges,x,y,z,c;

reset(arg) {
   ::reset(arg);
   if (arg) return;

  charges = 1000;
  set_name("chaingun");
  set_alias("gun");
  set_type("gun");
  set_short("HyperPulse Chaingun");
  set_weight(6);
  set_value(5932);
  set_class(2);
  set_hit_func(this_object());
  message_hit=({
    "unload a wave of laser fire ripping into","",
    "blasted"," with a wave of laser fire",
    "tore into"," with a barrage of energy blasts",
    "cut into"," with many blasts of energy",
    "struck"," with a precise blast",
    "nailed"," with numerous energy blasts",
    "grazed"," with energy blasts",
  });
}

long(){
	write(
"This is a HyperPulse Chaingun, model number ZW669.  It is a massive\n"+
"weapon, with a large circular barrel and body.  On the left side there\n"+
"is a small red LED display showing the amount of energy remaining.\n");
}

query_save_flag(){    return 1; }
two_handed(){         return 1; }

void init(){ ::init(); add_action("read_cmd", "read"); }
read_cmd(str){
	if(!str) return 0;
	if(str == "display"){ if(charges < 0) charges = 0; write(
"The display shows there is "+HIR+charges+NORM+" energy remaining.\n");
	return 1; } }

int weapon_hit(object target){
   z = (int)environment()->query_attrib("sta");
   c = (int)environment()->query_attrib("str");
   y = (z + c) / 10;
   if(y > 4) y = 4;
   x = random(11);
   set_hits(0);
   set_misses(0);
   if(!random((y*4)+2)){  /*  1:18 backfire [max stats]  */
	HM, "The gun kicks back, jamming your hand!\n");
	ENV->hit_player(15);
	return 0;
   }
   else if(charges <= 0){
	HM, "You pull the trigger and the barrel spins...\n"+
		"The chaingun is out of energy.\n");
      value = 1;
	  charges = 0;
	   return 0;
   }
   else if(x <= 1+random(2)){  /*  22% chance of missfire */
	   HM, "You fire but your blasts go astray.\n");
	   MH, ENV->QN+"'s blasts go astray.\n", ({ENV}));
	   x = 0;
	   charges -= 3 + random(3);
   }
   else if(x <= 5){
	HM, "You fire numerous blasts of energy at "+TQN+".\n");
	MH, ENV->QN+" fires numerous blasts of energy at "+TQN+".\n",
		   ({ENV}));
   }
   else if(x <= 7){
	HM, "The barrel spins as blasts of energy tear into "+TQN+".\n");
	MH, ENV->QN+" fires blasts of energy tearing into "+TQN+".\n",
		   ({ENV}));
   }
   else if(x < 10){
	HM, "You unload a torrent of energy blasts into "+TQN+".\n");
	MH, ENV->QN+" unloads a torrent of energy blasts into "+TQN+".\n",
		   ({ENV}));
   }
   else {
	HM, "As you fire the chaingun you are knocked back...\n"+
	   "You unload energy blasts into "+TQN+" causing massive damage!\n");
	MH, ENV->QN+" unloads energy blasts into "+TQN+".\n",
		   ({ENV}));
	   x += random(5);
   }
   charges -= x;
   if(target->query_hp() > ((x*y)/2+2))
	  target->hit_player((x*y)/2+2);
   else target->hit_player(target->query_hp());
   return (x*y);
}

