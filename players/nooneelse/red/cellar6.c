/*
 cellar6.c
*/

inherit "room/room";

realm() { return "NT"; }

reset(arg) {
  if (arg) return;

  set_light(0);
  short_desc = "small hole";
  no_castle_flag=1;
  long_desc =
    "This small room appears to be the nest of something with strong claws.\n"+
    "The walls are rough as if scratched out.\n";
  items =
    ({
      "walls", "The walls are dirt and have deep scracthes in them.",
      "wall", "The wall is dirt and has deep scracthes in it.",
      "scratches", "They are deep.  They look like something has "+
                   "been digging here.",
      "scratch", "It is deep.  It looks like something has been digging here.",
      "hole", "This small hole leads to the room above.",
    });
  dest_dir =
    ({
      "players/nooneelse/red/cellar5", "up",
    });
}
