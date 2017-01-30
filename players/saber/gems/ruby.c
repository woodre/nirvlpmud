#define tp this_player()->query_name()
inherit "obj/treasure";
reset(arg)
{   if (arg) return;
   set_id("ruby");
 set_short("A star ruby");
  set_long(
 "A translucent ruby with white star highlights.\n"
    );
   set_weight(0);
   set_value(1000);
}
init()
{  add_action("polish_ruby", "polish");   }
 polish_ruby(str)
{  if ((!str) || !id(str)) return 0;
  write("You polish the ruby.\n");
 say(tp+" polishes the ruby.\n");
    return 1;   }
quest_ob()  { return 1; }
