#define tp this_player()->query_name()
inherit "obj/treasure";
reset(arg)
{   if (arg) return;
   set_id("gem");
 set_short("A moonstone gem");
  set_long(
 "A white gem with a pale blue hue.\n"
    );
   set_weight(0);
   set_value(50);
}
init()
{  add_action("polish_gem", "polish");   }
 polish_gem(str)
{  if ((!str) || !id(str)) return 0;
  write("You polish the gem.\n");
 say(tp+" polishes the gem.\n");
    return 1;   }
