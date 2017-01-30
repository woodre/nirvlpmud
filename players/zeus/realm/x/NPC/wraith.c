/* Intended for use in Zeus' fallen lands forest 'arena'
*  will hunt players at random, and flee from combat.
*/
inherit "/obj/monster";
#include "/players/zeus/closed/all.h"
#include "/players/zeus/realm/x/defs.h"
#include "/players/zeus/realm/x/demon_check.h"
#define LEAVE "The wraith disappears into the shadows.\n"
#define ARRIVE "A wraith appears from the shadows.\n"
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

	set_name("shadow wraith");
	set_short(0);
	set_alias("wraith");
	set_long(
"This is a wraith that dwells in the shadows.  It is a shadowy figured\n"+
"that seems to drift in the wind.  You are able to see straight through\n"+
"it.  The wraith is doomed to spend the rest of its existence hunting\n"+
"in the forest, feeding on the souls of the living.  Its eyes weep\n"+
"softly, filling you with despair.\n");
	set_race("spirit");
	set_gender("female");
	set_level(20);
	set_ac(10+random(9));
	set_wc(26+random(12));
	set_hp(400+random(200));
  set_hp_bonus(180);  /* flees */
	set_heal(1,1);
	set_al(-random(1000));
	set_aggressive(1);
	set_chat_chance(3);
  set_chance(15);
  set_spell_dam(30+random(20));
  set_spell_mess1("The wraith screams at you.\n");
  set_spell_mess2("The wraith screams at you.\n");
	load_chat("The wraith glides among the shadows.\n");
	load_chat("The wraith weeps softly.\n");
	load_chat("The wraith drifts among the trees.\n");
	set_dead_ob(TO);
	call_out("fake_hb", 1);
}   }

/*  Allow npcs to hunt players */
#include "/players/zeus/realm/x/hunt.h"

monster_died(){
  object corpse, heal;
  corpse = present("corpse", environment());
  heal = CO("/players/zeus/heals/shadow.c");
  if(!random(2)) heal->set_type(2);
  MO(heal, environment());
  write_file("/players/zeus/log/X", ctime(time())+"   "+
       capitalize((string)TP->QRN)+" killed a shadow wraith.\n");
  write("The wraith fades into nothing...\n");
  if(corpse) destruct(corpse);
}

death(){
	TR(environment(),
		"The wraith disappears into the shadows.\n");
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
		"The wraith disappears into the shadows.\n");
	TR(environment(), 
		"A wraith appears from the shadows.\n");
	hunted = 0;
	hunter = 0;
}

fake_hb(){
	if(!environment()) return;
	call_out("fake_hb", 1);
	if(AO && !present(AO, ENV))
		AO = 0;
	if(AO && !random(DEMON))
		demon_check();
	if(!AO && !random(HCHANCE))
		hunt();
	else if(!AO && !random(DCHANCE))
		death();
	if(AO && !random(FCHANCE))
		flee();
}
