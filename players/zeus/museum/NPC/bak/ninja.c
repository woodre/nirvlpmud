/*  2 attacks per hb, can do 10-54 damage w/ 2nd attack  */

inherit "/obj/monster";
#include "/players/zeus/closed/all.h"
#define OQN AO->QN
#define OQP AO->POS
#define OQJ AO->OBJ

int attack_value, attack_message, last_message;

reset(arg) {
   ::reset(arg);
   if (!arg) {

  MO(CO("/players/zeus/museum/OBJ/gem.c"), TO);

  set_name("tolbrehn");
  set_alias("ninja");
  set_short("Tolbrehn the Shadowninja Master");
  set_race("human");
  set_gender("male");
  set_long(
"Tolbrehn is the master of the Shadowninja clan.  He is wearing a black\n"+
"and gray ninja suit.  His black face is painted with white and gray\n"+
"stripes that look permanent.  On his hands he wears two black gloves.\n");
  set_ac(20);
  set_wc(60);
  set_wc_bonus(35);
  set_hp(1000);
  set_hp_bonus(40);
  set_heal(6,2);
  set_level(21);
  set_al(0);
  set_aggressive(0);
  set_chat_chance(2);
  set_a_chat_chance(1);
  load_chat("Tolbrehn stands patiently.\n");
  load_chat("Tolbrehn meditates quietly.\n");
  load_chat("Tolbrehn watches you.\n");
  load_chat("Tolbrehn studies your movements.\n");
  load_chat("Tolbrehn cracks his knuckles.\n");
  load_a_chat("Tolbrehn dodges to the side.\n");
  set_dead_ob(TO);
   }
}

monster_died(){
  write_file("/players/zeus/log/museum", ctime(time())+"   "+
	  capitalize((string)TP->QRN)+" defeated Tolbrehn.\n");
   "/players/zeus/museum/lounge.c"->npc2();
}

atk(){
	if(!present(AO, environment())) return;
	attack_value = random(53);
	attack_message = 0;
	if(attack_value < 16){
		attack_value = 0;
		TR(environment(), "Tolbrehn missed "+OQN+".\n");
	}
	else if(attack_value >= 16 && attack_value < 26){
		attack_value = 10+random(5);
		attack_message = random(4);
		while(attack_message == last_message)
			attack_message = random(4);
		last_message = attack_message;
		switch(attack_message){
			case 0:
			TR(environment(),
				"Tolbrehn hits "+OQN+" in the face.\n", ({AO}));
			tell_object(AO,
				"Tolbrehn hits you in the face.\n");
			break;
		case 1:
			TR(environment(),
				"Tolbrehn kicks "+OQN+" in the stomach.\n", ({AO}));
			tell_object(AO,
				"Tolbrehn kicks you in the stomach.\n");
			break;
		case 2:
			TR(environment(),
				"Tolbrehn punches "+OQN+" in the chest.\n", ({AO}));
			tell_object(AO,
				"Tolbrehn punches you in the chest.\n");
			break;
		case 3:
			TR(environment(),
				"Tolbrehn sweep kicks "+OQN+".\n", ({AO}));
			tell_object(AO,
				"Tolbrehn sweep kicks you.\n");
			break;
		}
		AO->hit_player(attack_value);
	}
	else if(attack_value >= 26 && attack_value < 38){
		attack_value = 20+random(5);
		attack_message = random(5);
		while(attack_message == last_message)
			attack_message = random(5);
		last_message = attack_message;
		switch(attack_message){
		case 0:
			TR(environment(),
"Tolbrehn charges at "+OQN+", knocking "+OQJ+" over.\n",
					({AO}));
			tell_object(AO,
					"Tolbrehn charges at you, knocking you over.\n");
			break;
		case 1:
			TR(environment(),
				"Tolbrehn pummels "+OQN+" with his fists.\n", 
					({AO}));
			tell_object(AO,
				"Tolbrehn pummels you with his fists.\n");
			break;
		case 2:
			TR(environment(),
				"Tolbrehn spin kicks "+OQN+" in the head.\n", ({AO}));
			tell_object(AO,
				"Tolbrehn spin kicks you in the head.\n");
			break;
		case 3:
			TR(environment(),
"Tolbrehn dodges to the left and punches "+OQN+" in "+OQP+" side.\n",
					({AO}));
			tell_object(AO,
"Tolbrehn dodges to the left and punches you in your side.\n");
			break;
		case 4:
			TR(environment(),
"Tolbrehn dodges to the right and punches "+OQN+" in "+OQP+" side.\n",
					({AO}));
			tell_object(AO,
"Tolbrehn dodges to the right and punches you in your side.\n");
			break;
		}
	}
	else if(attack_value >= 38 && attack_value < 45){
		attack_value = 30+random(5);
		attack_message = random(4);
		while(attack_message == last_message)
				attack_message = random(4);
		last_message = attack_message;
		switch(attack_message){
		case 0:
			TR(environment(),
"Tolbrehn grabs "+OQN+"'s fist and crushes it.\n", ({AO}));
			tell_object(AO,
				"Tolbrehn grabs your fist and crushes it.\n");
			break;
		case 1:
			TR(environment(),
"Tolbrehn punches "+OQN+" in the neck, causing "+OQJ+" to stagger back.\n",
         ({AO}));
			tell_object(AO,
"Tolbrehn punches you in the neck, causing you to stagger back.\n");
			break;
		case 2:
			TR(environment(),
"Tolbrehn leaps into the air and spin kicks "+OQN+" in the head.\n",
				({AO}));
			tell_object(AO,
"Tolbrehn leaps into the air and spin kicks you in the head.\n");
			break;
		case 3:
			TR(environment(),
			"Tolbrehn kicks "+OQN+"s knee, making it pop loudly.\n",
				({AO}));
			tell_object(AO,
				"Tolbrehn kicks your knee, making it pop loudly.\n");
			break;
		}
	}
	else if(attack_value >= 45 && attack_value < 51){
		attack_value = 40+random(5);
		attack_message = random(4);
		while(attack_message == last_message)
			attack_message = random(4);
		last_message = attack_message;
		switch(attack_message){
		case 0:
			TR(environment(),
"Tolbrehn pinches "+OQN+"'s shoulder, causing "+OQJ+" to collapse in pain.\n",
			({AO}));
			tell_object(AO,
"Tolbrehn pinches your shoulder, causing you to collapse in pain.\n");
			break;
		case 1:
			TR(environment(),
"Tolbrehn grabs "+OQN+" by the neck and lifts "+OQJ+" into the air...\n"+
OQN+" struggles helplessly, gasping for air.\n",  ({AO}));
			tell_object(AO,
"Tolbrehn grabs you by the neck and lifts you into the air...\n"+
"You struggle helplessly, gasping for air.\n");
			break;
		case 2:
			TR(environment(),
"Tolbrehn leaps into the air...  landing on "+OQN+" with a precise kick...\n"+
OQN+" is sent sprawling as Tolbrehn lands above "+OQJ+".\n",  ({AO}));
			tell_object(AO,
"Tolbrehn leaps into the air...  landing on you with a precise kick...\n"+
"You are sent sprawling as Tolbrehn lands above you.\n");
			break;
		case 3:
			TR(environment(),
"Tolbrehn grabs "+OQN+"'s arm and twists it back violently.\n",  ({AO}));
			tell_object(AO,
"Tolbrehn grabs your arm and twists it back violently.\n");
			break;
		}
	}
	else if(attack_value >= 51){
		if(present("shadow_dragon_spell", AO)){
			TR(environment(),
			"Tolbrehn bows his head and focuses his strength.\n");
			hit_point += 25+random(35);
			return;
		}
		TR(environment(),
"\n"+
"The image of a giant gray dragon rises from Tolbrehn...\n"+
"Shadowy flames rise from him as he descends upon "+OQN+"...\n"+
"Tolbrehn engulfs "+OQN+" in a blast of shadowy flames!\n"+
"\n");
		hit_point += 90;
		if(AO->query_level() < 21)
		MO(CO("/players/zeus/museum/OBJ/shadow_dragon_spell.c"), AO);
	}
  attack_value += 10;  /* mo damage -zeus */
	AO->hit_player(attack_value);
}

heart_beat(){
  ::heart_beat();
  if(!environment()) 
    return ;
  if(!AO)
  {
    if(hit_point < max_hp)
    {
      if(!random(4))
      {
        TR(environment(), "Tolbrehn bows his head and seems at peace...\n");
      }
      hit_point += 5;
    }
    return ;
  }

  atk();

}
