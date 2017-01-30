#define tp this_player()->query_name()
inherit "obj/treasure";
reset(arg)
{   if (arg) return;
   set_id("bed");
   set_short("A large, comfortable looking bed");
  set_long(
 "A large, comfortable looking king sized bed, complete with\n"+
 "a black spread and several black, satin pillows.\n"+
 "You think you could 'lie' on the bed.\n"
    );
   set_weight(20);
   set_value(100);
}
init()
{  add_action("lie_bed", "lie");   }
lie_bed(str)
{  if ((!str) || !id(str)) return 0;
 write("You lie down upon what turns out to be a VERY comfortable bed.\n"+
   "Yummmmmmm\n");
say(tp+" lies down upon the bed.\n");
    return 1;   }
