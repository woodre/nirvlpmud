
int shots_drank;

id(str) { return (str == "saki" || str == "bottle"); }

reset() {}

long()
{
  write("A tall bottle Japanese Saki.\n");
  write("There are " + (11-shots_drank) + " shots left.\n");
}

short() { return "A bottle of Saki"; }
drop() {
	write("the bottle breaks on the ground.\n");
	destruct(this_object());
	return 1;
	}

init()

{
  add_action("drink","drink");
}

drink(arg)
{
  if (id(arg)) {
    if (!call_other(this_player(), "drink_alcohol", 14)) {
	write("You might want to wait a bit.\n");
	return 1;
	}
    if (call_other(this_player(), "drink_alcohol", 15))
      say(call_other(this_player(),"query_name") + " takes a shot of Saki.\n");
      write("You take a shot of Saki\n WHAMM it hits you like a ton of bricks!\n");
      if (shots_drank == 10) { write("You suck the last shot out and break the bottle.\n"); }
      else { write("There are " + (10 - shots_drank) + " shots left.\n"); }
      call_other(this_player(),"heal_self",20);
      shots_drank++;
      if (shots_drank > 10) { 
        this_player()->add_weight(-1);
        destruct(this_object()); 
      }
      return 1;
    }
    return 1;
}
 


get() { return 1; }

query_weight() { return 1; }

query_value() { return 1000; }


