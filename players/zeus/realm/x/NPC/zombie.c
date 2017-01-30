/* Intended for use in Zeus' fallen lands forest 'arena'
*  will hunt players at random
*/
inherit "/obj/monster";
#include "/players/zeus/closed/all.h"
#include "/players/zeus/realm/x/defs.h"
#include "/players/zeus/realm/x/demon_check.h"
#define LEAVE "The zombie disappears into the shadows.\n"
#define ARRIVE "A zombie appears from the shadows.\n"
object *arena, *nmys;
string w, a;
int aa;

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

	aa = random(10);
	if(aa == 0) a = "restless";
	if(aa == 1) a = "decaying";
	if(aa == 2) a = "furious";
	if(aa == 3) a = "worm-eaten";
	if(aa == 4) a = "moaning";
	if(aa == 5) a = "greenish";
	if(aa == 6) a = "pale";
	if(aa == 7) a = "white";
	if(aa == 8) a = "cursed";
	if(aa == 9) a = "rotting";

  set_name("zombie");
  set_short("A "+a+" zombie");
  set_long(
"This zombie does not look very pleased to be here.  It has pale, torn\n"+
"skin, covered by some tattered rags.  Its flesh is rotten and smells\n"+
"acrid.  The expression it wears is one of unending torment and pain.\n");
  set_gender("creature");
  set_race("zombie");
  set_level(20);
  set_hp(400+random(300));
  set_hp_bonus(110);
  set_wc(33+random(16));
  set_ac(12+random(16));
  set_al(-random(1000));
  add_money(3000+random(4500));
  set_chance(15);
  set_spell_dam(25+random(16));
  set_spell_mess1("The zombie grasps at your face.\n");
  set_spell_mess2("You feel pain as the zombie grabs you.\n");
  set_aggressive(1);
  set_chat_chance(3);
  load_chat("The zombie walks towards you.\n");
  load_chat("Wind blows through the trees above.\n");
  load_chat("The zombie moans horribly at you.\n");
  load_chat("The zombie lurches towards you.\n");
  load_chat("Shadows dart past your eyes.\n");
  set_dead_ob(this_object());
  call_out("fake_hb", 1);
   }
}

/*  Allow npcs to hunt players */
#include "/players/zeus/realm/x/hunt.h"

monster_died(){
  write_file("/players/zeus/log/X", ctime(time())+"   "+
       capitalize((string)TP->QRN)+" killed a "+a+" zombie.\n");
}

death(){
	TR(environment(),
		"The zombie staggers away.\n");
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
	else if(!AO && !random(DCHANCE))
		death();
}