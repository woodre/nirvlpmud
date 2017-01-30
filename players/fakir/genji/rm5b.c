inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Tower of Genji";
long_desc =
"     Your feet rest upon a crystal clear sheet of glass, two meters\n"+
"square which hangs without support in the core of the tower.  It\n"+
"reflects your immage in a rather grotesque manner.  The interior of\n"+
"the tower rises overhead, divided at three regular intervals by open\n"+
"arched doors at all eight points of the compass...just like the\n"+
"arched doors which confront you here.  Below is another set of eight\n"+
"doors, and beyond that, empty darkness.\n";

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
         "three levels above and another level below",
"darkness", "Black as a pit of tar, it resembles empty space",

});

dest_dir = ({
"/players/fakir/genji/rm2b","north",
"/players/fakir/genji/rm8b","south",
"/players/fakir/genji/rm6b","east",
"/players/fakir/genji/rm4b","west",
"/players/fakir/genji/rm1b","northwest",
"/players/fakir/genji/rm7b","southwest",
"/players/fakir/genji/rm9b","southeast",
"/players/fakir/genji/rm3b","northeast",

});

}
