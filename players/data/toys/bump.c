#include "/players/data/ansi.h"

inherit "obj/treasure";
 reset(arg)
{   if (arg) return;
   set_id("bump");
   set_short();
   set_long();
   call_out("bye", 500);
}
 bye()  {
  destruct(this_object());
        }
 extra_look()  {
object ex_look;
  ex_look = environment(this_object())->query_name();
  write(ex_look+" got bonked on the head by Data's" +GRN+" Pimp Stick"+NORM+".\n");
        }
 drop()  { return 1; }
