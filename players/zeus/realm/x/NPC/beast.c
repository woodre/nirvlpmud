/* Intended for use in Zeus' fallen lands forest 'arena'
*  will hunt players at random - coins 3500+r(2200);
*/
inherit "/obj/monster";
#include "/players/zeus/closed/all.h"
#include "/players/zeus/realm/x/defs.h"
#include "/players/zeus/realm/x/demon_check.h"
#define LEAVE "The beast leaves into the forest.\n"
#define ARRIVE "A beast emerges from behind a tree.\n"
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

  set_name("beast");
  set_short("A beast of the forest");
  set_long(
"The creature you look at now is a mighty beast.  Its matted fur is truly\n"+
"filthy, and smells awful.  The jaw of the beast is somewhat crooked,\n"+
"causing drool to slowly drip from its mouth.  It has a powerful body,\n"+
"and looks to be at least a few hundred pounds heavy.  Long claws adorn\n"+
"each of its four wide paws.  Its eyes follow you like a hawks.\n");
  set_race("wolf");
  if(!random(2)) set_gender("male");
  else set_gender("female");
  set_level(21);
  set_hp(400+random(220));
  set_ac(17+random(4));
  set_wc(30+random(10));
  set_heal(3,10);
  set_al(-random(1000));
  set_aggressive(1);
  set_chance(15);
  set_spell_dam(25+random(16));
  set_spell_mess1("The beast tears into your flesh.\n");
  set_spell_mess2("You feel great pain as the beast bites you.\n");
  set_chat_chance(3);
  load_chat("The beast growls at you.\n");
  load_chat("The beast rears up on its hind legs.\n");
  load_chat("The beast paws the ground.\n");
  load_chat("The beast rages with anger.\n");
  load_chat("You are suddenly filled with fear.\n");
  set_dead_ob(TO);
  call_out("fake_hb", 1);
}   }

/*  Allow npcs to hunt players */
#include "/players/zeus/realm/x/hunt.h"

monster_died(){
	TR(environment(),
		"The beast slumps to the ground....\n");
	MO(CO("/players/zeus/realm/x/OBJ/claws.c"), ENV);
  write_file("/players/zeus/log/X", ctime(time())+"   "+
       capitalize((string)TP->QRN)+" killed a beast.\n");
}

death(){
	TR(environment(), "The beast leaves into the forest.\n");
	destruct(TO);
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
	if(!AO && !random(DCHANCE))
		death();
}