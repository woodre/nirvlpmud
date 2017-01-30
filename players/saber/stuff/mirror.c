inherit "obj/treasure";
reset(arg)
{   if (arg) return;
   set_id("mirror");
   set_short("A mirror");
   set_long("This is a small silver mirror that you may 'peek' in to.\n");
   set_weight(1);
   set_value(10);
}
init()
{  add_action("peek_mirror", "peek");   }
peek_mirror(str)
{  if ((!str) || !id(str)) return 0;
   write("You gaze in rapture at your own reflection.\n");
   say(this_player()->query_name()+" gazes into a mirror.\n");
    return 1;   }

quest_ob()  { return 1; }
