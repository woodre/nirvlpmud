#pragma strong_types

inherit "room/room";

void
reset(status arg) {
  object notebook,statue;

  if (present("notebook"))
    destruct(present("notebook"));
  move_object(clone_object("players/angmar/o/notebook"), this_object());
  if (!present("stone statue") && !present("elfwarrior"))
    move_object(clone_object("players/angmar/o/statue"), this_object());
  if (arg)
    return;
  set_light(1);
  short_desc = "The library";
  long_desc = 
"This is Angmar's library.  Along the walls are shelves full of books,\n" +
"papers, and magic scrolls.  The entire room seems to emanate a dark,\n" +
"chilling feeling, as if Angmar were still here in spirit.\n" +
"There is a magic wardrobe in the corner.\n";
  dest_dir = ({
    "players/angmar/castle/magroom", "east",
  });
  items = ({
    "shelves", "They hold what look like the collected works of Angmar's magic",
    "books", "The book you examine deals with the pitfalls of magical human mutation",
    "papers", "The paper seems to be thinner than normal parchment.  Surely, magical",
    "wardrobe", "It can take you to fairyland.\nThe door is closed"
    });
}

void
init() {
  room::init();
  add_action("open","open");
  add_action("close","close");
  add_action("enter","enter");
}

status open(string str) {
  if (str !="door" && str !="wardrobe")
    return 0;
  "players/angmar/castle/wardrobe1"->open_door("door");
  remove_item("wardrobe");
  add_item("wardrobe", "It can take you to fairyland.\nThe door is open");
  return 1;
}

status close(string str) {
  if (str != "door" && str !="wardrobe")
    return 0;
  "players/angmar/castle/wardrobe1"->close_door("door");
  remove_item("wardrobe");
  add_item("wardrobe", "It can take you to fairyland.\nThe door is closed");  
  return 1;
}

status enter(string str) {
  if (str != "door" && str != "wardrobe")
    return 0;
  if("players/angmar/castle/wardrobe1"->query_door()) {
    write("The door is closed.\n");
    return 1;
  }
  this_player()->move_player("into the wardrobe#players/angmar/castle/wardrobe1");
  return 1;
}
