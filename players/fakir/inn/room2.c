#define TP this_player()
#define TPN this_player()->query_name()
#define TPP this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Winespring Inn";
long_desc =
   "The expansive slate fireplace stretches along the entire of this\n"+
   "wall to the east.  Alcoves have been built into the face of the\n"+
   "fireplace and books are neatly stacked inside them for the reading\n"+
   "pleasure of the inn's patrons.  A table and chairs are to the north.\n";

items = ({
   "fireplace", "Grey slate embedded in red mortar covers the entire wall\n"+
                "from floor to ceiling.  The slate is irregular and has fossil\n"+
                "leaves and insects etched in its rough surface from place to\n"+
                "place.  The slate has been set with great care by a master\n"+
                "craftsman, perhaps even an Ogier",
   "wall",      "The east wall of the Winespring Inn, covered entirely by a\n"+
                "grey slate fireplace",
   "alcoves",   "Small rectangles built into the face of the fireplace about\n"+
                "fourteen snitches deep and several spans wide.  They are\n"+
                "filled with books on many subjects", 
   "books",     "Rare in the Two Rivers area, these are some of the best books\n"+
                "to be found, and the innkeeper allows all to read freely, but\n"+
                "you may not take a book out of the inn",
   "table",     "Several spans long and a third as wide, it stands on four legs\n"+
                "of sturdy hewn timber six snitches square.  Its top is thick\n"+
                "as well, and is stained a rich dark brown from the grease and\n"+
                "spilled drinks",
   "chairs",    "Plain but sturdy and made from the same timber as the tables,\n"+
                "they are able to support the heaviest of men with ease",
   
});
if(!present("jon",this_object()))
 move_object(clone_object("/players/fakir/inn/NPC/jon.c"),this_object());
dest_dir = ({
   "/players/fakir/inn/room3.c", "north",
   "/players/fakir/inn/room11.c", "east",
   "/players/fakir/inn/room10.c", "northeast",
});

}
