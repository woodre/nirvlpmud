#include "std.h"
#include "living.h"
object shark;
 
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
 
ONE_EXIT("players/mistress/sci_fi/shark.c","leave",
   "Peter Benchley`s Jaws",
   "\n" +
   "It is getting more and more difficult to see.  That large dorsal fin you\n" +
   "saw a while ago has been joined by LARGER fins interrupting the water`s \n" +
   "surface.  \n",0)
 
extra_reset()
{
if ( !shark || !living(shark) )
{
   object weapon;
shark= clone_object("obj/monster");
call_other(shark, "set_name", "Jaws");
call_other(shark, "set_al", -600);
call_other(shark, "set_ac", 17);
call_other(shark, "set_hp", 500);
call_other(shark, "set_wc", 30);
call_other(shark, "set_short", "Jaws");
call_other(shark, "set_race", "jaws");
call_other(shark, "set_alias", "shark");
call_other(shark, "set_alt_name", "Jaws");
call_other(shark, "set_aggressive",1);
call_other(shark, "set_long", "The great white shark, JAWS, is here.\n");
call_other(shark, "set_level", 19);
call_other(shark,"set_dead_ob",this_object());
 
move_object(shark, this_object() );
weapon = clone_object("obj/weapon");
call_other(weapon, "set_name", "Shark`s tooth");
call_other(weapon, "set_alias", "tooth");
call_other(weapon, "set_long", "A very sharp tooth from the great white, JAWS.\n");
call_other(weapon, "set_class", 20);
call_other(weapon, "set_value", 2000);
call_other(weapon, "set_weight", 5);
call_other(weapon, "set_save_flag", 1);
transfer(weapon, shark);
}
}

monster_died() {
tell_object(this_player(),
  "As the giant shark dies, he regurgitates a small disk.\n");
 move_object(clone_object("players/mistress/other/disk.c"),
  environment(this_player()));
return 0; }
