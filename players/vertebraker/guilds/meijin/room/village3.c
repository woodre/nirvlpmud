inherit "room/room";

reset(arg) {
  if(!arg) {
  set_light(1);
  short_desc="North Village";
  long_desc=
    "You are at the north end of the barren village.  Several\n"+
    "grass-sewn huts can be seen to the south.  To the north is\n"+
    "an imposing stone structure with very high walls and a\n"+
    "heavy wooden gate.  The whistling wind is the only sound\n"+
    "that can be heard in this desolate place.  The trail leads\n"+
    "southwest from here.\n";

  items=({
  "huts",
  "Grass huts can be seen to the south",
  "structure",
  "A large stone building lies directly to the north",
  "building",
  "A large stone building lies directly to the north",
  "gate",
  "The large wooden gate is closed tight",
  });

  dest_dir=({
    "/players/vertebraker/guilds/meijin/room/gate", "north",
    "/players/vertebraker/guilds/meijin/room/village2", "southwest",
  });

  }
}

