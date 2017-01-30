/*
 * Gate
 * Dopplegangers Gates
 *
 * Rumplemintz
 */

status main(string str) {
  object badge;
  object gate;
  string menu;

  badge = present("V-GUILD", this_player());
  switch(str) {
  case "help":
    menu = read_file("/players/guilds/dopplegangers/docs/gate_menu");
    write(menu);
    return 1;
    break;
  case "list":
    write("Gate listing:\n");
    if (!badge->query_gate(1)) write("1.  <Not Placed>\n");
    else write("1.  " + badge->query_g(1)->short() + "\n");
    if (!badge->query_gate(2)) write("2.  <Not Placed>\n");
    else write("2.  " + badge->query_g(2)->short() + "\n");
    if (!badge->query_gate(3)) write("3.  <Not Placed>\n");
    else write("3.  " + badge->query_g(3)->short() + "\n");
    if (!badge->query_gate(4)) write("4.  <Not Placed>\n");
    else write("4.  " + badge->query_g(4)->short() + "\n");
    if (!badge->query_gate(5)) write("5.  <Not Placed>\n");
    else write("5.  " + badge->query_g(5)->short() + "\n");
    write("\n");
    return 1;
    break;
  case "drop":
    if (this_player()->query_sp() < 35) {
      write("You do not have enough spell points for that.\n");
      return 1;
    }
    if ((string)environment(this_player())->realm() == "NT") {
      write("Magical forces prevent you from dropping a gate here.\n");
      return 1;
    }
    gate = clone_object("/players/guilds/dopplegangers/obj/gate_ob");
    move_object(gate, environment(this_player()));
    if (!badge->query_gate(1)) {
      badge->set_gate(1, 1);
      badge->set_g(1, environment(gate));
    }
    else if (!badge->query_gate(2)) {
      badge->set_gate(2, 1);
      badge->set_g(2, environment(gate));
    }
    else if (!badge->query_gate(3)) {
      badge->set_gate(3, 1);
      badge->set_g(3, environment(gate));
    }
    else if (!badge->query_gate(4)) {
      badge->set_gate(4, 1);
      badge->set_g(4, environment(gate));
    }
    else if (!badge->query_gate(5)) {
      badge->set_gate(5, 1);
      badge->set_g(5, environment(gate));
    }
    else {
      write("You already have 5 gates.  You will need to remove one first.\n");
      destruct(gate);
      return 1;
    }
    this_player()->add_spell_point(-35);
    write("You drop a gate in " + environment(gate)->short() + ".\n");
    say(this_player()->query_name() + " rips a hole behind " +
        this_player()->query_possessive() + " shadow.\n");
    return 1;
    break;
  case "enter":
    main("list");
    write("Enter the gate to enter:  (0 for none)\n");
    input_to("gate_enter");
    return 1;
    break;
  case "remove":
    main("list");
    write("Enter the gate you want to remove: (0 for none)\n");
    input_to("gate_remove");
    return 1;
    break;
  default: return 0;
  }
  return 0;
}

gate_enter(string str) {
  int i;
  object badge;
  object target;

  badge = present("V-GUILD", this_player());
  if (sscanf(str, "%d", i) == 1) {
    if (i < 1 || i > 5) {
      write("That is an invalid selection.\n");
      return 1;
    }
    switch(i) {
    case 1: target = badge->query_g(1); break;
    case 2: target = badge->query_g(2); break;
    case 3: target = badge->query_g(3); break;
    case 4: target = badge->query_g(4); break;
    case 5: target = badge->query_g(5); break;
    default:
      write("That is an invalid selection.\n");
      return 1;
      break;
    }
    if (!present("dopp_gate", target)) {
      write("That gate has been destroyed, removing from list.\n");
      badge->set_gate(i, 0);
      badge->set_g(i, 0);
      return 1;
    }
    if (this_player()->query_sp() < 30) {
      write("You do not have enough spell points to do that.\n");
      return 1;
    }
    if ((string)environment(this_player())->realm() == "NT") {
      write("A magical force is preventing the gate from opening.\n");
      return 1;
    }
    this_player()->add_spell_point(-30);
    say(this_player()->query_name() + " steps behind " +
        this_player()->query_possessive() + " shadow and disappears.\n");
    write("You step behind your shadow and arrive in a new place.\n");
    move_object(this_player(), target);
    say(this_player()->query_name() + " steps out from behind the shadows.\n");
    return 1;
  }
  write("You need to choose which gate to enter.\n");
  return 1;
}

gate_remove(string str) {
  int i;
  object badge;
  object target;

  badge = present("V-GUILD", this_player());
  if (sscanf(str, "%d", i) == 1) {
    if (i < 1 || i > 5) {
      write("That is an invalid selection.\n");
      return 1;
    }
    switch(i) {
    case 1: target = badge->query_g(1); break;
    case 2: target = badge->query_g(2); break;
    case 3: target = badge->query_g(3); break;
    case 4: target = badge->query_g(4); break;
    case 5: target = badge->query_g(5); break;
    default:
      write("That is an invalid selection.\n");
      return 1;
      break;
    }
    if (present("dopp_gate", target)) {
      write("Destructing gate in " + target->short() + ".\n");
      destruct(present("dopp_gate", target));
    }
    else write("That gate has already been destroyed, removing from list.\n");
    badge->set_gate(i, 0);
    badge->set_g(i, 0);
    return 1;
  }
  write("You need to choose which gate to remove.\n");
  return 1;
}
