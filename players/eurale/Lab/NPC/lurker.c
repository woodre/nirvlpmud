/*  Changed to new doc/build/RULES/monster.guide 8/12/02 - Eurale  */

#include "/players/eurale/closed/ansi.h"
inherit "obj/monster.c";
#define ETO environment(this_object())

reset(arg)  {
  ::reset(arg);
  if(arg) return;

set_name("lurker");
set_short(GRY+"Lurker"+NORM);
set_long(
  "This carnivorous scavenger resembles a large manta ray.  Its gray\n"+
  "belly is textured like stone. It has a large mouth with canine\n"+
  "fangs and usually attaches itself to ceilings where it is difficult\n"+
  "to detect.\n");

set_race("creature");
set_level(18);
set_hp(400 + random(50));
set_al(0);
set_wc(28);
set_ac(15);
set_aggressive(1);
set_dead_ob(this_object());

set_chat_chance(3);
  load_chat("A drop of water falls from the ceiling.... sploop.\n");

}

monster_died() {
object ob;
ob = present("corpse",ETO);
move_object(clone_object("/players/eurale/Lab/OBJ/lurk_skin.c"),ob);
return 0; }
