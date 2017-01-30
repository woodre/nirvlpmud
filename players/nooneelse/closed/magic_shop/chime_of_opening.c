/*
  chime_of_opening.c
*/

inherit "obj/treasure";

string str, str2;

init() {
  ::init();

  add_action("ring_chime", "ring");
}

ring_chime(str) {
  object stuff, door_obj;
  int found_door;
  if (!str || !id(str)) return;
  door_obj=0;
  found_door=0;
  stuff=first_inventory(environment(environment()));
  while (stuff) {
    str=0;
    str=stuff->short();
    if (str) {
      str2=0;
      sscanf(str, "%sdoor%s", str2);
      if (!str2) sscanf(str, "%sdoor", str2);
      if (!str2) sscanf(str, "door%s", str2);
      if (str2 && !door_obj) {
        door_obj=stuff;
        found_door=1;
        door_obj->set_locked(0);
      }
    }
    stuff=next_inventory(stuff);
  }
  if (!found_door) {
    write("Open the lock on what door?\n"+
          "This only works on doors that you can see.\n");
    return 1;
  }
  write("As you tap the chime, it emits a clear pericing note and"+
        " starts to glow.\n");
  say("As "+this_player()->query_name()+" taps the chime, it emits a clear\n"+
      "pericing note and starts to glow.\n", this_player());
  return 1;
}

reset(arg) {
  set_short("A brass chime");
  set_long("It is a small brass chime.\n"+
           "\nA small label says: Made by Nooneelse's Doodads Inc.\n");
  set_value(300);
  set_weight(1);
}

query_save_flag() { return 1; }

id(str) { return str=="brass chime" ||
                 str=="chime" ||
                 str=="small chime" ||
                 str=="small brass chime"; }
