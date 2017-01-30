
inherit "/obj/treasure";
id(str) { return (str == "bag" || str == "popcorn"); }
reset() { save_flag = 1; }
long()
{
  write("A bag of popcorn.\n");
 /*write("its sobering just to look at.\n");*/
}

short() { return "bag of popcorn"; }

init()

{
  add_action("eat", "eat");
}

eat(arg)
{

  if (id(arg)) {
    this_player()->drink_alcohol(0);
    say(this_player()->query_name() + " eats the bag of popcorn bag and all.\n");
    write("mmmmm that tastes good\n");
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
query_value() { return 0; }

