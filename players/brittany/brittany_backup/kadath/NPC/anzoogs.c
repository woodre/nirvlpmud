#include "/players/brittany/ansi"
inherit "obj/monster.c";

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;


set_name("zoog");
set_alias("ancient");
set_alt_name("guard");
set_race("creature");
set_short("Ancient guard");
set_long("An older zoog, his tail does not seem as sharp\n"+
"as the younger ones.  He guards the huge tree\n"+
"from trespassers.  He looks as though he would\n"+
"be an easy target, but do not let that fool you.\n");

set_level(18);
set_hp(425+random(75));
set_al(-100);
set_wc(26);
set_ac(14);
set_aggressive(0);
set_dead_ob(this_object());
set_chat_chance(6);
load_chat("The guard eyes you suspiciously.\n");
set_a_chat_chance(10);

set_chance(15);
set_spell_dam(30+random(40));

set_spell_mess1(
"The guard emit sharp quills from it's tail, cutting it's opponent deeply.\n");
set_spell_mess2(
"The guard emit sharp quills from its tail, cutting you deeply.\n");
}

monster_died() {
move_object(clone_object("/players/brittany/kadath/OBJ/antail.c"),
     this_object());
  tell_room(environment(this_object()),
"The guard squeals on its last breathe, before hitting the ground.\n");
return 0; }
