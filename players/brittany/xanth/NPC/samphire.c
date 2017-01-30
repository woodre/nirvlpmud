#include "/players/brittany/ansi"
inherit "obj/monster.c";

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name("samphire");
set_alias("samphire");
set_race("monster");
set_short("Samphire");
set_long("A living marshweed with a taste for\n"+
"fresh blood.  It has thorn claws and\n"+
"fangs.  It loves to live in marshy areas.\n");
set_level(8);
set_hp(120);
set_al(-100);
set_wc(12);
set_ac(7);
set_aggressive(0);
set_dead_ob(this_object());

set_chat_chance(6);
  load_chat("The samphire snarls at you, exposing its fangs. \n");
set_a_chat_chance(15);
load_a_chat("The samphire looks in your direction.\n");

set_chance(15);
set_spell_dam(20);

set_spell_mess1(
"Samphire smacks its opponent, with its thorned claws.\n");
set_spell_mess2(
"Samphire smacks you, with its thorned claws.\n");

}

monster_died() {
move_object(clone_object("/players/brittany/xanth/OBJ/thorn.c"),
      this_object());
  tell_room(environment(this_object()),
"The Samphire sinks into the marsh,\n"+
"a thorn falls from its claw.\n");
return 0; }
