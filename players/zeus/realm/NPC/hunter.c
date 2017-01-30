inherit "/obj/monster";
#include "/players/zeus/closed/all.h"
#define OQN AO->QN
#define OQP AO->POS

int old_opp_hp, new_opp_hp, heal, old_opp_sp, new_opp_sp, spheal,x;

reset(arg) {
   ::reset(arg);
   if (!arg) {

	   old_opp_hp = 1000;
	   old_opp_sp = 1000;

  set_name("renegade hunter");
  set_short("A Renegade Hunter");
  set_alias("hunter");
  set_race("cyborg");
  set_gender("creature");
  set_long(
"The Renegade Hunter is a very old cyborg.  Patches of metal are visible\n"+
"beneath its skin on its chest and legs.  Its right arm is robotic.\n"+
"Its left leg appears to be damaged, as it walks a little off balance.\n"+
"Despite its age, the Hunter looks like an incredibly powerful cyborg.\n"+
"A red laser is being projected from its right eye.  It has a peculiar\n"+
"looking red jewel imbedded in its chest.\n");
  set_level(20);
  set_hp(500);
  set_ac(16);
  set_wc(36);
  set_wc_bonus(6);
  set_al(-500);
  set_dead_ob(TO);
   }
}

monster_died(){
  object corpse, leg, arm, chest, head;
  corpse = present("corpse", environment());
 write(
"The cyborg falls to the ground in pieces...\n");
 leg = CO("/obj/treasure.c");
 leg->set_id("leg");
 leg->set_short("A shattered mechanical leg");
 leg->set_weight(3);
 leg->set_value(600);
 MO(leg, environment());
 arm = CO("/obj/treasure.c");
 arm->set_id("arm");
 arm->set_short("A fragmented mechanical arm");
 arm->set_weight(2);
 arm->set_value(700);
 MO(arm, environment());
 chest = CO("/obj/treasure.c");
 chest->set_id("chest");
 chest->set_short("A cyborgs damaged chest");
 chest->set_weight(7);
 chest->set_value(900);
 MO(chest, environment());
 head = CO("/obj/treasure.c");
 head->set_id("head");
 head->set_short("A cyborgs head");
 head->set_weight(3);
 head->set_value(800);
 MO(head, environment());
 MO(CO("/players/zeus/realm/OBJ/ruby.c"), environment());
  if(corpse)
    destruct(corpse);
return 1; }

opponent_heal_function(){
	x = 0;
	if(!present(AO, environment())) return 0;  
    new_opp_hp = (int) AO->query_hp();
	new_opp_sp = (int) AO->query_spell_point();
    heal = (new_opp_hp - old_opp_hp);
	spheal = (new_opp_sp - old_opp_sp);
    if(heal > 2){ 
			AO->hit_player(heal / 2);
			x = 1;
	}
	if(spheal > 2){
			AO->add_spell_point(-spheal / 2);
			x = 1;
	}
	if(x){
		tell_object(AO, "You suddenly feel weak.\n");
		TR(environment(), AO->QN+" staggers.\n", ({AO}));
	}
	old_opp_hp = new_opp_hp;
	old_opp_sp = new_opp_sp;
}


attack_special(){
   TR(environment(),
	   "The Renegade Hunter punches "+OQN+" in "+OQP+" chest.\n",
	   ({ AO }));
   tell_object(AO,
	   "The Renegade Hunter punches you in the chest.\n"+
	   "You stagger from the blow.\n");
   AO->hit_player(random(35));
   return 1;
}

void heart_beat(){
	::heart_beat();
        if(!environment()) 
                return ;
        if(!AO)
				return ;
		opponent_heal_function();
		if(!random(12)){   attack_special();  return ;  }
}
