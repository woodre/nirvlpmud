/*
  guild_mist.c - a mist to make the room dark to all but vampires
*/

inherit "obj/armor";

reset(arg) {
  if (arg) return;

  set_weight(666);
  set_value(0);
  set_arm_light(-9);
}

get() { return 0; }

id(str) { return str=="mist" || str=="vampire mist" || str=="red mist"; }

short() {
  if (present("vampire fangs", this_player()))
    return "Through the deep red mist, you see:\n"+
           environment(this_object())->short();
  else
    return "There is a deep red mist here that blocks your vision";
}

init() {
  add_action("look",      "look", 1);
  add_action("look",      "examine", 3);
  add_action("inventory", "inventory", 1);
}

look(str) {
  object obj;
  string dest_dir, str2;
  int n;
  str2=0;
  if (str) sscanf(str, "at %s", str2);
  if (str && !str2) sscanf(str, "into %s", str2);
  if (str && (str2!="mist" && str2!="red mist") &&
      present("vampire fangs", this_player()))
    return 0;
  if (present("vampire fangs", this_player())) {
    write("Through the deep red mist, you see:\n"+
          environment(this_object())->short()+".\n");
    dest_dir=environment(this_object())->query_dest_dir();
    if (sizeof(dest_dir) > 0) {
      if (sizeof(dest_dir)==1)
        write("The only obvious exit is ");
      else
        write("The obvious exits are ");
      n=1;
      while (n < sizeof(dest_dir)) {
        write(dest_dir[n]);
        if (n < (sizeof(dest_dir) - 2) && sizeof(dest_dir) > 1) write(", ");
        n++;
        n++;
      }
    }
    else
      write("The mist is so thick that even you cannot see the exits"+
            " in this room.\n");
    write("\n\n");
    obj = first_inventory(environment(this_object()));
    while(obj) {
      if (obj!=this_player() && obj!=this_object() && obj->short())
        write(obj->short()+".\n");
      obj = next_inventory(obj);
    }
  }
  else
    write("There is a deep red mist here that blocks your vision.\n");
  return 1;
}

inventory() {
  if (present("vampire fangs", this_player())) return 0;
  write("The mist is too thick for you to see anything clearly.\n");
  return 1;
}
