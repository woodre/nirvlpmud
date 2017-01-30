inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Inner Court";
long_desc =
"   Brightly glowing glass lamps cast light into every corner\n"+
"of the inner court of the castle.  Colorful tapestries hang\n"+
"from the walls, depicting glorious battles fought and won.\n"+
"Open stone doorways lead east and west toward the respective\n"+
"towers which house the royal family and their staff and guests.\n"+
"A door north leads to the courtyard of the castle.\n";

items = ({
"door",      "An ornately carved door of a very dark and deep\n"+
             "grained wood...perhaps a type of cherry wood",
"tapestrys", "Colorful curtains with pictures of battles\n"+
             "woven into the patterns",
"court",     "A large but simple room, where an occasional\n"+
             "ball or party is held.  Also where the King\n"+
             "and Queen receive petitioners on alms day",
"lamps",     "Simple bowl type oil lamps with a cotton wick",
"doorways",  "Arched stone doorways, open to the court, which\n"+
             "lead to the east and west towers",

});
dest_dir = ({
   "/players/fakir/fcastle/room31.c", "north",
   "/players/fakir/fcastle/room29.c", "south",
   "/players/fakir/fcastle/room45.c", "east",
   "/players/fakir/fcastle/room55.c", "west",

});
}


