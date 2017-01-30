/*  Tyrannosaurus Rex  */

#define TP this_player()
#include "/players/eurale/closed/ansi.h"
inherit "obj/monster.c";

reset(arg) {

::reset(arg);
if(arg) return;
set_name("rex");
set_race("creature");
set_short("Tyrannosaurus Rex");
set_alias("tyrannosaurus");
set_long(
	"  This fierce, meat-eating reptile grew to over 40 feet in length \n"+
	"and stood over 20 feet tall.  It's jaws were nearly 4 feet in \n"+
	"length and contained 6 inch long curved teeth.  It was the largest\n"+
	"and most feared meat eater that ever lived. \n");
set_level(19);
set_hp(450 + random(100));
set_al(-1);
set_ac(17);
set_aggressive(1);
set_dead_ob(this_object());

set_wc(30);


set_chat_chance(5);
  load_chat("You shake at the sound of its primeval roar... \n");
set_a_chat_chance(8);
  load_a_chat("\n\nRex SNARLES and LUNGES at you..\n\n");


set_chance(12);
set_spell_dam(45);
  set_spell_mess1(
	"\n\nThe mighty Rex takes a fearsome bite of its prey.. \n\n");
  set_spell_mess2(
	"\nThe mighty Rex opens its jaws, fangs dripping with blood \n\n"+
        "and..... "+BOLD+" C R U N C H "+NORM+" bites down, piercing your flesh.\n\n");

}

monster_died() {
  tell_room(environment(this_object()),
  "\n\nYour final blow KNOCKS the front tooth from the mighty beast!\n\n");
  move_object(clone_object("players/eurale/Park/OBJ/tooth"),
    environment(this_object()));
  if(this_player())
  move_object(clone_object("players/eurale/Park/OBJ/qst3"),
                this_player());
  else if(attacker_ob) move_object(clone_object("players/eurale/Park/OBJ/qst3"),
 attacker_ob);
  write_file("/players/eurale/Park/LOG/rexquest",
  ctime(time())+"     Rex3     "+query_attack()->query_real_name()+"\n");
return 0; }
