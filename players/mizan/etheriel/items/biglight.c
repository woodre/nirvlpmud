string amount_of_fuel;
string name;
status is_lighted;

short() {
  if (is_lighted) {
    return "A halogen lantern (lit)";
  }
  return "A halogen lantern";
}

long() {
  write("This is a halogen lantern made of a durable red plastic.\n");
  write("To use it, toggle 'light on' and 'off'.\n");
  if(is_lighted) {
    write("Right now, it is ON.\n");
  } else {
    write("Right now, it is OFF.\n");
  }
}

reset(arg) {
  if (arg) return;
  amount_of_fuel = 5000;
  name = "lantern";
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
    if (set_light(50000) == 1) {
	write("You turn on the lantern.\n");
	say(call_other(this_player(), "query_name") +
	    " turns on a lantern.\n");
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
	    " turns off the lantern.\n");
    } else {
	write("Ok.\n");
    }
    return 1;
}

out_of_fuel() {
    object ob;
    if (set_light(-1) == 0)
	say("Darkness settles in as the battieries in the lantern die.\n");
    else
	say("The batteries in the lantern died.\n");
    ob = environment(this_object());
    if (living(ob))
	call_other(ob, "add_weight", -1);
    destruct(this_object());
}

id(str) {
    return str == "lantern";
}

query_value() { return amount_of_fuel/100; }

get() { return 1; }

