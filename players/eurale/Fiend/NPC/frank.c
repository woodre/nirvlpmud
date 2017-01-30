/* Updated monster's level and wc,ac and added spells to
strengthen by Pestilence per Dragnar 8-9-2014 */
#include "/players/eurale/closed/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
  ::reset(arg);
  if(arg) return;

if(!present("electrodes")) {
move_object(clone_object("players/eurale/Fiend/OBJ/electrodes"),
  this_object()); }
set_name(GRN+"Frankenstein"+NORM);
set_alias("frank");
set_alt_name("frankenstein");
set_race("creature");
set_short(GRN+"Frankenstein"+NORM);
set_long(
	"  Created in 1931 and played by a struggling actor by the name\n"+
	"of Boris Karloff.  This 'abomination' was put together by Dr.\n"+
	"Frankenstein from body parts taken from dead people.  Every\n"+
	"morning they would apply blue-green grease paint to Karloff's\n"+
	"face, put putty on his eyelids, paint his fingernails with black\n"+
	"shoe polish and fit him with a spinal brace.  The costume for\n"+
	"this early monster weighed more than 48 pounds.\n");

  set_level(23);
  set_hp(850);
  set_al(0);
  set_wc(40);
/*
  set_wc_bonus(24);
*/
  set_ac(40);
  set_heal(15,5);
  set_aggressive(0);
  set_dead_ob(this_object());

set_chat_chance(15);
  load_chat("You rang? asks Frankenstein\n");
  load_chat("Why do you disturb us? inquires Frankenstein\n");
set_a_chat_chance(15);
  load_a_chat("Frankenstein grabs at you with a meaty fist..\n");
  load_a_chat("Frankenstein bites at you with yellow teeth...\n");

add_spell("pound",
  "\n\nFrankenstein "+BOLD+" P O U N D S "+NORM+" you...\n\n"+
  "and then he "+BOLD+" P O U N D S "+NORM+" you again..\n\n",
  "\n\nFrankenstein "+BOLD+" P O U N D S  "+NORM+"his assailant...\n\n",
25,"30-45",0,0);

add_spell("stomp",
"#RET#$G$                                         .....$N$\n"+
"$G$                                        C C  /$N$\n"+
"$G$                                       /<   /$N$\n"+
"$G$                        ___ __________/_#__=o$N$\n"+
"$G$                       /(- /(\\_\\________   \\$N$\n"+
"$G$                       \\ ) \\ )_      \o     \\$N$\n"+
"$G$                       /|\\ /|\\       |'     |$N$\n"+
"$G$                                     |     _|$N$\n"+
"$G$                                     /o   __\\$N$\n"+
"$G$                                    / '     |$N$\n"+
"$G$                                   / /      |$N$\n"+
"$G$                                  /_/\______|$N$\n"+
"$G$                                 (   _(    <$N$\n"+
"$G$                                  \\    \\    \\$N$\n"+
"$G$                                   \\    \\    |$N$\n"+
"$G$                                    \\____\\____\\$N$\n"+
"$G$                                  ____\\_\\__\\_\\$N$\n"+
"$G$                                 /`   /`     o\$N$\n"+
"$G$                                 |___ |_______|$N$\n",
"#MN# begins to stomp on #TN$.\n",
30,"40-60",0,3);

/*
set_chance(25);
set_spell_dam(30 + random(15));

set_spell_mess1(
  "\n\nFrankenstein "+BOLD+" P O U N D S  "+NORM+"his assailant...\n\n");
set_spell_mess2(
  "\n\nFrankenstein "+BOLD+" P O U N D S "+NORM+" you...\n\n"+
  "and then he "+BOLD+" P O U N D S "+NORM+" you again..\n\n");
*/

}

monster_died() {
  tell_room(environment(this_object()),
  "\n\n"+
  "With a "+BOLD+"THUD!!"+NORM+" Frankensteins hits the floor..\n\n");
return 0; }
