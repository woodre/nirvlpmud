inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Tower of Genji";
long_desc =
"     Your feet rest upon a crystal clear sheet of glass, two meters\n"+
"square which hangs without support in the top of the tower.  It\n"+
"reflects your immage in a rather grotesque manner.  Eight open\n"+
"arched doors surround you. Four more levels with eight doors each\n"+
"lie below you, and beyond that, darkness.\n";

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

});

dest_dir = ({
"/players/fakir/genji/rm2e","north",
"/players/fakir/genji/rm8e","south",
"/players/fakir/genji/rm6e","east",
"/players/fakir/genji/rm4e","west",
"/players/fakir/genji/rm1e","northwest",
"/players/fakir/genji/rm7e","southwest",
"/players/fakir/genji/rm9e","southeast",
"/players/fakir/genji/rm3e","northeast",

});

}
