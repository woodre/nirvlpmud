
inherit "/obj/treasure";
id(str) { return (str == "bottle" || str == "water"); }
reset() { save_flag = 1; }
long()
{
  write("A bottle of water.\n");
 /*write("its sobering just to look at.\n");*/
}

short() { return "bottled water"; }

init()

{
  add_action("drink", "drink");
}

drink(arg)
{

  if (id(arg)) {
    this_player()->drink_alcohol(0);
    say(this_player()->query_name() + " drinks the bottled water
.\n");
    write("mmmmm that tastes good\n");
      /*this_player()->add_weight(-1);
      destruct(this_object());*/
      return 1;
      }
   else {
   return 0;
   }
}
get() { return 1; }
query_weight() { return 1; }
query_value() { return 0; }


