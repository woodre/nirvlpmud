/*
 cellar12.c
*/

inherit "room/room";

object alchemist;

init() {
  ::init();

  add_action("sniff", "sniff");
}

sniff() {
  write("You sniff.\n");
  write("The odor is so bad that you gag and have to run out of the room!\n");
  say(this_player()->query_name()+" sniffs, gags and runs out of the room!\n");
  command("north", this_player());
  return 1;
}


realm() { return "NT"; }

reset(arg) {
  if (arg) return;

  set_light(1);
  short_desc = "alchemists' workroom";
  no_castle_flag=1;
  long_desc =
    "This is the workroom of a chemist.  There are tables everywhere\n"
    + "laden with racks and shelves of jars, vials, bags and boxes of\n"
    + "powders, liquids, lumps and pieces of unknown origin.  There\n"
    + "is a horrid reek of strangely mixed ingrediants.\n";
  items =
    ({
      "tables",
        "The large wooden tables are almost covered with paraphernalia.",
      "table", "The large wooden table is almost covered with paraphernalia.",
      "racks", "These are small wire racks to hold beakers standing upright.",
      "rack", "This is a small wire rack to hold beakers standing upright.",
      "shelves", "The wooden shelves are full of jars, vials and bags.",
      "shelf", "The wooden shelves are full of jars, vials and bags.",
      "jars",
        "They are various sized glass and ceramic jars full of strange things.",
      "jar", "It is a small ceramic jar full of strange things.",
      "vials", "These small glass vials look like chemists mixing beakers.",
      "vial",
        "It is a small glass vial that looks like chemists mixing beaker.",
      "bags", "The bags contain powders and lumps of various chemicals.",
      "bag", "The bag contains powders and lumps of various chemicals.",
      "boxes", "The boxes made are of thin wood and contain bags and jars.",
      "box", "The box is made of thin wood and contains bags and jars.",
      "powders", "Unidentifiable powders of various colors and textures.",
      "powder", "An unidentifiable green powder with a strange texture.",
      "liquids", "Unidentifiable liquids of various colors.",
      "liquid", "An unidentifiable purple liquid.",
      "lumps", "Unidentifiable lumps of various colors, sizes and textures.",
      "lump", "An unidentifiable lavender lump.",
      "pieces", "Unidentifiable pieces of unknown items of various colors, "+
                "sizes and textures.",
      "piece", "An unidentifiable piece of something squishy.",
    });
  dest_dir =
    ({
      "players/nooneelse/red/cellar11", "north",
    });
  if (!find_living("nooneelsealchemist"))
    move_object(clone_object("players/nooneelse/mon/alchemist"), this_object());
}
