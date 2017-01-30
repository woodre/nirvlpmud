inherit "room/room";
reset(arg) {
  if(!present("sheeh")) {
   move_object(clone_object("/players/stark/forest/mon/sheeh.c"),this_object());
  }
  if (arg) return;
  set_light(1);
  short_desc="Cavern";
  long_desc=
"   The tunnel widens and grows tall into a large room.  On the far \n"+
"south wall, an intricate carving has been made into the wall.  Burning \n"+
"brightly, a bonfire has been placed at the dead center of the room.  \n"+
"Mats and blankets circle past the burnable aura of the fire.\n";

  items=({
"tunnel",
"The tunnel ends here with a large room",
"walls",
"There is a carving on the south wall",
"wall",
"A large picture is carved into the south wall",
"carving",
"The large carving is a picture of sorts",
"picture",
"A carved picture takes up nearly the entirity of the south wall\n"+
"It shows a giant snake rising out of flames.  There are smaller \n"+
"carved snake people bowing before the giant snake",
"bonfire",
"There is enough wood to fuel this fire for days",
"center",
"The center piece of this room is a large fire",
"aura",
"Half a meter keeps the blanketing away from the flames",
"mats",
"Mats and blankets serve to comfort the Sithos at night",
"blankets",
"Blankets are scattered over the circle of mats"
  });

  dest_dir=({
    "/players/stark/forest/cavern5","north"
  });
}   

init() {
  ::init();
  add_action("search","search");
}

search(str) {
  write("You briefly search about the cave and find nothing.\n");
  return 1;
}

