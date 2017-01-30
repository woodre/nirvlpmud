#include "/players/eurale/closed/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
  ::reset(arg);
  if(arg) return;

set_name("red ant");
set_alias("ant");
set_alt_name("mutant");
set_race("creature");
set_short(HIR+"Red Ant Mutant"+NORM);
set_long(
  "You stare upon the largest and reddest ant you have ever seen.  It\n"+
  "is at least 5 feet in length and it's smooth hard body looks like\n"+
  "some sort of shell.  Large, jagged mandibles protrude from under\n"+
  "its head.\n");

set_level(18);
  set_hp(450);
  set_al(0);
  set_wc(26);
  set_ac(16);
  set_aggressive(1);
  set_dead_ob(this_object());

set_a_chat_chance(15);
  load_a_chat("The ant's giant mandibles just miss your leg...\n");
  load_a_chat("You strike the ant's hard exterior causing NO damage...\n");
  load_a_chat("PAIN.... as the ant nips you.....\n");

}

monster_died() {
  move_object(clone_object("players/eurale/Glade/OBJ/larvae.c"),
      environment(this_object()));
  tell_room(environment(this_object()),
  "You STRIKE the ant squarely between the eyes and it dies.....\n\n");
return 0; }
