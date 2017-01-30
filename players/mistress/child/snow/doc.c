#include "std.h"
#include "living.h"
object doc;

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

ONE_EXIT("players/mistress/child/snow/sleepy.c","east",
    "Doc",
    "\nThe small path you have been following ends abruptly.  However,  it\n" +
    "looks like this spot has been used quite often for something.  Not sure\n" +
    "what though.\n",1)

extra_reset()
{
if (!doc || !living(doc) )
{

doc = clone_object("obj/monster");
call_other(doc, "set_name", "Doc");
call_other(doc, "set_ac", 7);
call_other(doc, "set_wc", 10);
call_other(doc, "set_hp", 140);
call_other(doc, "set_al", -100);
call_other(doc, "set_short", "Doc");
call_other(doc, "set_alias", "dwarf");
call_other(doc, "set_long", "Doc is pretty much the head honcho around here.\n");
call_other(doc, "set_alt_name", "doc");
call_other(doc, "set_aggressive", 0);
call_other(doc, "add_money", 350);
call_other(doc, "set_level", 8);
move_object(doc, this_object() );

}
}
