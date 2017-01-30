#define TP this_player()
#define TPN this_player()->query_name()
#define TPP this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Winespring Inn";
long_desc =
   "Two men from the village sit at one end of a rather large table\n"+
   "sipping ale from tall tankards and eating a thick soup from white\n"+
   "ceramic bowls.  A grey slate fireplace covers the entire south wall\n"+
   "of the inn, and the bar is across the room to your north.  A gleeman\n"+
   "sometimes does magic tricks for drinks and tips to the northeast.\n";

items = ({
   "fireplace", "Grey slate embedded in red mortar covers the entire wall\n"+
                "from floor to cieling.  The slate is irregular and has fossil\n"+
                "leaves and insects etched in its rough surface from place to\n"+
                "place.  The slate has been set with great care by a master\n"+
                "craftsman, perhaps even an ogier",
   "soup",      "A thick concoction of carrots, biscuit root, veal and spuds",
   "ale",       "A deep rich amber color with a good head of foam", 
   "bowls",     "Plain white in color and large enough for five ladles of soup",
   "bar",       "Solid and well built, it spans the entire north wall of the inn",
   "tankards",  "Tall and slender in shape, with a handle of clear glass",
   "gleeman",   "His back is toward you, but the cloak he wears makes you drool",
   "table",     "Several spans long and a third as wide, it stands on four legs\n"+
                "of sturdy hewn timber six snitches square.  Its top is thick\n"+
                "as well, and is stained a rich dark brown from the grease and\n"+
                "spilled drinks",
   "men",       "Clothed in the common attire of the village folk and without weapons,\n"+
                "they appear to be old friends and very hungry by the way they are\n"+
                "wolfing down the soup",
});

dest_dir = ({
   "/players/fakir/inn/room4.c", "north",
   "/players/fakir/inn/room10.c", "east",
   "/players/fakir/inn/room2.c", "south",
   "/players/fakir/inn/room9.c", "northeast",
   "/players/fakir/inn/room11.c", "southeast",
});

}
