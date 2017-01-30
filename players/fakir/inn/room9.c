#define TP this_player()
#define TPN this_player()->query_name()
#define TPP this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Winespring Inn";
long_desc =
   "Large wooden tables and chairs surround this raised or stage area of the\n"+
   "inns commonroom.  It is here that traveling entertainers, known as gleemen,\n"+
   "sometimes ply their stock in trade...magic and storytelling.  There is a\n"+
   "door to the kitchen east, and the bar stretches along the entire north wall\n"+
   "of the inn.  The slate fireplace covers the wall south of here.\n";

items = ({
   "fireplace", "Grey slate embedded in red mortar covers the entire wall\n"+
                "from floor to cieling.  The slate is irregular and has fossil\n"+
                "leaves and insects etched in its rough surface from place to\n"+
                "place.  The slate has been set with great care by a master\n"+
                "craftsman, perhaps even an ogier",
   "chairs",    "Plain but sturdy and made from the same timber as the tables,\n"+
                "they are able to support the heaviest of men with ease",
   "bar",       "Solid and well built, it spans the entire north wall of the inn",
   "tables",    "Several spans long and a third as wide, they stand on four legs\n"+
                "of sturdy hewn timber six snitches square.  Their tops are thick\n"+
                "as well, and appear to be stained a rich dark brown from the\n"+
                "grease and spilled drinks",
   "door",      "Double pannels set on hinges with a louvered section in the center\n"+
                "of each door",
   "commonroom","Huge and expansive, it is warm and comfortable with a massive fireplace\n"+
                "and an inviting bar",
   "maids",     "Slender and attractive, they bustle about under the direction of the\n"+
                "innkeeper, who keeps a watchful eye on them",
   "wall",      "Covered entirely by a grey slate fireplace to the south and a bar north",
});
if(!present("gleeman",this_object()))
 move_object(clone_object("/players/fakir/inn/NPC/gleeman.c"),this_object());
dest_dir = ({
   "/players/fakir/inn/room8.c", "north",
   "/players/fakir/inn/room14.c", "east",
   "/players/fakir/inn/room10.c", "south",
   "/players/fakir/inn/room15.c", "northeast",
   "/players/fakir/inn/room13.c", "southeast",
   "/players/fakir/inn/room4.c",  "west",
   "/players/fakir/inn/room5.c",  "northwest",
   "/players/fakir/inn/room3.c",  "southwest",
   
});

}
