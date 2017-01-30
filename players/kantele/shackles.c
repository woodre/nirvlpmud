#pragma strong_types

inherit "obj/armor";

void reset(status arg) {
  ::reset(arg);
  if (arg)
    return;
  set_id("shackles");
  set_name("shackles");
  set_short("Some strange shackles");
  set_long("Some strange arm and leg shackles.\n");
  set_type("prison");
  set_ac(0);
  set_value(0);
  set_weight(1);
}

int drop(int silently) {
  if(this_player()->query_level() < 20) {
    write("The shackles are impossible to get off.\n");
    return 1;
  }
  return 0;
}

status get() {
  this_player()->wear(this_object());
  return 1;
}

status magic() {
  if (this_player()->query_level() > 20) {
    return 0;
  } else {
    write("You can't use magic while shackled.\n");
    return 1;
  }
}

status move() {
  if(this_player()->query_level() > 20) {
    return 0;
  } else {
    return 1;
  }
}

status kill() {
  write("You can't kill somebody while you are shackled.\n");
  return 1;
}
