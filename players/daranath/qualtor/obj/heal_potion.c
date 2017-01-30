
#include <ansi.h>

id(str) { return (str == "potion"); }
reset() {}
short() { return ("A "+HIR+"dark red"+NORM+" healing potion"); }
long() { write("A small potion that is dark red in color, its magical nature\n"+
               "is quite evident from just holding it. You can feel the power\n"+
               "of the potion resonating in your hand.\n"); }
init()
{ add_action("drink","drink");}
drink(arg)
{
  if (id(arg)) {
    if (!call_other(this_player(), "drink_alcohol",13)){
  write("The power of the potion is too much for you right now.\n");
	return 1;
	}
    if (call_other(this_player(), "drink_alcohol", 20))
    {
  say(call_other(this_player(),"query_name") + "drinks the powerful potion in full.\n");
  write("You drink the powerful potion, its power healing your wounds.\n");
      call_other(this_player(),"heal_self",400);
      this_player()->add_weight(-1);
      destruct(this_object()); 
      return 1;
    }
    return 1;
  } else { return 0; }
}
get() { return 1; }
query_weight() { return 1; }
query_value() { return 10000; }

