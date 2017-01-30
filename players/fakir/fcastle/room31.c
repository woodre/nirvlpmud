inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Castle Courtyard";
long_desc =
"   Bright sunlight beams though the clouds above, and tall walls\n"+
"surround this large courtyard of the castle. Small shops and stables\n"+
"are clustered about the perimeter of the courtyard, and people hurry\n"+
"about from shop to shop, looking for the latest in trade items and\n"+
"supplies delivered here by tinkers and traveling gypsies.  A few\n"+
"children play in the shade of the towers.  The courtyard continues\n"+
"to the north.\n";

items = ({
"sunlight", "The bright sunlight of a golden mid-day sun",
"clouds",   "Puffy white, and billowing across the sky",
"walls",    "High stone walls, protecting the courtyard",
"shops",    "Small out-buildings set against the inner wall of the castle\n"+
            "courtyard, they have become permanent over a period of time",
"stables",  "Many travelers come and go, and board their steeds in the\n"+
            "safekeeping of the stable hands.  Grains and other feeds\n"+
            "can be had at the stables",
"courtyard","Also called a ward, it is the central area inside the\n"+
            "castle walls",
"castle",   "A stone castle, built sometime in the ancient past",
"people",   "Some tall, some short, some fat, some skinny. All kinds of people",
"children", "Scruffy looking brats still too young to work in the fields",
"towers",   "Twin towers, one to the east, the other to the west",

});
if(!present("trolloc",this_object()))
 move_object(clone_object("/players/fakir/woods/TEMP/trolloc4.c"),this_object());

dest_dir = ({
   "/players/fakir/fcastle/room32.c", "north",
   "/players/fakir/fcastle/room30.c", "south",
   "/players/fakir/fcastle/shop.c", "shop",
   "/players/fakir/fcastle/room35.c", "armory",
});
}


