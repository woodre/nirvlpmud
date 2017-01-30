#define TP this_player()
#define TPN this_player()->query_name()
#define TPP this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Winespring Inn";
long_desc =
   "The expansive commonroom of the inn greets you like an old friend.\n"+ 
   "Large wooden tables and chairs are north and south, while to the\n"+
   "far east a swinging door opens and closes with the passing of the\n"+
   "serving maids.  The bar stretches along the entire north wall of the\n"+
   "inns commonroom, and the fireplace covers the south wall.  People\n"+
   "are eating and drinking at the various tables, hoping a gleeman might\n"+
   "perform some bits of magic or perhaps do some juggling.  You may exit\n"+
   "the inn through the door to your west.\n";

items = ({
   "fireplace", "Grey slate embedded in red mortar covers the entire wall\n"+
                "from floor to cieling.  The slate is irregular and has fossil\n"+
                "leaves and insects etched in its rough surface from place to\n"+
                "place.  The slate has been set with great care by a master\n"+
                "craftsman, perhaps even an ogier",
   "door",      "Laminated wood planks painted a bright red and reinforced with thick\n"+
                "cast iron straps bolted top and bottom from the inside.  This door\n"+
                "could withstand an army of darkfriends",
   "chairs",    "Plain but sturdy and made from the same timber as the tables,\n"+
                "they are able to support the heaviest of men with ease",
   "bar",       "Solid and well built, it spans the entire north wall of the inn",
   "gleeman",   "His profile is that of a very powerful man, and he is wearing\n"+
                "one of the most gaudy cloaks you have ever seen",
   "tables",    "Several spans long and a third as wide, they stand on four legs\n"+
                "of sturdy hewn timber six snitches square.  Their tops are thick\n"+
                "as well, and are stained a rich dark brown from the grease and\n"+
                "spilled drinks",
   "people",    "Clothed in the common attire of the village folk and without weapons,\n"+
                "they appear to be enjoying a meal away from home",
   "door",      "Double pannels set on hinges with a louvered section in the center\n"+
                "of each door",
   "commonroom","Huge and expansive, it is warm and comfortable with a massive fireplace\n"+
                "and an inviting bar",
   "maids",     "Slender and attractive, they bustle about under the direction of the\n"+
                "innkeeper, who keeps a watchful eye on them",
   "wall",      "Covered entirely by a grey slate fireplace to the south and a bar north",
});

dest_dir = ({
   "/players/fakir/inn/room5.c", "north",
   "/players/fakir/inn/room9.c", "east",
   "/players/fakir/inn/room3.c", "south",
   "/players/fakir/inn/room8.c", "northeast",
   "/players/fakir/inn/room10.c", "southeast",
   "/players/fakir/inn/room1.c",  "exit",
   
});

}
