#define tp this_player()->query_name()
#include <ansi.h>
inherit "obj/treasure";
reset(arg)
{   if (arg) return;

   set_id("rubble");
   set_alias("earth rubble");
set_short("A large pile of stone rubble");
set_long("A large pile of rock and stone, this might have been some\n"+
         "sort of construct at one point. Maybe an elemental of\n"+
         "some unknown type.\n");
   set_weight(9999);
   set_value(1);
}

init()  {
  ::init();
        }

get()  { return 0; }
