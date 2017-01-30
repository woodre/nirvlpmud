/* Intended for use in Zeus' Museum Arena */
inherit "/obj/monster";
#include "/players/zeus/closed/all.h"
#define OQN AO->QN
object nmy;
string place;
int x;

reset(arg) {
   ::reset(arg);
   if (!arg) {

	x = 1;
	set_name("mini golem");
	set_alt_name("mini_golem");
	set_short("A mini granite golem");
	set_race("golem");
	set_gender("creature");
	set_long(
"This is a tiny version of the granite golem.  It is only about a foot\n"+
"and a half tall, however it still looks incredibly strong.  Its eyes\n"+
"are burning with a powerful red glow, making it look like an incredibly\n"+
"evil creature.  It lacks any expression at all on its face.\n");
	set_ac(7);
	set_wc(30);
	set_hp(30);
  set_heal(30,1);
	set_level(5);
	set_al(-600);
	set_aggressive(1);
	set_chat_chance(4);
	set_a_chat_chance(0);
	load_chat("The golem watches you.\n");
	load_chat("The golems eyes burn.\n");
	load_chat("The golems eyes flare up.\n");
	load_chat("The golem stands silently.\n");
  call_out("getnmy", 10);
   }
}

getnmy(){
  object abc;
  if(nmy) return;
  if(abc = find_living("zeus magic granite golem"))
  {
    if(sscanf(file_name(environment(abc)),
      "players/zeus/museum/arena/%s", place))
    {
      if(nmy = abc->query_nmy())
        tell_room(environment(), RED+"The golem's eyes flash red.\n"+NORM);
    }
  }
}
     

attack_function(){
	int random_attack;
  if(!attacker_ob) return;
	if(!present(attacker_ob, environment())) return;
	random_attack = random(4);
	switch(random_attack){
	case 0:
			TR(environment(),
"The golem punches "+OQN+" incredibly hard!\n", ({AO}));
			tell_object(AO,
"The golem punches you incredibly hard!\n");
			if(AO->query_hp() >= 10)
			AO->add_hit_point(-10);
			break;
	case 1:
		TR(environment(),
"The golem grabs onto "+OQN+"'s leg and squeezes it...\n", ({AO}));
		tell_object(AO,
"The golem grabs onto your leg and squeezes it...\n");
		if(AO->query_hp() >= 8)
		AO->add_hit_point(-8);
		break;
	case 2:
		TR(environment(),
			"The golem slams its fists into "+OQN+"!\n", ({AO}));
		tell_object(AO,
			"The golem slams its fists into you!\n");
		if(AO->query_hp() >= 7)
		AO->add_hit_point(-7);
		break;
	case 3:
		TR(environment(),
			"The golem walks towards "+OQN+"...\n", ({AO}));
		tell_object(AO,
			"The golem walks towards you...\n");
		break;
	}
	return 1;
}

boom(){
	if(sscanf(file_name(environment(nmy)), 
		"players/zeus/museum/arena/%s", place) &&
		!nmy->query_ghost()){
	MO(TO, environment(nmy));
	TR(environment(), "A golem walks into the room.\n");
	attack_object(nmy);
	}
	x = 1;
}

blah(){
	if(sscanf(file_name(environment()), 
		"players/zeus/museum/arena/%s", place)){
		if(x && nmy && !present(nmy, environment()) &&
			!nmy->query_ghost()){
			if(sscanf(file_name(environment(nmy)),
				"players/zeus/museum/arena/%s", place)){
				call_out("boom", 1+random(5));
				x = 0;
			}
		}
	}
	else {
		TR(environment(), "The golem crumbles to pieces.\n");
		destruct(TO);
	}
}

go(){
	if(present(nmy, environment()))	attack_object(nmy);
}

void heart_beat(){
  ::heart_beat();
  if(!environment()) return;
  blah();
  if(nmy && !random(10) && !nmy->query_ghost())
    go();
  if(!attacker_ob) return;
  nmy = attacker_ob;
  if(!random(11)) 
    attack_function();
}
