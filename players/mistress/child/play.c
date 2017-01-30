#include "std.h"
#include "living.h"
object block;

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

FOUR_EXIT("players/mistress/child/zeus.c","north",
           "players/mistress/child/disney","east",
           "players/mistress/child/diap.c","south",
           "players/mistress/child/child.c","west",
     "Play area",
     "\n" +
     "Building block and child-sized furniture is scattered in a \n" +
     "haphazard circle... obviously children like to play here.  An\n" +
     "unwelcome stench permeates from the south. <What is all the worlds\n" +
     "could cause that?>\n",1)


extra_reset()
{
if (!block || !living(block) )
{

block = clone_object("obj/monster");
call_other(block, "set_name", "Building block");
call_other(block, "set_ac", 4);
call_other(block, "set_wc", 7);
call_other(block, "set_al", -189);
call_other(block, "set_short", "Building block");
call_other(block, "set_alias", "block");
call_other(block, "set_long", "For some reason this block looks alive.\n");
call_other(block, "set_race", "building");
call_other(block, "set_alt_name", "building block");
call_other(block, "set_aggressive", 0);
call_other(block, "add_money", 100);
call_other(block, "set_level", 3);
move_object(block, this_object() );

}
}
