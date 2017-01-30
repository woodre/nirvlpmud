#include "/players/eurale/closed/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
object helm;
  ::reset(arg);
  if(arg) return;

set_name("thing");
set_alias("the thing");
set_race("creature");
set_short("The Thing");
set_long(
	"  This 4 foot tall monstrosity has blue hair and green blood.\n"+
	"Instead of arms, it has tentacles like an octopus.  Three \n"+
	"angry red eyes glow in it's face.  The Thing first appeared\n"+
	"in a 1938 short story called 'Who Goes There' by Don Stuart.\n"+
	"In this story, scientists in Antarctica discover a monster\n"+
	"from another planet buried beneath the ice.\n");

set_level(20);
  set_hp(500);
  set_al(0);
helm = clone_object("players/eurale/Fiend/OBJ/skull_helm.c");
move_object(helm,this_object());
init_command("wear skull");
  set_wc(30);
  set_ac(15);
  set_heal(4,5);
  set_aggressive(1);

}
