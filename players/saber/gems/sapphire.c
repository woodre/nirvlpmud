#define tp this_player()->query_name()
inherit "obj/treasure";
reset(arg)
{   if (arg) return;
   set_id("sapphire");
 set_short("A star sapphire");
  set_long(
 "A translucent blue sapphire with white star highlights.\n"
    );
   set_weight(0);
   set_value(1500);
}
init()
{  add_action("polish_sapphire", "polish");   }
 polish_sapphire(str)
{  if ((!str) || !id(str)) return 0;
  write("You polish the sapphire.\n");
 say(tp+" polishes the sapphire.\n");
    return 1;   }
