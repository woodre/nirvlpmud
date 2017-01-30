/* Intended for use in Zeus' fallen lands forest 'arena'
*  will hunt players at random - no coins
*/
inherit "/obj/monster";
#include "/players/zeus/closed/all.h"
#include "/players/zeus/realm/x/defs.h"
#include "/players/zeus/realm/x/demon_check.h"
#define LEAVE "The spider disappears into the forest.\n"
#define ARRIVE "A spider emerges from the forest.\n"
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

  set_name("gigantic spider");
  set_short("A gigantic spider");
  set_long(
"This is a gigantic spider the dwells in the depths of the forest.\n"+
"Its massive body is covered in dark, coarse hair.  Is has two beady\n"+
"white eyes at the front of its round head, which features two large\n"+
"fangs which remind you of daggers.\n");
  set_race("spider");
  set_gender("creature");
  set_level(14);
  set_hp(150+random(50));
  set_ac(10);
  set_wc(25+random(7));
  set_al(-random(1000));
  set_aggressive(1);
  set_chance(15);
  set_spell_dam(25);
  set_spell_mess1("The spider bites you with its fangs.\n");
  set_spell_mess2("You feel great pain as the spider bites you.\n");
  set_dead_ob(TO);
  call_out("fake_hb", 1);
}   }

/*  Allow npcs to hunt players */
#include "/players/zeus/realm/x/hunt.h"

monster_died(){
  object cash;
  write_file("/players/zeus/log/X", ctime(time())+"   "+
       capitalize((string)TP->QRN)+" killed a spider.\n");
  write("You notice some coins that were uncovered during the fight.\n");
  cash = clone_object("/obj/money.c");
  cash->set_money(600+random(1200));
  move_object(cash, environment(this_object()));
}

death(){
	TR(environment(), LEAVE);
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
