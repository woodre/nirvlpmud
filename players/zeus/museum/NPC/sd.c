/*  The Smasher/Devourer  - intended for use in Zeus' museum arena 
*/
/*
go       1:8    16
special  1:9    14
healing  < 100  25
*/
/*
// 2005.08.20 -Forbin
// Changes:
//  AC 35 -> 50
//  WC 55 -> 75
//  HP 1000 -> 1500
//  set_heal 1,1 -> 3,1
*/
inherit "/obj/monster";
#include "/players/zeus/closed/all.h"
#define OQN AO->QN
#define OQP AO->POS
#define OQJ AO->OBJ
object nmy;
string place;

reset(arg) {
   ::reset(arg);
   if (!arg) {

  set_name("Smasher/Devourer");
  set_short("A Smasher/Devourer module");
  set_alt_name("module");
  set_alias("machine");
  set_gender("creature");
  set_race("machine");
  set_long(
"This is a Smasher/Devourer module.  It was created by Humans to be one\n"+
"of the deadliest machines ever built.  A bi-pedal design with an\n"+
"egg-shaped, armored mainframe.  What appear to be arms are actually\n"+
"weaponry for protection.  This machine was built for one purpose,\n"+
"and one purpose alone.\n");
  set_level(22);
  set_hp(1950);
  set_hp_bonus(25);
  set_ac(65);
  set_heal(3,1);
  set_wc(98);
  set_wc_bonus(30);
  set_al(-200);
  set_aggressive(0);
  set_chat_chance(5);
  set_a_chat_chance(1);
  load_chat("The Smasher/Devourer says:  Fear me not but fear my hell.\n");
  load_chat("The Smasher/Devourer says:  Man made me so I could kill.\n");
  load_chat("The Smasher/Devourer says:  Praise me in the name of war.\n");
  load_chat("The Smasher/Devourer says:  I destroy both rich and poor.\n");
  load_chat(
	  "The Smasher/Devourer says:  I am the way, prepare for salvation.\n");
  load_chat("The Smasher/Devourer says:  Strength in time of suffering.\n");
  load_chat("The Smasher/Devourer says:  Man alone is a weakling.\n");
  load_chat("The Smasher/Devourer says:  Ascension is what you ask.\n");
  load_chat("The Smasher/Devourer says:  I will be the fall of man.\n");
  load_a_chat(
	  "The Smasher/Devourer says:  I am the way, prepare for salvation.\n");
  set_dead_ob(TO);
  call_out("blah", 45);
   }
}

query_z_museum_mob() { return 1; }

monster_died(){
	object corpse;
  string killer_name;
  /* Added to prevent bugs with query_real_name  - illarion 8.16.2009 */
  if(this_player())
  {
    killer_name = this_player()->query_real_name();
    if(!killer_name) killer_name = this_player()->query_name();
  }
  if(!killer_name)
    killer_name="unknown";
  
  write_file("/players/zeus/log/museum", ctime(time())+"   "+
	  capitalize(killer_name)+" defeated Smasher/Devourer.\n");
	MO(CO("/players/zeus/museum/OBJ/gun.c"), environment());
	TR(environment(),
"The Smasher/Devourer explodes in a mass of machinery as it is defeated.\n"+
"A strange object is left lying on the ground.\n");
	corpse = present("corpse", environment());
   "/players/zeus/museum/lounge.c"->npc5();
	if(corpse)  destruct(corpse);
  emit_channel("junk","\n(junk) "+HIY+"["+HIW+"Museum Arena"+HIY+"]"+NORM+" "+
    capitalize(killer_name)+
    " has defeated Smasher/Devourer module.\n\n"+NORM); 	
}

attack_special(){
	int random_attack;
	if(!present(AO, environment())) return 0;  
	random_attack = random(4);
	switch(random_attack){
	case 0:
			TR(environment(),
"The Smasher/Devourer fires its guns at "+OQN+".\n", ({AO}));
			tell_object(AO,
"The Smasher/Devourer fires its guns at you.\n");
			AO->hit_player(25+random(50));
			break;
	case 1:
			TR(environment(),
"The Smasher/Devourer fires missiles at "+OQN+".\n", ({AO}));
			tell_object(AO,
"The Smasher/Devourer fires missiles at you.\n");
			AO->hit_player(25+random(50));
			break;
	case 2:
			TR(environment(),
"The Smasher/Devourer fires a blast of solar energy at "+OQN+".\n", ({AO}));
			tell_object(AO,
"The Smaser/Devourer fires a blast of solar energy at you.\n");
			AO->hit_player(25+random(50));
			break;
	case 3:
			TR(environment(),
"The Smasher/Devourer fires a huge beam of...\n\n\n"+
HIY+"       =----   =   -- ------- --  =   ----=\n"+
"\tS O L A R    E N E R G Y\n"+
"       =----   =   -- ------- --  =   ----=\n\n\n"+NORM+
"...into "+OQN+"...  "+OQN+" crumples in agony...\n", ({AO}));
			tell_object(AO,
"The Smasher/Devourer fires a huge beam of...\n\n\n"+
HIY+"       =----   =   -- ------- --  =   ----=\n"+
"\tS O L A R    E N E R G Y\n"+
"       =----   =   -- ------- --  =   ----=\n\n\n"+NORM+
"... into you ...  You crumple in agony...\n");
			AO->heal_self(-50-random(75));
			break;
	}
	return 1;
}

go(){
	if((int)AO->query_hp() > 240){
		TR(environment(),
"The Smasher/Devourer fires a series of missiles at "+OQN+"!\n", 
			({AO}));
		tell_object(AO,
"The Smasher/Devourer fires a series of missiles at you!\n"+
"Huge explosions erupt all around you!\n");
		AO->hit_player(140+random(30));
	}
}

blah(){
  if(!environment(this_object())) return;
  if(sscanf(file_name(environment()), 
    "players/zeus/museum/arena/%s", place))
  {
    if(nmy && environment(nmy) != environment() &&
      sscanf(file_name(environment(nmy)), 
      "players/zeus/museum/arena/%s", place))
    {
      MO(TO, environment(nmy));
      TR(environment(), "The Smasher/Devourer arrives.\n");
      attack_object(nmy);
      attack_special();
    }
    else
      call_out("blah", 45);
  }
}

heart_beat(){
  ::heart_beat();
  if(!environment())
    return;
  if(!attacker_ob)
    return;
  nmy = AO;
  if(hit_point <= 100)
    hit_point += 3;
  if(attacker_ob == this_object())
  {
    stop_fight();
    stop_fight();
  }
  if(weapon_class < 55)
    weapon_class = 55;
  if(!random(9)){   attack_special();  return;  }
  if(!random(8)) go();
}
