inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Tower of Genji";
long_desc =
"     Your feet rest upon a crystal clear sheet of glass, two meters\n"+
"square which hangs without support in the core of the tower.  It\n"+
"reflects your immage in a rather grotesque manner.  Above you is a\n"+
"single level of doors, exactly like the arched doors which confront\n"+
"you here.  Below are three more levels with eight doors each.  Beyond\n"+
"that, darkness.\n";

items = ({
"feet",  "They are your feet. You know what they look like",
"glass", "Really a ter-angreal mirror of very thick proportion.\n"+
         "If it were in the correct position, you could\n"+
         "'enter mirror' to escape the tower",
"sheet", "Really a ter-angreal mirror of very thick proportion.\n"+
         "If it were in the correct position, you could\n"+
         "'enter mirror' to escape the tower",
"immage","You see yourself from the soles of your boots up",
"doors", "More like oval openings in the interior wall, each/n"+
         "perfectly matching all the others in appearence",
"core",  "The interior of the tower, circular in shape with\n"+
         "two levels above and another two levels below",
"darkness", "Completly black, like empty space",

});

dest_dir = ({
"/players/fakir/genji/rm2d","north",
"/players/fakir/genji/rm8d","south",
"/players/fakir/genji/rm6d","east",
"/players/fakir/genji/rm4d","west",
"/players/fakir/genji/rm1d","northwest",
"/players/fakir/genji/rm7d","southwest",
"/players/fakir/genji/rm9d","southeast",
"/players/fakir/genji/rm3d","northeast",

});

}
