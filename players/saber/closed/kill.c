#define  tp this_player()->query_name()
inherit "obj/treasure";
reset(arg)
{   if (arg) return;
   set_id("rag");
    set_short("A large rag");
    set_long("A large rag used for wiping objects.\n");
   set_weight(1);
   set_value(10);
}
init()
{  add_action("wipe");  }
wipe(str)
{
write("You wipe "+str+" with the rag.\n");
say(tp+" wipes "+str+" with a rag.\n");
    return 1;   }
