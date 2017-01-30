#include "/players/eurale/closed/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
object collar;
  ::reset(arg);
  if(arg) return;

set_name("werewolf");
set_alias("wolf");
set_race("creature");
set_short("Werewolf");
set_long(
	"  This creature is half man, half creature.  When the moon is\n"+
	"full and the wolfsbane is in bloom, they come in search of prey.\n"+
	"This part of Fiendsville is notorius for having such creatures\n"+
	"lurking in the shadows.\n");

set_level(19);
  set_hp(475);
  set_al(0);
collar = clone_object("players/eurale/Fiend/OBJ/spiked_collar.c");
move_object(collar,this_object());
init_command("wear collar");
  set_wc(28);
  set_ac(16);
  set_aggressive(1);

set_chat_chance(15);
  load_chat("The werewolf's eyes shine out of the darkness...\n");
  load_chat("The werewolf growls.....\n");
set_a_chat_chance(15);
  load_a_chat("\n\nThe werewolf bites you on the leg...\n\n");
  load_a_chat("Steel jaws clamp down on your arm....\n");

}
