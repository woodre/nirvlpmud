/*  Tyrannosaurus Rex  */

#define tp this_player()
#include "/players/eurale/closed/ansi.h"
inherit "obj/monster.c";

reset(arg) {

::reset(arg);
if(arg) return;
set_name("rex");
set_race("creature");
set_short(BOLD+"Tyrannosaurus Rex"+NORM);
set_alias("tyrannosaurus");
set_long(
	"  This fierce, meat-eating reptile grew to over 40 feet in length \n"+
	"and stood over 20 feet tall.  It's jaws were nearly 4 feet in \n"+
	"length and contained 6 inch long curved teeth.  It was the largest\n"+
	"and most feared meat eater that ever lived. \n");
set_level(20);
set_hp(500 + random(200));
set_al(-100);
set_ac(18);
set_aggressive(1);
set_dead_ob(this_object());

set_wc(33);


set_chat_chance(5);
  load_chat("The tyrannosaurus cocks his head and stares at you.. \n");
  load_chat("You shake at the sound of its primeval roar... \n");


set_chance(16);
set_spell_dam(65 + random(10));
  set_spell_mess1(
	"\n\nThe mighty Rex takes a fearsome bite of its prey.. \n\n");
  set_spell_mess2(
	"\n\nThe mighty Rex opens its jaws, fangs dripping with blood..\n\n"+
	"and..... "+BOLD+" C R U N C H "+NORM+" bites down, piercing your flesh.\n\n");

}

monster_died() {
  tell_room(environment(this_object()),
  "\n\nIn a dying gesture, the huge beast SPITS one of his broken\n"+
  "teeth at you hitting you IN THE FACE... and then dies...\n\n");
  this_player()->heal_self(-random(40));
  move_object(clone_object("players/eurale/Park/OBJ/tooth"),
    environment(this_object()));
  move_object(clone_object("players/eurale/Park/OBJ/rex_skin"),
	environment(this_object()));
  if(this_player())
  move_object(clone_object("players/eurale/Park/OBJ/qst1"),
		this_player());
  else if(attacker_ob) move_object(clone_object("players/eurale/Park/OBJ/qst1"), attacker_ob);
  write_file("/players/eurale/Park/LOG/rexquest",
  ctime(time())+"     Rex1     "+query_attack()->query_real_name()+"\n");
return 0; }
