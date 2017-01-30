inherit "obj/treasure";
#include "/players/saber/closed/ansi.h"

reset(arg)
{   if (arg) return;
   set_id("smear");
   set_short();
   set_long();
   call_out("bye", 500);
}

bye()  {
  destruct(this_object());
        }

extra_look()  {
object ex_look;
string colors;
  ex_look = environment(this_object())->query_name();
  colors = HIG+"S"+HIY+"M"+HIB+"E"+HIR+"A"+HIM+"R"+NORM;
  write(ex_look+" is covered with a "+colors+" of paintball paint.\n");
        }

drop()  { return 1; }
