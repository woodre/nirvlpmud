#include "/players/brittany/ansi"
inherit "obj/monster.c";

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name("dragon");
set_alias("dragon");
set_race("monster");
set_short("Dragonlady");
set_long("This is the leader of the dragons.  Her\n"+
"tail is blue and barbed and she has a\n"+
"bright red neck.  Her eyes are ruby red\n"+
"and her fangs are sharp and long.  She\n"+
"looks like a very tough opponent.\n");
set_level(12);
set_hp(180);
set_al(-100);
set_wc(16);
set_ac(9);
set_aggressive(0);
set_dead_ob(this_object());

set_chat_chance(6);
  load_chat("The dragon hisses at you. \n");
set_a_chat_chance(15);
load_a_chat("The dragon speaks:  Why have you disturbed me?\n");

set_chance(15);
set_spell_dam(20);

set_spell_mess1(
"Dragon spits fire at its opponent.\n");
set_spell_mess2(
"Dragon spits fire at you.\n");

}

monster_died() {
move_object(clone_object("/players/brittany/xanth/OBJ/diamond.c"),
      this_object());
  tell_room(environment(this_object()),
"The dragon crashes to the ground and dies.\n");
return 0; }
