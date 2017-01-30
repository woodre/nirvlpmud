#define DEST "room/south/sforst17"

int manservant_dead, gate_open;
object manservant;

mixed
id(string str) {
  return str == "mansion" || str == "sign" || str == "gate";
}

string
short() {
  return "The Mansion of Kantele is to the south";
}

void
long(string str) {
  if (str == "sign") {
    write("\nBEWARE OF THE DOGS\n\n"+
          "SQUATTERS WILL BE EATEN !\n\n");
    return;
  }
  write("A large fence topped by barbed wire surronds the house, the only\n");
  write("entrance is a huge iron gate leading into the garden. There is a\n");
  write("sign on the gate. You can also see a bell rope.\n");
}

void
init() {
  add_action("enter", "south");
  add_action("pull_rope", "pull");
}

status
pull_rope(string str) {
  if (!str || str != "rope")
    return 0;
  if (str == "rope") {
    if (gate_open == 1) {
      write("nothing happens...\n");
      return 1;
    } else {
      gate_open = 1;
      say(this_player()->query_name()+" pulls the rope...\n");
      say("The gate opens !\n");
      say("Kanteles manservant arrives.\n");
      say("Kanteles manservant says: get lost punk !\n");
      write("The gate opens !\n");
      write("Kanteles manservant arrives.\n");
      write("Kanteles manservant says: get lost punk !\n");
      if (!manservant || !living(manservant))
        manservant = clone_object("players/kantele/manservant");
      move_object(manservant, environment(this_object()));
      return 1;
    }
  }
}

status
enter(string str) {
  if (manservant && environment(manservant) == environment(this_object())) {
    write("Kanteles servant bars your way !\n");
  } else if (gate_open == 0) {
    write("The gates are closed.\n");
  } else {
    this_player()->move_player("south#players/kantele/brick_road");
  }
  return 1;
}

void
reset(status arg) {
  /* Move away the manservant, and close the gates. */
  if (manservant && living(manservant))
    manservant->move_player("X#players/kantele/castle");
  gate_open = 0;
  if (arg)
    return;
  move_object(this_object(), DEST);
}
is_castle(){ return 1; }
