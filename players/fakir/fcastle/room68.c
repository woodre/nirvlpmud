inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "West Castle Hallway";
long_desc =
"   The hallway to the captain's quarters is well lit by brightly\n"+
"burning glass lamps full of clear oil.  A red and blue carpet\n"+
"covers the floorway and softens the fall of your boots upon\n"+
"the stone.\n";

items = ({
"boots",    "They are yours....take a look down",
"carpet",   "A fine imported carpet with a gold thread binding",
"oil",      "A clear and clean burning oil of some sort",
"walls",    "Stone set close without mortar or joint.  Drops of moisture\n"+
            "trickle down from above",
"lamps",    "Glass lamps with tall chimneys, also of clear glass",
"hallway",  "The place in which you stand",
"floorway", "Stones worn smooth and almost slick from many boots",

});
if(!present("gaurd",this_object()))
 move_object(clone_object("/players/fakir/fcastle/NPC/cguard.c"),this_object());

dest_dir = ({
   "/players/fakir/fcastle/room29.c", "gate_house",
   "/players/fakir/fcastle/room69.c", "hall",
});
}


