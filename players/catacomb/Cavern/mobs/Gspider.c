#include "/players/catacomb/misc/ansi.h"
inherit "obj/monster.c";
#define ATTACKED (this_object()->query_attack())


reset(arg)  {
  ::reset(arg);
  if(arg) return;

set_name("spider");
set_race("creature");
set_short("A giant spider");
set_long(
  "  A large spider standing at least six feet tall stands before\n"+
  "you.  Blood drips off of its razor-sharp fangs.  Its many eyes\n"+
  "look for its next meal.\n");
 
set_level(16);
set_hp(300);
set_al(0);
set_ac(13);
set_wc(22);
set_dead_ob(this_object());
set_aggressive(1);
set_chance(5);
set_spell_dam(15);
set_spell_mess1(
  "The spider sinks it's razor sharp fangs into it's foe.\n");
set_spell_mess2(
  "The spider sinks it's fang deep into your arm, "+RED+"blood"+NORM+" spurts forth.\n");
}
 
monster_died(){
  object fang;
  tell_object(ATTACKED,
    "As the spider falls it's fang breaks off.\n");
  fang = clone_object("/players/catacomb/Cavern/items/Sdagger.c");
  move_object(fang, this_object());
}   