/*
 cellar11.c
*/

inherit "room/room";

realm() { return "NT"; }

reset(arg) {
  if (arg) return;

  set_light(0);
  no_castle_flag=1;
  short_desc = "alchemists' bedroom";
  long_desc =
    "This seems to be the bedroom of a very messy person.  There are\n"+
    "clothes strewn all over the single bed, the wooden chair and the\n"+
    "small table.  Also on the table is a couple of empty vials with\n"+
    "strange stains in them.\n";
  items =
    ({
      "clothes", "Various articles of clothing look as if they were taken "+
                 "off and dropped.",
      "bed", "The bed is rumpled and in disarray.",
      "chair", "The wooden chair looks uncomfortable.",
      "table",
        "The small wooden dressing table is barren except for the vials.",
      "vials", "These small glass vials look like chemists mixing beakers.",
      "stains", "They look like permanent chemical stains.",
    });
  dest_dir =
    ({
      "players/nooneelse/red/cellar12", "south",
      "players/nooneelse/red/cellar10", "north",
    });
  return;
}
