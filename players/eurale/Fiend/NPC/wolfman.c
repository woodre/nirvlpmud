#include "/players/eurale/closed/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
  ::reset(arg);
  if(arg) return;

set_name("wolf man");
set_alias("wolf");
set_alt_name("man");
set_race("creature");
set_short("Wolf Man");
set_long(
	"  The Wolf Man is a tragic character, a man who turns into a \n"+
	"monster through no fault of his own.  Originally played by \n"+
	"a man named Creighton Chaney who later changed his name to\n"+
	"Lon Chaney, Jr.  The movie The Wolf Man was made in 1941 with\n"+
	"Chaney having yak hair glued to his body to make him look more\n"+
	"animal like.....\n\n"+
	"		'Even a man who is pure of heart\n"+
	"		and says his prayers by night\n"+
	"		may become a wolf when the wolfsbane blooms\n"+
	"		and the autumn moon is bright.'\n");

set_level(20);
  set_hp(600);
  set_al(-300);
  set_wc(34);
  set_ac(15);
  set_aggressive(1);
  set_dead_ob(this_object());

set_a_chat_chance(15);
  load_a_chat("\n\nWolf Man SNAPS at your neck.....\n\n");
  load_a_chat("Wolf Man HOWLS into the darkness...\n");

set_chance(14);
set_spell_dam(40);

set_spell_mess1(
  "\n\nWith glazed eys... the beast bites.....\n\n");
set_spell_mess2(
  "\n\nWith glazed eyes... the beast BITES you....\n\n");

}

monster_died() {
  tell_room(environment(this_object()),
  "\n\nThe beast crashes to the ground.......\n\n"+
  "the animal hair slowly retracts and disappears...\n\n"+
  "and with a final 'sigh'..... expires..\n\n");
  move_object(clone_object("players/eurale/Fiend/OBJ/wolfsbane.c"),
    environment(this_object()));
return 0; }
