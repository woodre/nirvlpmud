#define tp this_player()->query_name()
inherit "obj/treasure";
reset(arg)
{   if (arg) return;
   set_id("coffin");
   set_short("A sleek black coffin");
  set_long(
 "A beautiful sleek black coffin.\n");
   set_weight(7);
   set_value(1000);
}
init()
{ add_action("open_coffin", "open");   }
open_coffin(str)
{  if ((!str) || !id(str)) return 0;
write("You open the coffin.\n");
say(tp+" opens the coffin.\n");
    return 1;   }
