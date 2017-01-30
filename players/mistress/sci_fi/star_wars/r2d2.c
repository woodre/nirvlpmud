#include "std.h"
#include "living.h"
object robot,helmet;
 
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
 
ONE_EXIT("players/mistress/sci_fi/star_wars/luke.c","north",
    "R2D2",
    "\n" +
    "This ceiling here is a little low for your comfort.  This seems to\n" +
    "be a cubicle designed for a shorter person - or robot?\n",1)
 
extra_reset()
{
if (!robot || !living(robot) )
{
 
   object armor;
robot = clone_object("obj/monster");
call_other(robot, "set_name", "R2D2");
call_other(robot, "set_ac", 7);
call_other(robot, "set_wc", 12);
call_other(robot, "set_al", 42);
call_other(robot, "set_short", "R2D2");
call_other(robot, "set_alias", "robot");
call_other(robot, "set_long", "A short robot standing a meter high.\n");
call_other(robot, "set_race", "robot");
call_other(robot, "set_alt_name", "r2d2");
call_other(robot, "set_aggressive", 0);
call_other(robot, "add_money", 20);
call_other(robot, "set_level", 8);
move_object(robot, this_object() );
 
armor = clone_object("obj/armor");
call_other(armor, "set_name", "R2D2`s head");
call_other(armor, "set_alias", "head");
call_other(armor, "set_short", "Robot Head");
call_other(armor, "set_long", "The head from R2D2");
call_other(armor, "set_type", "helmet");
call_other(armor, "set_value", 75);
call_other(armor, "set_weight", 1);
call_other(armor, "set_read", "This helmet is actually a head");
call_other(armor, "set_ac", 1);
transfer(armor,robot);
}
}
