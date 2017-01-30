#include "/players/fakir/color.h"
inherit "obj/monster.c";

reset(arg)  {
  ::reset(arg);
  if(arg) return;
add_money(2000);
set_name("trapper");
set_race("human");
set_short("Trapper");
set_long(
  "Dressed in oddly stitched hides of various animals, the trapper\n"+
  "looks a bit like one himself.  A full beard covers his lower face\n"+
  "and hides his mouth from view.  One ear is missing the lower half,\n"+
  "and a long scar runs from there up his temple and across his lined\n"+
  "forehead.  He wears a bearclaw necklace and a broad snakeskin belt.\n"+
  "A huge hunting knife hangs in a sheath from the belt.\n");

set_level(17);
set_hp(470);
set_al(-500);
set_wc(30);
set_ac(15);
set_aggressive(0);
set_dead_ob(this_object());

set_chat_chance(10);
  load_chat("Trapper says: 'I have some good pelts here to barter' \n");
set_chat_chance(10);
  load_chat("The trapper fingers his bearclaw necklace and strokes his beard\n");
set_a_chat_chance(15);
  load_a_chat("Tapper says: 'I've killed skunks tougher than you' \n");

set_chance(10);
set_spell_dam(20);

set_spell_mess1(
  "The trapper whips out his knife and slashes his attacker on the arm\n");
set_spell_mess2(
  "The trapper whips out his knife and slashes your arm to the bone\n");


}

monster_died() {
  
  tell_room(environment(this_object()),
	"The trapper twitches once and falls dead on his face.\n");
return 0; }
