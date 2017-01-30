#define tp this_player()->query_name()
inherit "obj/treasure";
reset(arg)
{   if (arg) return;
   set_id("fireplace");
   set_alias("hearth");
  set_long(
 "A large fireplace, filled with blazing logs.\n"+
   "The hearth is made from worked black stone.\n"+
 "Perhaps you might want to add a log to the 'fire'.\n"
    );
   set_weight(50);
   set_value(100);
call_out("blaze",150);
}
init()
{add_action("fire", "fire");
}

fire()
{
 write("You add a log to the fire.\n"+
   "The fire blazes brightly.\n");
 say(tp+" adds another log to the fire.\n"+
   "The fire blazes brightly.\n");
    return 1;   }

blaze() {
if(!environment(this_object())) return 1;
tell_room(environment(this_object()), "The fire blazes warmly.\n");
call_out("blaze",150);
  return 1;
}
