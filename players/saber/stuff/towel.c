#define tp this_player()->query_name()
inherit "obj/treasure";
reset(arg)
{   if (arg) return;
   set_id("towel");
   set_short("A large, soft towel");
  set_long(
   "A very large soft towel for you to dry off with.\n");
   set_weight(0);
   set_value(5);
}
init()
{  add_action("polish_object", "dry");   }
 polish_object(str)
{
  write("You dry yourself off with the towl.\n");
  say(tp+" dries "+this_player()->query_possessive()+"self off with a towel.\n");
    return 1;   }
