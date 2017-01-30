inherit "room/room";

reset(arg) {
  if(!arg) {
  set_light(1);
  short_desc="The circle of stones";
  long_desc=
    "The circle of stones.  You stand at the center of this\n"+
    "barren village.  Blackened stones form a large circle here.\n"+
    "Inside the circle are the ashes of countless fires.  A lone\n"+
    "whisp of smoke curls lazily into the sky.  The trail\n"+
    "continues northeast and southwest.  There are grass huts\n"+
    "to the north, east and west.\n";

  items=({
  "circle",
  "A circle of blackened stones lies here",
  "stones",
  "A circle of blackened stones lies here",
  "ash",
  "Smoldering ashes from countless fires burn here",
  "ashes",
  "Smoldering ashes from countless fires burn here",
  "trail",
  "The well-worn trail continues northeast and southwest from here",
  });

  dest_dir=({
    "/players/pavlik/guild/room/village3", "northeast",
    "/players/pavlik/guild/room/village1", "southwest",
  });

  }
}

init() {
  ::init();
  add_action("enter_hut","north");
  add_action("enter_hut","east");
  add_action("enter_hut","west");
}

enter_hut() {
  write("You enter the small grass hut.\n");
  switch (query_verb()) {
    case "north" :
	this_player()->move_player("into a hut#players/pavlik/guild/room/exchange");
	break;
    case "east" :
	this_player()->move_player("into a hut#players/pavlik/guild/room/hut1");
	break;
    case "west" :
	this_player()->move_player("into a hut#players/pavlik/guild/room/advance");
	break;
  }
  return 1;
}

