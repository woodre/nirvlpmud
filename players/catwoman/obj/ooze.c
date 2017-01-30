
inherit "/obj/treasure";
id(str) { return (str == "bottle" || str == "ooze"); }
reset() { save_flag = 1; }
long()
{
  write("A bottle of boiling black ooze.\n");
  write("its sobering just to look at.\n");
}

short() { return "a bottle of ooze"; }

init()
 
{
  add_action("drink", "drink");
}

drink(arg)
{
  if (id(arg)) {
    this_player()->drink_alcohol(-10);
    say(this_player()->query_name() + " drinks the ooze then swallows the bottle.\n");
    write("Ooooo Yuk.\n");
      this_player()->add_weight(-1);
      destruct(this_object()); 
      return 1;
      }
   else { 
   return 0; 
   }
}
get() { return 1; }
query_weight() { return 1; }
query_value() { return 150; }

