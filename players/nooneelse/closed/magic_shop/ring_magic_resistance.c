/*
  ring_magic_resistance.c
*/

inherit "obj/armor";

string str;

init() {
  ::init();

  add_action("read_ring",   "read");
  add_action("wear_ring",   "wear");
  add_action("remove_ring", "remove");
}

/* clue the player of what the ring does */
read_ring(str) {
  if (!str || !id(str)) return;
  write(
    "It says: With this protection, from magic will you be safe.\n");
  return 1;
}

wear_ring(str) {
  if (!str || !id(str)) return;
  this_player()->add_immunity("magic");
  write("The ring glows for a moment.\n");
  say("As "+this_player()->query_name()+
      " puts a ring on, it glows for a moment.\n", this_player());
  return 1;
}

remove_ring(str) {
  if (!str || !id(str)) return;
  this_player()->remove_immunity("magic");
  write("The ring glows for a moment.\n");
  say("As "+this_player()->query_name()+
      " puts a ring on, it glows for a moment.\n", this_player());
  return 1;
}

reset(arg) {
  ::reset(arg);
  if (arg) return;

  set_name("ring");
  set_alias("steel ring");
  set_short("Steel Ring");
  set_long("This is a sturdy looking ring that's just your size.\n"+
           "There seems to be something written inside the band.\n");
  set_value(10000);
  set_weight(1);
  set_ac(1);
  set_type("ring");
  set_arm_light(1);
}

query_save_flag() { return 1; }
