/*  a spirit that shadows players through my area.
    will add atmosphere to area, and make things fun ;)
	this is just a 'rough draft'
*/

inherit "/obj/monster";
#include "/players/zeus/closed/all.h"
#define A (object)shadow->query_attack()
#define AHP (int)shadow->query_attack()->query_hp()
#define AN (string)shadow->query_attack()->query_name()
#define ALGN (int)shadow->query_alignment()
object room, shadow, *pot;
int z;
string w;

reset(arg) {
   ::reset(arg);
   if (!arg) {

 set_name("fallen curse");
 set_alias("curse");
 set_short(0);
 set_long(0);
 set_race("spirit");
 set_ac(3);
 set_wc(40);
 set_level(19);
 set_heal(1,1);
 set_al(-1400);
 set_aggressive(0);
 set_heart_beat(1);
 set_dead_ob(this_object());
} }

monster_died(){
	write("A soul fades away...\n");
	if(present("corpse", environment()))
		destruct(present("corpse", environment()));
}

shadow(){
  if(!present(shadow, environment())){
	if(!sscanf(file_name(environment(shadow)), 
		"players/zeus/realm/%s", w)){
	  home();
	}
  else MO(TO, environment(shadow));
  }
}

assist(){
  if(shadow && present(shadow, environment()) && 
	  shadow->query_attack()){
	if(AHP < 50 && !random(10) && ALGN < 0){
	  TR(environment(), AN+" is suddenly invigorated!\n");
	  A->heal_self(15+random(20));
	  A->set_wc(A->query_wc()+5+random(8));
	}
	else if(AHP < 50 && !random(10) && ALGN > 0){
	  tell_object(shadow, "You are suddenly invigorated!\n");
	  if(!random(2))
	    shadow->add_spell_point(10);
	  else
	    shadow->add_hit_point(10);
	}

  }
}

curse(){
  if(shadow && present(shadow, environment()) && 
	  !shadow->query_attack()){
	if(!random(25) && ALGN < 0){
		if(!random(2))
	  tell_object(shadow, "You feel a weight pressing down on you.\n");
		else
	  tell_object(shadow, "You suddenly feel drained.\n");
	  if(shadow->query_hp() > 15)
	    shadow->add_hit_point(-15);
	}
	else if(!random(25) && ALGN > 0){
	  tell_object(shadow, "You suddenly feel refreshed.\n");
	  shadow->heal_self(10);
	}
	else if(!random(150)){
	  tell_object(shadow, "Panic suddenly fills you!\n");
	  shadow->run_away();
	}
	else if(!random(75)){
		object x;
		x = CO("/players/zeus/realm/NPC/demon1.c");
	  TR(environment(shadow),
        "A "+BOLD+"VORTEX"+NORM+" opens before you...\n"+
        "A cursed demon steps out and lunges at "+shadow->QN+"!\n\n");
	  MO(x, environment(shadow));
	  x->attack_object(shadow);
	}
  }
}


home(){
	MO(TO, "/players/zeus/realm/city/ent.c");
	shadow = 0;
	if(AO) AO->stop_fight();
	stop_fight();
	stop_fight();
	hit_point += 50;
	set_heart_beat(0);
}

check(){
  room = all_inventory(environment());
  if(AO) home();
  if(!shadow || !random(10)){
	pot = ({ });
    for(z=0;z<sizeof(room);z++){
	  if(room[z]->is_player() && !room[z]->query_ghost()){
		  pot += ({ room[z], });
	  }
	}
  shadow = pot[random(sizeof(pot))];
  }
}

heart_beat(){
  ::heart_beat();
  if(!environment())
	  return;
  check();
  if(shadow) shadow();
  else { home(); return; }
  assist();
  curse();
}
