/* Intended for use in Zeus' fallen lands forest 'arena'
*  will hunt players at random
*/
inherit "/obj/monster";
#include "/players/zeus/closed/all.h"
#include "/players/zeus/realm/x/defs.h"
#include "/players/zeus/realm/x/demon_check.h"
#define LEAVE "The ghoul disappears among the shadows.\n"
#define ARRIVE "A ghoul appears from the shadows.\n"
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

  set_name("ghoul");
  set_alias("khabal");
  set_short("A khabal ghoul");
  set_long(
"The khabal ghoul is not so much a physical being as it is a spirit\n"+
"of the forest.  It is highlighted by a yellow, cracked skull that\n"+
"protrudes from the upper part of a purple suit of armor.  About\n"+
"half way down though, the armor fades into nothingness.  The ghouls\n"+
"empty sockets watch you with a demonic intensity.\n");
  set_race("ghoul");
  set_gender("creature");
  set_level(21);
  set_hp(430+random(200));
  set_wc(30+random(9));
  set_wc_bonus(4);   /* sps drain */
  set_hp_bonus(160);  /* flees */
  set_ac(10+random(6));
  add_money(4500+random(3000));
  set_al(-random(1000));
  set_aggressive(1);
  set_chance(15);
  set_spell_dam(25+random(26));
  set_spell_mess1("The ghoul bites your flesh!\n");
  set_spell_mess2("You feel pain as the ghoul bites your flesh!\n");
  set_chat_chance(3);
  load_chat("The ghoul glares at you.\n");
  load_chat("The ghoul hides among the shadows.\n");
  load_chat("The ghoul watches you.\n");
  set_dead_ob(this_object());
  call_out("fake_hb", 1);
} }

/*  Allow npcs to hunt players */
#include "/players/zeus/realm/x/hunt.h"

monster_died(){
  write_file("/players/zeus/log/X", ctime(time())+"   "+
       capitalize((string)TP->QRN)+" killed a khabal ghoul.\n");
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
		"The ghoul disappears among the shadows.\n");
	TR(environment(), 
		"A ghoul appears from the shadows.\n");
	hunted = 0;
	hunter = 0;
}

death(){
	TR(environment(),
		"The ghoul disappears among the shadows.\n");
	destruct(TO);
}

atk(){
	TR(environment(),
		"The ghoul feeds on "+AO->QN+"'s energy!\n", ({AO}));
	tell_object(AO,
		"The ghoul feeds on your energy!\n");
	AO->add_spell_point(-20);
}

fake_hb(){
	if(!environment()) return;
	call_out("fake_hb", 1);
	if(AO && !present(AO, ENV))
		AO = 0;
	if(AO && !random(9))
		atk();
	if(!AO && !random(HCHANCE))
		hunt();
	if(AO && !random(DEMON))
		demon_check();
	if(AO && hit_point < 100 && !random(5))
		flee();
	if(!AO && !random(DCHANCE))
		death();
}
