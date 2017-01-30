#define tp this_player()->query_name()
inherit "obj/treasure";
reset(arg)
{   if (arg) return;
   set_id("pearl");
 set_short("A pearl");
  set_long(
 "A pure black pearl of unusual beauty.\n"
    );
   set_weight(0);
   set_value(500);
}
init()
{  add_action("polish_pearl", "polish");   }
 polish_pearl(str)
{  if ((!str) || !id(str)) return 0;
  write("You polish the pearl.\n");
 say(tp+" polishes the pearl.\n");
    return 1;   }
