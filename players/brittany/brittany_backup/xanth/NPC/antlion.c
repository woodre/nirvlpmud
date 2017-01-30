#include "/players/brittany/ansi"
inherit "obj/monster.c";

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name("antlion");
set_alias("ant");
set_alt_name("lion");
set_race("creature");
set_short("Antlion");
set_long("A small beast with the body of an ant\n"+
"and a manned head of a lion.  It is a powerful\n"+
"fighter, and make good use of it's sharp-pointed\n"+
"legs.  It has a stong jaw and stingers at the end\n"+
"of a sharp abdomen.\n");
set_level(5);
set_hp(75);
set_al(-100);
set_wc(9);
set_ac(5);
set_aggressive(0);
set_dead_ob(this_object());

set_chat_chance(10);
  load_chat("The lion looks at you. \n");
set_a_chat_chance(25);
load_a_chat("The lion crawls closer.\n");

set_chance(25);
set_spell_dam(10);

set_spell_mess1(
"The lion stings it's opponent with one of its stingers.\n");
set_spell_mess2(
"The lion stings you with one of it's stingers.\n");

}

monster_died() {
move_object(clone_object("/players/brittany/xanth/OBJ/stinger.c"),
      this_object());
  tell_room(environment(this_object()),
"The lion collapses, a stinger breaks and falls to the ground.\n");
return 0; }
