/*
 cellar7.c
*/

inherit "room/room";

realm() { return "NT"; }

reset(arg) {
  if (arg) return;

  set_light(0);
  short_desc = "old wine room";
  no_castle_flag=1;
  long_desc =
    "This large room was once, long ago, used to store wine.  The huge\n"+
    "wooden racks are sagging with age.  The racks on the west wall\n"+
    "have fallen to expose what used to be a concealed door.\n";
  items =
    ({
      "racks",
      "These are big wooden beams built into racks to hold large wine barrels.",
      "rack",
      "It is made of big wooden beams, made to hold large wine barrels.",
      "casks", "They are large wooden wine barrels.",
      "cask", "It is a large wooden wine barrel.",
      "barrels", "They are large wooden wine casks.",
      "barrel", "It is a large wooden wine cask.",
      "door", "This scratched wooden door sags open on broken hinges.",
      "scratches", "They seem to be the marks of something with strong claws.",
      "scratch", "It seems to be the mark of something with strong claws.",
    });
  dest_dir =
    ({
      "players/nooneelse/red/cellar5", "north",
      "players/nooneelse/red/cellar8", "west",
    });
}
