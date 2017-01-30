#define tp this_player()->query_name()
inherit "obj/treasure";
reset(arg)
{   if (arg) return;
   set_id("microphone");
  set_short("A microphone");
  set_long(
     "A microphone which you could hook into a P.A. sysyem.\n");
   set_weight(0);
   set_value(50);
}
