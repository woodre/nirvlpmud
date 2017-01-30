#define tp this_player()->query_name()
inherit "obj/treasure";
reset(arg)
{   if (arg) return;
   set_id("rag");
  set_short("A large rag");
  set_long(
   "A large rag used to 'polish' objects.\n");
   set_weight(0);
   set_value(5);
}
init()
{  add_action("polish_object", "polish");   }
 polish_object(str)
{
  write("You polish "+str+" with the rag.\n");
  say(tp+" polishes "+str+" with a rag.\n");
    return 1;   }
