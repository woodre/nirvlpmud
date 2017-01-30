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
set_level(20);
set_hp(550 + random(100));
set_al(-1);
set_ac(17);
set_aggressive(1);
set_dead_ob(this_object());

set_wc(31);


set_chat_chance(15);
  load_chat("You shake at the sound of its primeval roar... \n");
set_a_chat_chance(20);
  load_a_chat("\n\nRex SNARLES and LUNGES at you..\n\n");


set_chance(11);
set_spell_dam(35 + random(15));
  set_spell_mess1(
	"\n\nThe mighty Rex takes a fearsome bite of its prey.. \n\n");
  set_spell_mess2(
	"\nThe mighty Rex opens its jaws, fangs dripping with blood \n\n"+
        "and..... "+BOLD+" C R U N C H "+NORM+" bites down, piercing your flesh.\n\n");

}

monster_died() {
  tell_room(environment(this_object()),
  "\n\nThe beast slumps to the ground, open-eyed, twitching and you\n"+
  "notice that his left front tooth is loose.  You might be able to\n"+
  "pry it loose if you tried.....\n\n");
  if(this_player())
  move_object(clone_object("players/eurale/Park/OBJ/qst4"),
                this_player());
  else if(attacker_ob) move_object(clone_object("players/eurale/Park/OBJ/qst4"),
 attacker_ob);
  write_file("/players/eurale/Park/LOG/rexquest",
  ctime(time())+"     Rex4     "+query_attack()->query_real_name()+"\n");
return 0; }
