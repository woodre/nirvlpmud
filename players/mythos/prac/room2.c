inherit "room/room";
reset(arg) {
  if(!present("slayer")) {
    move_object(clone_object("/players/mythos/prac/slayer.c"),this_object()); }
  if(!arg) {
  set_light(4);
    short_desc = "Sun Room";
    long_desc =
    "You enter a room of blinding intensity.  Light streams forth\n"+
    "from the center of the room.  All is white light, all is \n"+
    "heat. Watch out.\n";
  items = ({
    "center", "A man seems to stand there waiting.",
    "cloud", "The clouds look cooler and much safer.",
  });

  dest_dir = ({
    "/players/mythos/castle.c", "cloud",
  });
} }
  init()  {
    ::init();
    add_action("search_room","search");
  }

  search_room() {
    object card;
    write("You find a small card hidden in a corner.\n");
    say (this_player()->query_name() +"searches the area\n");
    card = clone_object("/players/mythos/prac/card.c");
    move_object(card,this_player());
    return 1;}

