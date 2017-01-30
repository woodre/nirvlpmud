#include "/players/eurale/closed/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
  ::reset(arg);
  if(arg) return;

set_name("hickory tree");
set_alias("tree");
set_race("creature");
set_short();
set_long(
  "This large, menacing tree has gnarly branches.  Its bark is old and\n"+
  "and cracked from much weathering.\n");

set_level(15);
  set_hp(650);
  set_al(0);
  set_wc(20);
  set_ac(12);
  set_aggressive(0);
  set_dead_ob(this_object());

set_chat_chance(6);
  load_chat("A songbird sings off in the distance.\n");
  load_chat("The wind 'sighs' as it passes through the leaves.\n");

set_chance(16);
set_spell_dam(30);

set_spell_mess1(
  "The tree clubs its target with a gnarly branch...\n");
set_spell_mess2(
  "The tree clubs you with a gnarly branch...\n");

}

monster_died() {
move_object(clone_object("players/eurale/Glade/OBJ/nut.c"),
	environment(this_object()));
move_object(clone_object("players/eurale/Glade/OBJ/nut.c"),
      environment(this_object()));
return 0; }
