#include "/players/eurale/closed/ansi.h"
inherit "obj/monster.c";
#define ETO environment(this_object())
#define TO this_object()

reset(arg)  {
  ::reset(arg);
  if(arg) return;

set_name("troglodyte");
set_short(GRY+"Troglodyte"+NORM);
set_long(
  "This carnivorous reptilian humanoid stands nearly 6 feet tall. It\n"+
  "is covered in rough leathery scales and has a toothy lizard-like\n"+
  "head.  There is a fin-like crest that runs across its head and\n"+
  "down it's back.\n");

set_race("creature");
set_level(20);
set_hp(500);
set_al(-25);
move_object(clone_object("/players/eurale/Lab/OBJ/dart.c"),TO);
init_command("wield dart");
set_wc(30);
set_ac(15);
set_aggressive(0);
set_dead_ob(this_object());

set_chat_chance(3);
  load_chat("The troglodyte slowly circles you...\n");

set_chance(8);
set_spell_dam(random(35));
set_spell_mess1(
  GRY+"The troglodyte JUMPS on its attacker and BITES.\n"+NORM);
set_spell_mess2(
  GRY+"The troglodyte JUMPS on you BITES your exposed arm.\n"+NORM);

}

monster_died() {
object ob;
ob = present("corpse",ETO);
move_object(clone_object("/players/eurale/Lab/OBJ/scale.c"),ob);
return 0; }
