
inherit "/obj/monster";
#include "/players/zeus/closed/all.h"
int ball;
object lgolem, nmy, *nmys;

reset(arg) {
  ::reset(arg);
  if (!arg) {

  ball = 0;
  set_name("granite golem");
  set_short("A Granite Golem");
  set_race("golem");
  set_gender("creature");
  set_long(
"This is a gigantic granite golem.  Created by magic, its sole purpose\n"+
"is to serve the bidding of its master.  Its two glowing red eyes seem\n"+
"fueled by the fires of Hell.  It is an emotionless tool of destruction.\n");
  set_ac(35);
  set_wc(35);
  set_hp(1200);
  set_ac_bonus(20);
  set_wc_bonus(42);
  set_hp_bonus(400);
  set_level(23);
  set_al(-600);
  set_heal(5,10);
  set_aggressive(0);
  set_chat_chance(4);
  set_a_chat_chance(0);
  load_chat("The golem stands silently.\n");
  load_chat("The golem watches you.\n");
  load_chat("The golem looks at you.\n");
  load_chat("The golems eyes flash with fire.\n");
  load_chat("The golems eyes burn with a passion.\n");
  load_chat("The golem stands waiting.\n");
  set_dead_ob(TO);
  call_out("hunt",20);
  }
}

hunt(){
  string w;
  if(!ENV) return;
  if(!sscanf(file_name(ENV), "players/zeus/museum/arena/%s", w))
  return;
  call_out("hunt", 20);
  if(!nmy) return;
  if(ball) return;
  if(!sscanf(file_name(environment(nmy)),
    "players/zeus/museum/arena/%s", w)) return;
  if(!nmy->query_ghost())
  {
    MO(TO, environment(nmy));
    TO->attack_object(nmy);
    return;
  }
}

monster_died(){
  object corpse;
  corpse = present("corpse", environment());
  if(this_player())
  {
  write_file("/players/zeus/log/museum", ctime(time())+"   "+
  capitalize((string)TP->QRN)+" defeated Granite Golem.\n");
  }
   "/players/zeus/museum/lounge.c"->npc6();
  TR(environment(),
    "The golem explodes into fragments of rock!\n"+
    "An object rests among the rubble.\n");
  if(corpse) MO(CO("/players/zeus/museum/OBJ/gstaff.c"), corpse);
}

unmoo(){
  TR(environment(), "The golem uncurls, ready to fight.\n");
  weapon_class = 35;
  armor_class = 30;
  set_heal(5,10);
  ball = 0;
}

moo(){
  TR(environment(), "The golem curls up into a tight ball.\n");
  armor_class = 100;
  weapon_class = 2;
  set_heal(10,1);
  ball = 1;
  call_out("unmoo", 25);
}

rage(){
  int x;
  TR(environment(), "Bloodlust fills the golem with a demonic RAGE!\n\n");
  for(x = 0; x < (4+random(4)); x ++){
    if(AO->query_ghost() && AO->is_player()) return;
    else {
      already_fight = 0;
      ::attack();
		}
	}
}

damage_function(){
	if(random(6)) return;
    TR(environment(TO),
"\nA chunk of granite becomes detached and falls to the ground...\n"+
"The chunk molds into a mini granite golem!\n\n");
	lgolem = CO("/players/zeus/museum/NPC/tiny_golem.c");
	MO(lgolem, environment());
	lgolem->attack_object(AO);
}


pet_check(){
  object pet, mech, wolf;
  pet = present("pet", environment());
  mech = present("mech", environment());
  wolf = present("wolf", environment());
  if(pet && pet->is_pet()){
    TR(environment(), 
      "The golem reaches down and grabs the pet.\n"+
      "The golem bites the pets head off.\n");
    destruct(pet);
  }
  else if(mech && mech->is_pet()){
    TR(environment(),
      "The golem grabs the mech and crushes it easily.\n");
    destruct(mech);
  }
  else if(wolf && wolf->is_pet()){
    TR(environment(),
      "The golem grabs the wolf by both ends and pulls...\n"+
      "The golem tears the wolf in half.\n");
    destruct(wolf);
  }
}

void heart_beat(){
  ::heart_beat();
  if(!environment()) return ;
  if(hit_point < 200){
    hit_point += 5;
    if(!random(5))
      TR(environment(), "The golem slowly rebuilds itself!\n");
  }
  if(!AO) return;
  nmy = AO;
  if(!random(6))            pet_check();
  if(ball)                  hit_point += 5;
  if(!random(20) && !ball)  moo();
  if(!random(20) && !ball)  rage();
  damage_function();
}

