/* Intended for use in Zeus' fallen lands forest 'arena'
*  will flee from combat.  and hunts
*  only 2k coins in treasure
*/
inherit "/obj/monster";
#include "/players/zeus/closed/all.h"
#include "/players/zeus/realm/x/defs.h"
#include "/players/zeus/realm/x/demon_check.h"
#define LEAVE "The shadowy figure vanishes from sight.\n"
#define ARRIVE "A shadowy figure appears from the shadows.\n"
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

	 if(!present("scythe", TO)){
	 MO(CO("/players/zeus/realm/x/OBJ/scythe.c"), TO);
	 init_command("wield scythe"); }

  set_name("shadowy figure");
  set_alias("figure");
  set_short(HIW+"A shadowy figure"+NORM);
  set_long(
"The figure before you seems to be cloaked in a shadow.  You are\n"+
"unable to see any defining features about the figure.  It drifts just\n"+
"a few inches above the ground.  It holds in its hands a mighty scythe.\n");
  set_level(20);
  set_gender("male");
  set_race("spirit");
  set_ac(9+random(7));
  set_wc(28+random(8));
  set_hp(460+random(300));
  set_hp_bonus(160);  /* cause it flees like a bitch */
  set_heal(1,1);
  set_al(-random(1000));
  set_aggressive(1);
  set_chat_chance(3);
  load_chat("The figure drifts among the shadows.\n");
  load_chat("The figure drifts in and out of view.\n");
  load_chat("The figure glares through you.\n");
  set_dead_ob(TO);
  call_out("fake_hb", 1);
} }

/*  Allow npcs to hunt players */
#include "/players/zeus/realm/x/hunt.h"

monster_died(){
  object corpse;
  corpse = present("corpse", environment());
  write_file("/players/zeus/log/X", ctime(time())+"   "+
       capitalize((string)TP->QRN)+" killed a shadowy figure.\n");
  MO(CO("/players/zeus/realm/x/OBJ/cloak.c"), environment());
  if(corpse) destruct(corpse);
}

death(){
	TR(environment(), "The shadowy figure vanishes from sight.\n");
	if(present("scythe", TO))
		destruct(present("scythe", TO));
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
		"The shadowy figure vanishes from sight.\n");
	TR(environment(), 
		"A shadowy figure appears from the shadows.\n");
	hunted = 0;
	hunter = 0;
}

fake_hb(){
	if(!environment()) return;
	call_out("fake_hb", 1);
	if(AO && !present(AO, ENV))
		AO = 0;
	if(AO && hit_point < 100 && !random(4))
		flee();
	if(AO && !random(DEMON))
		demon_check();
	if(!AO && !random(HCHANCE))
		hunt();
	if(!AO && !random(DCHANCE))
		death();
}
