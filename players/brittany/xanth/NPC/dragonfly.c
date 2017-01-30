#include "/players/brittany/ansi"
inherit "obj/monster.c";

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name("dragon");
set_alias("dragon");
set_alt_name("dragonfly");
set_race("monster");
set_short("Dragonfly");
set_long("This is a miniature insectoid dragon.  It\n"+
"preys on bugs and associate with dragons.  They\n"+
"live mostly around the trees to keep them free of\n"+
"pests.  They breathe fire and explode in flames\n"+
"when they crash.\n");
set_level(5);
set_hp(75);
set_al(-100);
set_wc(9);
set_ac(5);
set_aggressive(0);
set_dead_ob(this_object());

set_chat_chance(10);
  load_chat("The fly looks at you. \n");
set_a_chat_chance(25);
load_a_chat("The fly wisps by.\n");

set_chance(25);
set_spell_dam(10);

set_spell_mess1(
"Fly breathes fire at its opponent.\n");
set_spell_mess2(
"Fly breathes fire at you.\n");

}

monster_died() {
move_object(clone_object("/players/brittany/xanth/OBJ/gem.c"),
      this_object());
  tell_room(environment(this_object()),
"The fly crashes into the tree and explodes,\n"+
"a gem falls to the ground.\n");
return 0; }
