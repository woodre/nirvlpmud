#include "/players/eurale/closed/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
object ring;
  ::reset(arg);
  if(arg) return;

set_name("gremlin");
set_alias("stripe");
set_race("creature");
set_short("Stripe");
set_long(
	"  This two-foot high furry creature came from the Mogwai.  It\n"+
	"is a sinister looking little animal with long sharp teeth and\n"+
	"pointed ears.  It's glowing eyes allow it to see well in the\n"+
	"darkness.  This particular gremlin has stripes running down his\n"+
	"back and is, by far, the meanest gremlin of all.\n");

set_level(20);
  set_hp(595);
  set_al(-400);
ring = clone_object("players/eurale/Fiend/OBJ/catseye_ring.c");
move_object(ring,this_object());
init_command("wear ring");
  set_wc(30);
  set_ac(17);
  set_aggressive(1);

set_chat_chance(15);
  load_chat("The Gremlin chatters......\n");
set_a_chat_chance(15);
  load_a_chat("Stripe makes a nasty scratch across your hand...\n");
  load_a_chat("You feel the pain of sharp teeth as Stripe bites you..\n");
  load_a_chat("Spit hits you in the face.....\n");
  load_a_chat("Spike laughs demonically....\n");

}
