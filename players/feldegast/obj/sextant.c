inherit "/obj/treasure.c";

void reset(int arg) {
  if(arg) return;
  set_id("sextant");
  set_short("A sextant");
  set_long("This is a sextant, used by sailors for centuries to calculate\n"+
           "their position.  You can USE it to calculate yours.\n");
  set_weight(1);
  set_value(150);
}

void init() {
  add_action("cmd_use","use");
}

int cmd_use(string str) {
  int *coords;
  if(!str || !id(str)) {
    notify_fail("Use what?\n");
    return 0;
  }
  coords=(int *)environment(this_player())->query_coords();
  if(!coords)
    write("You cannot gauge your current position.\n");
  else
    write("You use the sextant to locate your current longitude and latitude.\n"+
          "X: "+coords[0]+" Y: "+coords[1]+"\n");
  return 1;
}

  