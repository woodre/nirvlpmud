/*  Modified October 2001 to conform to /doc/build/RULES/monster.guide */

#include "/players/eurale/defs.h"
inherit "obj/monster.c";

reset(arg)  {
  ::reset(arg);
  if(arg) return;

set_name("disir");
  /* sentry 2 id wasn't working with room and causing monster overspawning */
  /* - illarion */
set_alias("eurale_sentry_2");
set_alt_name("imperial disir");
set_race("creature");
set_short(BOLD+"Imperial Disir"+NORM);
set_long(
	"This mutant of the Disir race was born with inate fighting \n"+
	"skills.  He wears the hood of the Shaman Elite corps by virtue\n"+
	"of his Oath of Loyaty to the Shaman.  It is said that not only\n"+
	"are these disirs tenacious fighters but their poison is also one\n"+
	"of the most potent known.\n");

set_level(20);
set_hp(750);
set_al(-60);
set_wc(30 + random(10));
if(!present("cape")) {
move_object(clone_object("players/eurale/Keep/OBJ/velvet_cape"),TO); }
init_command("wear cape");
set_ac(17);
set_aggressive(0);
set_dead_ob(this_object());

set_chat_chance(10);
  load_chat("Glowing red eyes glare out from under the hood...\n");
  load_chat("The Disir slowly tenses......\n");
  load_chat("You hear a scream from down below...\n");
  load_chat("Slimy gel drips to the floor...\n");
set_a_chat_chance(20);
  load_a_chat("The Disir dodges your attack....\n");
  load_a_chat("You feel the sting of the Disir's talons....\n");
  load_a_chat("Disir fangs just miss your neck.....\n");

set_chance(14);
set_spell_dam(40);
set_spell_mess1(
  "\nThe Imperial Disir "+HIG+"MAULS"+NORM+" it's target...\n\n");
set_spell_mess2(
  "\nThe Imperial Disir "+HIG+"MAULS"+NORM+" you.....\n\n");

}

heart_beat() {
  ::heart_beat();
  if (query_attack()) {
    /* if(query_attack()->query_attrib("luc") < random(28) changed to account for update stats Forbin 2004-09.26 */
    if(query_attack()->query_attrib("luc") < random(39)
    & !present("toxin",query_attack())) {
      move_object(clone_object("players/eurale/Keep/OBJ/poison.c"),
        query_attack()); 
      if(attacker_ob) tell_object(attacker_ob, 
        "You feel a burning sensation......\n");
       }
  }
}

monster_died() {
move_object(clone_object("players/eurale/Keep/OBJ/disir_slime.c"),
  environment(this_object()));
return 0; }
