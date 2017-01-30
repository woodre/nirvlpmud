/* Intended for use in Zeus' fallen lands forest 'arena'
*  will hunt players at random - no coins
*/
inherit "/obj/monster";
#include "/players/zeus/closed/all.h"
#include "/players/zeus/realm/x/defs.h"
#include "/players/zeus/realm/x/demon_check.h"
#define LEAVE "The vulture flys away.\n"
#define ARRIVE "A vulture soars in from the trees.\n"
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

  set_name("dark vulture");
  set_short("A dark vulture");
  set_long(
"This vulture lurks among the shadows, preying upon those weak\n"+
"creatures unfortunate enough to fall under its gaze.  It has a\n"+
"slender body covered in jet black feather.  Its sharp beak looks\n"+
"as though it could tear through flesh and bone.\n");
  set_race("vulture");
  set_gender("creature");
  set_level(14);
  set_hp(150+random(50));
  set_ac(9);
  set_wc(20);
  set_al(-random(1000));
  set_aggressive(1);
  set_dead_ob(TO);
  call_out("fake_hb", 1);
}   }

/*  Allow npcs to hunt players */
#include "/players/zeus/realm/x/hunt.h"

monster_died(){
  write_file("/players/zeus/log/X", ctime(time())+"   "+
       capitalize((string)TP->QRN)+" killed a vulture.\n");
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
