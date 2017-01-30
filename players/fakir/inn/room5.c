#define TP this_player()
#define TPN this_player()->query_name()
#define TPP this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Winespring Inn";
long_desc =
   "An empty table covered with the last remains of a meal sits somewhat\n"+
   "askew in the room, as if those who were eating here left in a hurry.\n"+
   "The swinging doors to the kitchen far on the east wall swish back\n"+
   "and forth, indicating whoever left the table did so just moments\n"+ 
   "before.  A grey slate fireplace covers the entire far, south wall\n"+
   "of the inn, and the bar is directly to your north.\n";

items = ({
   "fireplace", "Grey slate embedded in red mortar covers the entire wall\n"+
                "from floor to ceiling.  The slate is irregular and has fossil\n"+
                "leaves and insects etched in its rough surface from place to\n"+
                "place.  The slate has been set with great care by a master\n"+
                "craftsman, perhaps even an Ogier",
   "meal",      "A thick concoction of carrots, biscuit root, veal and spuds\n"+
                "in white porcelain bowls and two near empty tankards of ale",
   "bowls",     "Plain white in color and large enough for five ladles of soup",
   "bar",       "Solid and well built, it spans the entire north wall of the inn",
   "tankards",  "Tall and slender in shape, with a handle of clear glass",
   "table",     "Several spans long and a third as wide, it stands on four legs\n"+
                "of sturdy hewn timber six snitches square.  Its top is thick\n"+
                "as well, and is stained a rich dark brown from the grease and\n"+
                "spilled drinks",
   "doors",     "Double panels set on hinges with a louvered section in the center\n"+
                "of each door",
   "wall",      "Covered entirely by a grey slate fireplace to the south and a bar north",
   
});

dest_dir = ({
   "/players/fakir/inn/room6.c", "north",
   "/players/fakir/inn/room8.c", "east",
   "/players/fakir/inn/room4.c", "south",
   "/players/fakir/inn/room7.c", "northeast",
   "/players/fakir/inn/room9.c", "southeast",
});

}
