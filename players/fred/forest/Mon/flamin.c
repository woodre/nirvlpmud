#include "/players/fred/ansi.h"
inherit "obj/monster.c";
object feather, attacked;
#define attacked (this_object()->query_attack())

reset(arg)  {
  ::reset(arg);
  if(arg) return;

set_name("flamingo");
set_alias("bird");
set_race("creature");
set_short(HIR+"Flamingo"+NORM);
set_long(
  " A pink Flamingo with large flowing feathers.  It\n"+
  "stands next to the beautiful orange pond with it's\n"+
  "short stubby little legs.\n");
 
set_level(10);
set_hp(150);
set_al(-500);
set_ac(8);
set_wc(14);
set_aggressive(0);
set_dead_ob(this_object());
}

monster_died(){
  tell_object(attacked,
  "  A large feather falls to the ground.\n");
  move_object(clone_object("/players/fred/forest/Obj/feather.c"),
     this_object());
}

   



