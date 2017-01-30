
int water_drank;

id(str) { return (str == "water" || str == "canteen"); }

reset() {}

long()
{
  write("A canteen of pure mountain water.\n");
  write("There are " + (11-water_drank) + " sips left.\n");
}

short() { return "A canteen of water"; }
drop() {
	write("the canteen breaks on the ground.\n");
	destruct(this_object());
	return 1;
	}

init()

{
  add_action("drink"); add_verb("drink");
}

drink(arg)
{
  if (id(arg)) {
    if (!call_other(this_player(), "drink_alcohol", 14)) {
        write("You are too bloated to drink.\n");
	return 1;
	}
    if (call_other(this_player(), "drink_alcohol", 15))
      say(call_other(this_player(),"query_name") + " takes a sip of Water.\n");
      write("You take a sip of Water\n You are refreshed.\n");
if (water_drank == 10) { write("You drink the last sip from your canteen.\n"); }
      else { write("There are " + (10 - water_drank) + " sips left.\n"); }
      call_other(this_player(),"heal_self",18);
      water_drank++;
      if (water_drank > 10) { 
        this_player()->add_weight(-1);
        destruct(this_object()); 
      }
      return 1;
    }
    return 1;
}
 


get() { return 1; }

query_weight() { return 1; }

query_value() {
   int y;
      y=1000-1000/11*water_drank;
     return y;
}


query_save_flag() {return 1;}
