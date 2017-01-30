#define tp this_player()->query_name()
#include <ansi.h>
inherit "obj/treasure";
reset(arg)
{   if (arg) return;

set_id("gems");
set_alias("trade_obj");
set_short("A pile of valuable gems");
set_long("A small pile of valuable gems that have fallen from the remains\n"+
         "of the Earth Elemental. The gems themselves have a soft glow\n"+
         "to them, a residue magical effect.\n"+
         "You can <"+HIR+"trade"+NORM+"> them in at the right shop.\n");
set_weight(1);
set_value(1000);
}

query_save_flag() {return 1; }
