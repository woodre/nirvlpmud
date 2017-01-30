/*
  force_cube.c - a force cube surrounding a player for a bit
*/

inherit "room/room";

reset(arg) { return; }

query_light() { return 1; }

get() { return 0; }

id(str) { return str=="cube" || str=="force cube"; }

short(arg) {
  string str;
  object obj;
  /* they're looking at it from outside */
  if (environment(this_player())!=this_object()) {
    str=0;
    obj=first_inventory(this_object());
    while (obj) {
        if (!str)
          str=obj->short()+"\n";
        else
          str=str+"   "+obj->short()+"\n";
      obj=next_inventory(obj);
    }
    if (str)
      str="A force cube containing\n"+str;
    else
      str="An empty force cube";
    return str;
  }
  /* they're looking at it from inside */
  str=0;
  obj=first_inventory(environment(this_object()));
  while (obj) {
    if (obj!=this_object() && obj->short())
        if (!str)
          str=obj->short()+"\n";
        else
          str=str+"   "+obj->short()+"\n";
    obj=next_inventory(obj);
  }
  str="A force cube is surrounding you.  Outside, you see\n"+str;
  return str;
}

long() {
  write(short()+"\n");
}

init() {
  add_action("nope", "quit");
  add_action("nope", "shout");
  add_action("nope", "tell");
}

nope() {
  if (environment(this_player())!=this_object()) return 0;
  write("A magic force prevents that.\n");
  return 1;
}
