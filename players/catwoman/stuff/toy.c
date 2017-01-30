
inherit "/obj/treasure";
id(str) { return (str == "dildo" || str == "dildo"); }
reset() { save_flag = 1; }
long()
{
  write("A big dildo.\n");
 write("you might try using it.\n");
}

short() { return "a big dildo"; }

init()

{
  add_action("use", "use");
}

use(arg)
{

  if (id(arg)) {
    
    say(this_player()->query_name() + " turns on the dildo it starts to vibrate as \n"+
this_player()->query_name() + " starts using it on " + this_player()->query_name()+".\n");
    write("ooooo that feels good\n");
     /* this_player()->add_weight(-1);
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


