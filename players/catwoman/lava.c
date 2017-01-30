
id(str) { return (str == "lava"); }
reset() {}
long()
{  write("A crucible filled with liquid Lava.\n");}
short() { return "Liquid Lava"; }
init()
{ add_action("drink","drink");}
drink(arg)
{
  if (id(arg)) {
    if (!call_other(this_player(), "drink_alcohol",13)){
	write("what!?!? are you crazy?? you've had too much!!!\n");
	return 1;
	}
    if (call_other(this_player(), "drink_alcohol", 20))
    {
      say(call_other(this_player(),"query_name") + " screams as the lava goes down thier throat.\n");
      write("Your throat feels like its on fire.\n  You begin to wonder if your going to survive.\n");
      call_other(this_player(),"heal_self",200);
      this_player()->add_weight(-2);
      destruct(this_object()); 
      return 1;
    }
    return 1;
  } else { return 0; }
}
get() { return 1; }
query_weight() { return 2; }
query_value() { return 5000; }

