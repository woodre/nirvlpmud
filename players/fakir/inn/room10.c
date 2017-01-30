#define TP this_player()
#define TPN this_player()->query_name()
#define TPP this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Winespring Inn";
long_desc =
   "Large wooden tables and chairs are east and west, while to the\n"+
   "northeast a swinging door opens and closes with the passing of\n"+
   "the serving maids.  The bar stretches along the far, north wall\n"+ 
   "of the inns commonroom, and the fireplace covers the wall to the\n"+
   "south.  People are eating and drinking at the various tables,\n"+ 
   "waiting to see if a gleeman will perhaps tell a tale of courage,\n"+
   "or perhaps do some magic tricks.\n";

items = ({
   "fireplace", "Grey slate embedded in red mortar covers the entire wall\n"+
                "from floor to cieling.  The slate is irregular and has fossil\n"+
                "leaves and insects etched in its rough surface from place to\n"+
                "place.  The slate has been set with great care by a master\n"+
                "craftsman, perhaps even an ogier",
   "chairs",    "Plain but sturdy and made from the same timber as the tables,\n"+
                "they are able to support the heaviest of men with ease",
   "bar",       "Solid and well built, it spans the entire north wall of the inn",
   "gleeman",   "With wispy white hair and bushy eyebrows and mustache to match\n"+
                "the gleeman gestures imperiously at those in the room while\n"+
                "pulling multicolored flowers from thin air.  Sparkling blue eyes\n"+
                "peer out of a wrinkled face that seems to belong more to a gnarled\n"+
                "tree that had seen hard times.  The eyes are piercing, and look\n"+
                "deep into your soul.  The multicolored cloak he wears has odd baggy\n"+
                "sleeves and big pockets inside and out",
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
   "maids",     "Slender and attractive, they bustle about under the direction of the\n"+
                "innkeeper, who keeps a watchful eye on them",
   "wall",      "Covered entirely by a grey slate fireplace to the south and a bar north",
});

dest_dir = ({
   "/players/fakir/inn/room9.c", "north",
   "/players/fakir/inn/room13.c", "east",
   "/players/fakir/inn/room11.c", "south",
   "/players/fakir/inn/room14.c", "northeast",
   "/players/fakir/inn/room12.c", "southeast",
   "/players/fakir/inn/room3.c",  "west",
   "/players/fakir/inn/room4.c",  "northwest",
   "/players/fakir/inn/room2.c",  "southwest",
   
});

}
