#include "/players/fakir/color.h"
inherit "obj/monster.c";

reset(arg)  {
  ::reset(arg);
  if(arg) return;

set_name("whitecloak");
set_alias("guard");
set_race("human");
set_short(WHITE+"Whitecloak"+OFF);
set_long(
  "   Clothed in the traditional full-flowing cloak of pure white with\n"+
"a yellow sunburst emblazed upon it, the guard stands and stares as if\n"+
"you do not even exist.  His eyes seem focused on something far in the\n"+
"distance.  He firmly holds a long-pike in the crook of his left arm.\n");

set_level(17);
set_hp(350);
set_al(-500);
set_wc(24);
set_ac(12 +random(4));
set_aggressive(0);
set_dead_ob(this_object());

set_chat_chance(5);
  load_chat("The "+WHITE+"whitecloak"+OFF+" does not seem to even notice your presence.\n");
  load_chat("A pair of black crows fly overhead, watching you closely.\n");
set_a_chat_chance(15);
  load_a_chat("The "+WHITE+"whitecloak"+OFF+" smashes a fist in your chest.\n");
  load_a_chat("Backing up a bit, the "+WHITE+"whitecloak"+OFF+" stabs with his pike.\n");

set_chance(10);
set_spell_dam(15);

set_spell_mess1(
  "The "+WHITE+"whitecloak"+OFF+" smashes you on the head with his pike.\n");
set_spell_mess2(
  "Ducking slightly, the "+WHITE+"whitecloak"+OFF+" slashes you with a hidden dagger.\n");

}

monster_died() {
  move_object(clone_object("/players/fakir/fcastle/WEP/pike.c"),
      environment(this_object()));
  tell_room(environment(this_object()),
	"The "+WHITE+"whitecloak"+OFF+" screams and falls dead in his "+RED+"blood"+OFF+" soaked garments.\n");
return 0; }
