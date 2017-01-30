#include "/players/dusan/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name("skeleton");
set_alias("skeleton");
set_alt_name("skeleton");
set_race("skeleton");
set_short("A human skeleton");
set_long(
  "The animated bones of a long dead human.  It looks like something\n"+
  "has been chewing on its yellowed bones.  It turns its hollow sockets \n"+
  "towards you then moves your way!! \n");

set_level(14);
set_hp(200+random(75));
set_al(-300);
set_wc(19);
set_ac(12);
set_heal(2,20);
set_aggressive(0);
set_dead_ob(this_object());

set_chat_chance(15);
  load_chat("The skeleton lets out a hollow moan. \n");
  load_chat("The skeleton shuffles around.\n");
set_a_chat_chance(15);
  load_a_chat("The skeleton grasps you with dead hands! \n");
  load_a_chat("Bone hands rake your face drawing blood. \n");
set_chance(10);
set_spell_dam(random(20));

set_spell_mess1(
  "The skeleton rakes your face with fingers of bone.\n");
set_spell_mess2(
  " \n");
}

monster_died() {
 object corpse;  
 corpse = present("corpse",environment());
 move_object(clone_object("/players/dusan/area1/items/pieces.c"),
       environment(this_object()));
  tell_room(environment(this_object()),
   "With a mighty blow you shatter the skeleton.\n");
  if(corpse)
    destruct(corpse);
return 1; }
