#include "/players/fred/ansi.h"
inherit "obj/monster.c";
object sack, attacked;
#define attacked (this_object()->query_attack())

reset(arg)  {
  ::reset(arg);
  if(arg) return;

set_name("kid");
set_alias("child"); 
set_race("human");
set_short("Village Kid");
set_long(
  "  A small freckle faced kid from the village that can\n"+ 
  "be found running around the village causing trouble.\n"); 
 
set_level(9);
set_hp(135);
set_al(500);
set_ac(7);
set_wc(13);
set_aggressive(0);
set_dead_ob(this_object());
set_a_chat_chance(5);
  load_a_chat("The small child starts crying: I want my mommy!\n");
  load_a_chat("The kid says, You're mean.\n");
}

monster_died(){
  tell_object(attacked,
  " A small sack drops from the childs grasp.\n");
  sack = clone_object("/players/fred/forest/Obj/sack.c");
  move_object(sack, this_object());
  }
 

   

 


