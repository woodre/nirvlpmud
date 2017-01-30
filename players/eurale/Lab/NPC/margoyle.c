/*  Changed to new doc/build/RULES/monster.guide 8/12/02 - Eurale  */

#include "/players/eurale/closed/ansi.h"
inherit "obj/monster.c";
#define ETO environment(this_object())

reset(arg)  {
  ::reset(arg);
  if(arg) return;

set_name("margoyle");
set_alias("gargoyle");
set_short();
set_long(
  "This stone skinned margoyle is the most horrid form of gargoyle\n"+
  "experienced to date.  It is a grotesque representation of some\n"+
  "form of dragon. It has small, dull, lifeless eyes, long horns,\n"+
  "taloned claws on both hands and feet and a sharp edged tail.\n"+
  "Sturdy wings with bone spurs at their bending points makes this a\n"+
  "truly deadly predator.\n");

set_race("gargoyle");
set_level(20);
set_hp(500 + random(100));
set_al(-100);
set_wc(30 + random(5));
set_ac(18);
set_aggressive(0);
set_dead_ob(this_object());

set_chat_chance(3);
  load_chat("Your skin prickles as you sense something else in the "+
            "room with you.\n");
  load_chat("Something moves against the back wall.\n");

set_chance(15);
set_spell_dam(random(40));
set_spell_mess1(
  GRY+"The margoyle SWOOPS past it's prey with extended talons.\n"+NORM);
set_spell_mess2(
  GRY+"Intense PAIN as the margoyle SWOOPS past you with extended "+
  "talons.\n"+NORM);

}

monster_died() {
object ob;
ob = present("corpse",ETO);
move_object(clone_object("/players/eurale/Lab/OBJ/talon.c"),ob);
return 0; }
