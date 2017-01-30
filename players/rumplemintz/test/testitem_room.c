#pragma strong_types

inherit "room/room";

int switch_on;

void
reset(status arg)
{
  if (arg)
    return;
  switch_on = 0;
  set_short("Test room");
  set_long("Rump's test room.\n"+
"Currently testing the following items: switch, window, and car.\n");
  dest_dir = ({
    "/players/rumplemintz/workroom", "work"
  });
  items = ({
    "switch", "The switch is currently off",
    "window", "It's a window",
    "car", "It's a car"
  });
}

void
init() {
  ::init();
  add_action("flick", "flick");
}

status
flick(string str) {
  string pos;
  if (!str)
    return 0;
  if (str == "switch") {
    if (switch_on) {
      switch_on = 0;
      pos = "off";
      set_light(-1);
      remove_item("switch");
      add_item("switch", "The switch is currently off");
    }
    else {
      switch_on = 1;
      pos = "on";
      remove_item("switch");
      add_item("switch", "The switch is currently on");
      set_light(1);
    }
    write("You flick the switch to the "+pos+" position.\n");
    write("The switch_on var is now : "+switch_on+".\n");
    say(this_player()->query_name()+" flicks the switch "+pos+".\n");
    return 1;
  }
}
