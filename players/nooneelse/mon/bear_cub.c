/*
  bear_cub.c
*/

inherit "obj/monster";

reset(arg) {
  if (arg) return 0;
  ::reset();

  set_name("bear cub");
  set_level(3);
  set_alias("bear");
  set_race("bear");
  set_short("A bear cub");
  set_long("A small, cute, fuzzy bear cub.  Wonder were mom is?\n");
  set_alt_name("cub");
}

heart_beat() {
  object obj;
  ::heart_beat();

  if (!environment()->query_mom_called() && query_hp() < query_max_hp()) {
    tell_room(environment(),
      "The cub screams in pain and a huge female grizzly bear lumbers in.\n");
    obj->clone_object("players/nooneelse/mon/bear");
    move_object(obj, environment(this_object()));
    environment()->mom_called();
  }
}
