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
	set_ac(26);
	set_wc(35);
	set_hp(1200);
    set_ac_bonus(10);
    set_wc_bonus(50);
    set_hp_bonus(100);
	set_level(23);
	set_al(-600);
	set_heal(5,15);
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
   }
}

monster_died(){
  object corpse;
  corpse = present("corpse", environment());
	write_file("/players/zeus/log/museum", ctime(time())+"   "+
	capitalize((string)TP->QRN)+" defeated Classic Granite Golem.\n");
   "/players/zeus/museum/lounge.c"->npc666();
	TR(environment(),
		"The golem explodes into fragments of rock!\n"+
		"An object rests among the rubble.\n");
  AO->add_exp(8000);
  if(corpse)
	MO(CO("/players/zeus/museum/OBJ/gstaff.c"), corpse);
}

unmoo(){
	TR(environment(), "The golem uncurls, ready to fight.\n");
	weapon_class = 35;
	armor_class = 26;
	ball = 0;
}

moo(){
	TR(environment(), "The golem curls up into a tight ball.\n");
	armor_class = 50;
	weapon_class = 2;
	ball = 1;
	call_out("unmoo", 20);
}

rage(){
	int x;
	TR(environment(),
		"Bloodlust fills the golem with a demonic RAGE!\n\n");
	for(x = 0; x < (4+random(4)); x ++){
		if(AO->query_ghost() && AO->is_player()) return;
		else {
	    already_fight = 0;
        ::attack();
		}
	}
}

damage_function(){
	int p;
	object room, meat;
	nmys = ({ });
	if(random(4+random(2))) return;
	room = all_inventory(environment(TO));
    TR(environment(TO),
"\nA chunk of granite becomes detached and falls to the ground...\n"+
"The chunk molds into a mini granite golem!\n\n");
	lgolem = CO("/players/zeus/museum/NPC/tiny_golem.c");
	MO(lgolem, environment());
	for(p = 0; p < sizeof(room); p++){
		if(room[p]->is_player())
				nmys += ({ room[p], });
	}
	meat = nmys[random(sizeof(nmys))];
	lgolem->attack_object(meat);
}

team(){
	int y, no;
	object x, z, grr;
	no = 0;
	x = all_inventory(environment());
	for(y = 0; y < sizeof(x); y++){
		if(x[y]->is_player())
			no++;
	}
	if(no == 2){
	for(y = 0; y < sizeof(x); y++){
		if(x[y]->is_player() && 
			(string)x[y]->query_attack() != "granite golem")
			grr = x[y];
	}
		TR(environment(), 
	"A huge chunk of granite falls to the ground...\n"+
	"The chunk molds into 3 mini granite golems!\n");
		for(y = 0; y < 3; y++){
			z = CO("/players/zeus/museum/NPC/tiny_golem.c");
			MO(z, environment());
			if(grr)
			z->attack_object(grr);
			else if(alt_attacker_ob)
				z->attack_object(alt_attacker_ob);
			else
				z->attack_object(AO);
		}
	}
	else if(no > 2){
		for(y=0;y<sizeof(x);y++){
			if(x[y]->is_player() &&
			(string)x[y]->query_attack() == "granite golem" ||
			(string)x[y]->query_attack() == "mini golem"){
		tell_object(x[y],
			"The golem pounds you with its mighty fists!\n");
		x[y]->hit_player(60+random(30));
			}
		}
	}
}


pet_check(){
	object pet, mech, wolf;
	pet = present("pet", environment());
	mech = present("mech", environment());
	wolf = present("wolf", environment());
	if(pet){
		TR(environment(), 
			"The golem reaches down and grabs the pet.\n"+
			"The golem bites the pets head off.\n");
		destruct(pet);
	}
	else if(mech){
		TR(environment(),
			"The golem grabs the mech and crushes it easily.\n");
		destruct(mech);
	}
	else if(wolf){
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
        if(!AO)	return ;
		if(!random(6))
			pet_check();
		if(ball)
			hit_point += 5;
		if(!random(20) && !ball)
			moo();
		if(!random(20) && !ball)
			rage();
		if(!random(10) && !ball)
			team();
		if((string)AO->QRN == "granite golem"){
			AO->stop_fight();
			if(AAO) AAO->stop_fight();
			this_object()->stop_fight();
			this_object()->stop_hunted();
			weapon_class += random(15);
			TR(environment(), "The golem grows larger.\n");
		}
		damage_function();
}
