#define TP this_player()
#define TPN this_player()->query_name()
#define TPP this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Winespring Inn";
long_desc =
   "Large wooden tables and chairs are north and south, while to the east\n"+
   "a swinging door leads to the kitchen.  The bar stretches along the\n"+
   "entire north wall of the inns commonroom, and the fireplace covers\n"+
   "the south wall.  People are eating and drinking at the various tables,\n"+
   "hoping a gleeman will be doing some magic, or perhaps sing a ballad soon.\n";

items = ({
   "fireplace", "Grey slate embedded in red mortar covers the entire wall\n"+
                "from floor to cieling.  The slate is irregular and has fossil\n"+
                "leaves and insects etched in its rough surface from place to\n"+
                "place.  The slate has been set with great care by a master\n"+
                "craftsman, perhaps even an ogier",
   "chairs",    "Plain but sturdy and made from the same timber as the tables,\n"+
                "they are able to support the heaviest of men with ease",
   "bar",       "Solid and well built, it spans the entire north wall of the inn",
   "gleeman",   "His profile is that of a very powerful man, and he is wearing\n"+
                "one of the most gaudy cloaks you have ever seen",
   "tables",    "Several spans long and a third as wide, they stand on four legs\n"+
                "of sturdy hewn timber six snitches square.  Their tops are thick\n"+
                "as well, and appear to be stained a rich dark brown from the\n"+
                "grease and spilled drinks",
   "people",    "Clothed in the common attire of the village folk and without weapons,\n"+
                "they appear to be enjoying a meal away from home",
   "door",      "Double pannels set on hinges with a louvered section in the center\n"+
                "of each door",
   "commonroom","Huge and expansive, it is warm and comfortable with a massive fireplace\n"+
                "and an inviting bar",
   "wall",      "Covered entirely by a grey slate fireplace to the south and a bar north",
   "kitchen",   "You cannot see the kitchen untill you go through the swinging doors",
});

dest_dir = ({
   "/players/fakir/inn/room15.c",  "north",
   "/players/fakir/inn/room13.c",  "south",
   "/players/fakir/inn/room18.c",  "east",
   "/players/fakir/inn/room9.c",   "west",
   "/players/fakir/inn/room8.c",   "northwest",
   "/players/fakir/inn/room10.c",  "southwest",
   
});

}
