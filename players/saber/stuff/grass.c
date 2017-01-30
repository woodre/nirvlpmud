#define tp this_player()->query_name()
inherit "obj/treasure";
reset(arg)
{   if (arg) return;
   set_id("joint");
    set_short("A joint");
    set_long("A 'joint' of grass that you can 'smoke'.\n");
   set_weight(1);
   set_value(10);
}
init()
{  add_action("smoke_joint", "smoke");   }
smoke_joint(str)
{  if ((!str) || !id(str)) return 0;
   write("You take a deep hit off of the joint.\n"+
       "Woah!\n");
     say(tp+" takes a hit off of a joint.\n");
    return 1;   }
