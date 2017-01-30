/* Intended for use in Zeus' fallen lands forest 'arena'
*  will hunt players at random
*/
inherit "/obj/monster";
#include "/players/zeus/closed/all.h"
#include "/players/zeus/realm/x/defs.h"
#include "/players/zeus/realm/x/demon_check.h"
#define LEAVE "The bandit hides in the shadows.\n"
#define ARRIVE "A bandit appears before you.\n"
object *arena, *nmys;
string w;

reset(arg) {
   ::reset(arg);
   if (!arg) {

	   if(!present("dagger", TO)){
	 MO(CO("/players/zeus/realm/x/OBJ/dagger.c"), TO);
	 init_command("wield dagger"); }

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

  set_name("bandit");
  set_short("A bandit of the forest");
  set_long(
"This bandit lurks among the shadows, waiting behind the trees to\n"+
"strike.  He is powerfully built, wearing an outfit of black.  You\n"+
"notice a sharp steel dagger at his waist.  He looks like he may\n"+
"want more than just your money.\n");
  set_race("human");
  set_gender("male");
  set_level(19+random(2));
  set_hp(510);
  set_hp_bonus(60);
  set_ac(17);
  set_wc(30);
  set_wc_bonus(8);
  set_al(-random(500));
  set_aggressive(1);
  add_money(5000+random(2000));
  set_chance(15);
  set_spell_dam(40);
  set_spell_mess1("The bandit slashes you with his dagger.\n");
  set_spell_mess2("The bandit slashes you with his dagger.\n");
  set_chat_chance(3);
  load_chat("The bandit grins at you.\n");
  load_chat("The bandit says: don't make a move.\n");
  load_chat("The bandit slips behind a shadow.\n");
  set_dead_ob(this_object());
  call_out("fake_hb", 1);
}   }

/*  Allow npcs to hunt players */
#include "/players/zeus/realm/x/hunt.h"

monster_died(){
  write_file("/players/zeus/log/X", ctime(time())+"   "+
       capitalize((string)TP->QRN)+" killed a bandit.\n");
}

death(){
	TR(environment(), "The bandit hides in the shadows.\n");
	if(present("dagger", TO))
		destruct(present("dagger", TO));
	destruct(TO);
}

danger_will_robinson(){
  if(!AO->query_ghost()){
		already_fight = 0; ::attack();
} }


fake_hb(){
	if(!environment()) return;
	call_out("fake_hb", 1);
	if(AO && !present(AO, ENV))
		AO = 0;
	if(AO && !random(DEMON))
		demon_check();
	if(AO && !random(3))
		danger_will_robinson();
	if(!AO && !random(HCHANCE))
		hunt();
	if(!AO && !random(DCHANCE))
		death();
}

