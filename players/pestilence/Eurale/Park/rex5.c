/*  Tyrannosaurus Rex  */
/* Updated monster's level and wc,ac and added spells to
strengthen by Pestilence per Dragnar 8-9-2014 */

#define TP this_player()
#include "/players/eurale/closed/ansi.h"
inherit "obj/monster.c";

reset(arg) {

::reset(arg);
if(arg) return;
set_name(HIW+"Tyrannosaurus Rex"+NORM);
set_race("dinosaur");
set_alt_name("rex");
set_short(HIW+"Tyrannosaurus Rex"+NORM);
set_alias("tyrannosaurus");
set_long(
   "  This fierce, meat-eating reptile grew to over 50 feet in length \n"+
 "and stood over 30 feet tall.  It's jaws were nearly 5 feet in \n"+
 "length and contained 8 inch long curved teeth.  It is the "+HIW+"largest\n"+NORM+
	"and most feared meat eater that ever lived. \n");
set_level(23);
set_hp(750+ random (100));
set_al(-1);
set_ac(26);
set_aggressive(1);
set_dead_ob(this_object());
set_heal(25,3);
set_wc(48);
/*
set_wc_bonus(18);
*/


set_chat_chance(5);
  load_chat("You shake at the sound of its primeval roar... \n");
set_a_chat_chance(8);
  load_a_chat("\n\nRex SNARLES and LUNGES at you..\n\n");


set_chance(11);
set_spell_dam(37 + random(20));
  set_spell_mess1(
	"\n\nThe mighty Rex takes a fearsome bite of its prey.. \n\n");
  set_spell_mess2(
	"\nThe mighty Rex opens its jaws, fangs dripping with blood \n\n"+
        "and..... "+BOLD+" C R U N C H "+NORM+" bites down, piercing your flesh.\n\n");

add_spell("chomp",
"#MN# $HW$C H O M P S$N$ into your skin, tearing $HR$flesh$N$ from the $HW$bone$N$.#RET#$HR$Blood$N$ flows rapidly from your wound.\n",
"#MN# $HW$C H O M P S$N$ into #TN#'s skin, tearing $HR$flesh$N$ from the $HW$bone$N$.#RET#$HR$Blood$N$ flows rapidly from #TN#'s wound.\n",
25,"30-120",0,0);

}

monster_died() {
  tell_room(environment(this_object()),
  "\n\nThe beast slumps to the ground, open-eyed, twitching.. \n\n");
  move_object(clone_object("players/eurale/Park/OBJ/tooth"),
    environment(this_object()));
  move_object(clone_object("players/eurale/Park/OBJ/tooth"),
    environment(this_object()));
  move_object(clone_object("players/eurale/Park/OBJ/qst5"),TP);
  write_file("/players/eurale/Park/LOG/rexquest",
  ctime(time())+"     Rex5     "+query_attack()->query_real_name()+"\n");
return 0; }
