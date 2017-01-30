inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Tower of Genji";
long_desc =
"     Your feet rest upon a crystal clear sheet of glass, two meters\n"+
"square which hangs without support in the core of the tower.  It\n"+
"reflects your immage in a rather grotesque manner.  The interior\n"+
"of the tower looms overhead, broken at four regular intervals by\n"+
"open arched doors at all eight points of the compass...just like\n"+
"the arched doors which confront you here.  Below is the utter\n"+
"emptyness of black unending space.\n";

items = ({
"feet",  "They are your feet. You know what they look like",
"glass", "Really a ter-angreal mirror of very thick proportion.\n"+
         "You could 'enter mirror' to escape the tower",
"sheet", "Really a ter-angreal mirror of very thick proportion.\n"+
         "you could 'enter mirror' to escape the tower",
"immage","You see yourself from the soles of your boots up",
"doors", "More like oval openings into the interior wall of the tower,/n"+
         "each perfectly matching all the others in appearence",
"space", "Open, endless darkness",
"core",  "The interior of the tower, circular in shape with\n"+
         "perhaps five levels above and endless empty space\n"+
         "below",

});

dest_dir = ({
"/players/fakir/genji/rm2a","north",
"/players/fakir/genji/rm8a","south",
"/players/fakir/genji/rm6a","east",
"/players/fakir/genji/rm4a","west",
"/players/fakir/genji/rm1a","northwest",
"/players/fakir/genji/rm7a","southwest",
"/players/fakir/genji/rm9a","southeast",
"/players/fakir/genji/rm3a","northeast",

});

}
