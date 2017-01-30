#define tp this_player()->query_name()
inherit "obj/treasure";
reset(arg)
{   if (arg) return;
   set_id("opal");
 set_short("A fire opal");
  set_long(
 "A fiery red opal of unusual beauty.\n"
    );
   set_weight(0);
   set_value(1000);
}
init()
{  add_action("polish_opal", "polish");   }
 polish_opal(str)
{  if ((!str) || !id(str)) return 0;
  write("You polish the opal.\n");
 say(tp+" polishes the opal.\n");
    return 1;   }
