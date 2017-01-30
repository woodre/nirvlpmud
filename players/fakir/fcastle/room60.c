inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Study of the Grand Vizier";
long_desc =
"   Dusty books on dingy shelves line every wall.  An oversize\n"+
"desk dominates the small study.  An hourglass in a turnstile\n"+
"sits atop the desk, along with open charts, maps, and ancient\n"+
"parchments.  A spilled glass of wine drips to the floor from\n"+
"the desk top and stains one of the parchments a deep red.\n";

items = ({
"books",   "Old tombs from a forgotton age with brittle bindings",
"shelves", "Rickety shelves covered in dust from the ages",
"wall",    "One of the four walls which make up the study room",
"desk",    "Dark brown with streaks of black running through the\n"+
           "grain of the wood",
"study",   "The Grand Vizier's study...or workroom",
"hourglass","A figure 8 hour glass of good design and craftsmanship",
"turnstile","A wooden framework around the hourglass that spins",
"charts",   "Overlays of the castles defenses",
"maps",     "Drawings of the surrounding countryside",
"parchments","Letters, sketches, and other doodles of the Grand Vizier",
"glass",     "A very delicate wine glass with a crystal flute",
"wine",      "A deep red burgandy of some sort",
"floor",     "The stone floor of the study",
"stains",    "It is in the shape of your nose oddly enough",

});
if(!present("trolloc",this_object()))
 move_object(clone_object("/players/fakir/woods/TEMP/trolloc4.c"),this_object());

dest_dir = ({
   "/players/fakir/fcastle/room97.c", "out",
   
});
}


