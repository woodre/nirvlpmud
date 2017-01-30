/* 10/11/05 Earwax: Made room land. */

inherit "/players/earwax/housing/land.c";
inherit "room/room";
reset(arg) {
  if(!present("messenger")) {
    move_object(clone_object("/players/mythos/amon/messenger.c"),this_object()); }
  if(!arg) {
  set_light(1);
    short_desc = "Village Path1";
    long_desc =
    "You stand on the path that cuts through the village\n"+
    "As you trod on it, you see the shops and buildings of\n"+
    "of the village.  North is the Shrine, south is the Smithy.\n"+
    "West leads back to the entrance.\n";
  items = ({
    "north","You see the entrance to the Shrine",
    "south","You see a smithy",
    "west","You see the Pub and Shop",
  });

  dest_dir = ({
    "/players/mythos/aroom/shrinear4.c", "north",
    "/players/mythos/aroom/smithy.c","south",
    "/players/mythos/aroom/village.c","west",
  });
  set_realm_name("Ancient");
  set_lot_size(-2);
  set_cost(950000);
  setup_land();
} }
