#include "std.h"
#include "living.h"
object child;

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

FOUR_EXIT("players/mistress/child/beast.c","north",
          "players/mistress/child/black.c","south",
          "players/mistress/child/play.c","east",
          "players/mistress/child/rhyme.c","west",
    "Children`s Books",
    "\n" +
    "The books here look like they are meant for older children... those\n" +
    "that can read for themselves at any rate.\n",1)

extra_reset()
{
if (!child || !living(child) )
{

child = clone_object("obj/monster");
call_other(child, "set_name", "Unruly child");
call_other(child, "set_ac", 3);
call_other(child, "set_wc", 5);
call_other(child, "set_hp", 100);
call_other(child, "set_al", -30);
call_other(child, "set_short", "Unruly child");
call_other(child, "set_alias", "child");
call_other(child, "set_long", "The child is kicking and screaming like a banshee.\n");
call_other(child, "set_race", "child");
call_other(child, "set_aggressive", 0);
call_other(child, "add_money", 50);
call_other(child, "set_whimpy", 1);
call_other(child, "set_chat_chance", 60);
call_other(child, "load_chat", "The child looks at you and says, ~You're ugly!~\n");
call_other(child, "load_chat", "~Are you going to hit me?  Huh?  Are you?~\n");
call_other(child, "load_chat", "~Mommy told me never talk to strangers... YOU certainly are strange to me!~\n");
call_other(child, "load_chat", "The child sticks his tongue out at you. \n");
call_other(child, "set_level", 3);
move_object(child, this_object() );

}
}
