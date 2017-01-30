#include "/players/eurale/closed/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name("rock crusher");
set_alias("crusher");
set_race("creature");
set_short("Rock Crusher");
set_long(
  "This strange creature looks like some kind of abomination.  It has\n"+
  "the look of stones put together to form a humanoid, and bulging\n"+
  "muscles to move its incredible weight around with such eash.  It\n"+
  "has immense hands with short, thick nails protruding from its\n"+
  "stubby fingers.  It is hairless and has slits for eyes with no\n"+
  "visible pupils.\n");

set_level(21);
  set_hp(650);
  set_al(0);
if(!present("boulder boots")) {
move_object(clone_object("players/eurale/Glade/OBJ/boulder_boots.c"),
  this_object()); }
init_command("wear boots");
  set_wc(50);
  set_ac(17);
  set_aggressive(1);

}
