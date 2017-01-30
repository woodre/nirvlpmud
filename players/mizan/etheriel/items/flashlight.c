string amount_of_fuel;
string name;
status is_lighted;

short() {
  if (is_lighted) {
    return "A halogen flashlight (lit)";
  }
  return "A halogen flashlight";
}

long() {
  write("This is a halogen flashlight made of a durable green plastic.\n");
  write("To use it, toggle 'light on' and 'off'.\n");
  if(is_lighted) {
    write("Right now, it is ON.\n");
  } else {
    write("Right now, it is OFF.\n");
  }
}

reset(arg) {
  if (arg) return;
  amount_of_fuel = 2800;
  name = "flashlight";
  is_lighted = 0;
}

query_weight() { return 1; }

init() {
    add_action("light", "light");
}

light(str) {
  int i;
  if (!str) return 0;
  if(str == "on") {
    if (is_lighted) {
	write("It is already lighted.\n");
	return 1;
    }
    is_lighted = 1;
    call_out("out_of_fuel", amount_of_fuel * 2);
    if (set_light(1) == 1) {
	write("You turn on the flashlight.\n");
	say(call_other(this_player(), "query_name") +
	    " turns on a flashlight.\n");
    } else
	write("Ok.\n");
    amount_of_fuel = 0;
    return 1;
  }
  if(str == "off");
    if (!is_lighted) return 0;
    i = remove_call_out("out_of_fuel");
    if (i == -1) {
      write("Error.\n");
      return 1;
    }
    amount_of_fuel = i/2;
    is_lighted = 0;
    if (set_light(-1) == 0) {
	write("It turns dark.\n");
	say(call_other(this_player(), "query_name") +
	    " turns off the flashlight.\n");
    } else {
	write("Ok.\n");
    }
    return 1;
}

out_of_fuel() {
    object ob;
    if (set_light(-1) == 0)
	say("Darkness settles in as the battieries in the flashlight die.\n");
    else
	say("The batteries in the flashlight died.\n");
    ob = environment(this_object());
    if (living(ob))
	call_other(ob, "add_weight", -1);
    destruct(this_object());
}

id(str) {
    return str == "flashlight";
}

query_value() { return amount_of_fuel/100; }

get() { return 1; }

