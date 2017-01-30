/* Intended for use in Zeus' fallen lands forest 'arena'
*  will hunt players at random, and flee from combat.
*/
inherit "/obj/monster";
#include "/players/zeus/closed/all.h"
#include "/players/zeus/realm/x/defs.h"
#include "/players/zeus/realm/x/demon_check.h"
#define LEAVE "The apparition drifts away.\n"
#define ARRIVE "An apparition appears before you.\n"
object *arena, *nmys;
string w;

reset(arg) {
   ::reset(arg);
   if (!arg) {

	   arena = allocate(9);
	   arena =({
		   "players/zeus/realm/x/r/1",
		   "players/zeus/realm/x/r/2",
		   "players/zeus/realm/x/r/3",
		   "players/zeus/realm/x/r/4",
		   "players/zeus/realm/x/r/5",
		   "players/zeus/realm/x/r/6",
		   "players/zeus/realm/x/r/7",
		   "players/zeus/realm/x/r/8",
		   "players/zeus/realm/x/r/9", });

	set_name("headless apparition");
	set_alias("apparition");
	set_alt_name("headless");
	set_short(BOLD+"A headless apparition"+NORM);
	set_long(
"The figure before you has a human shape, but lacks a head.  It is hidden\n"+
"beneath a tattered cloak.  Its white flesh is decaying and slowly peeling\n"+
"off of its body.  The entire creature is of a soft gray color, and is\n"+
"somewhat transparent.  It is doomed to spend eternity in the forest.\n");
	set_race("spirit");
	set_gender("creature");
	set_ac(13);
	set_wc(40+random(8));
	set_hp(400+random(100));
  set_wc_bonus(4);  /* heal_self */
  set_hp_bonus(200);  /* flees and heals from special */
	set_heal(1,1);
	set_level(20);
	set_al(-600);
	set_aggressive(1);
	set_chat_chance(3);
	load_chat("The headless apparition floats towards you.\n");
	load_chat("The headless apparition grasps at you.\n");
	load_chat("Strange noises can be heard all around.\n");
	load_chat("The forest seems alive.\n");
	set_dead_ob(TO);
	call_out("fake_hb", 1);
   }
}

/*  Allow npcs to hunt players */
#include "/players/zeus/realm/x/hunt.h"

monster_died(){
  object corpse, heal, heal2;
  corpse = present("corpse", environment());
  heal = CO("/players/zeus/heals/shadow.c");
  heal2 = CO("/players/zeus/heals/shadow.c");
  if(!random(2)) heal->set_type(2);
  if(!random(2)) heal2->set_type(2);
  MO(heal, environment());
  MO(heal2, environment());
  write_file("/players/zeus/log/X", ctime(time())+"   "+
       capitalize((string)TP->QRN)+" killed a headless apparition.\n");
  write("The headless apparition fades into nothing...\n");
  if(corpse) destruct(corpse);
}


atk(){
	if(AO && present(AO, ENV)){
		TR(environment(),
			"The headless apparition grasps "+AO->QN+"'s throat.\n"+
			"It feeds on the life force of "+AO->QN+"!\n", ({AO}));
		tell_object(AO,
			"The headless apparition grasps your throat.\n"+
			"It feeds on your life force!\n");
		AO->heal_self(-15);
		hit_point += 10;
	}
}

death(){
	TR(environment(),
		"The headless apparition fades into nothing...\n");
	destruct(TO);
}

flee(){
	int c;
	if(!sscanf(file_name(ENV), "players/zeus/realm/x/r/%s", w))
		return;
	while(AO && present(AO, ENV)){
		c = random(9);
		if(!c) MO(TO, arena[0]);
		else if(c == 1) MO(TO, arena[1]);
		else if(c == 2) MO(TO, arena[2]);
		else if(c == 3) MO(TO, arena[3]);
		else if(c == 4) MO(TO, arena[4]);
		else if(c == 5) MO(TO, arena[5]);
		else if(c == 6) MO(TO, arena[6]);
		else if(c == 7) MO(TO, arena[7]);
		else if(c == 8) MO(TO, arena[8]);
	}
	TR(environment(AO), 
		"The apparition drifts away.\n");
	TR(environment(), 
		"An apparition appears before you.\n");
	hunted = 0;
	hunter = 0;
}

fake_hb(){
	if(!environment()) return;
	call_out("fake_hb", 1);
	if(AO && !present(AO, ENV))
		AO = 0;
	if(!AO && !random(HCHANCE))
		hunt();
	else if(!AO && !random(DCHANCE))
		death();
	if(AO && !random(DEMON))
		demon_check();
	if(AO && !random(8))
		atk();
	if(AO && !random(FCHANCE))
		flee();
}
