#define TP this_player()
#define TPN this_player()->query_name()
#define TPP this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Winespring Inn";
long_desc =
   "A plump village woman with a shawl over her shoulders sits in a chair\n"+
   "at the side of a table, sipping a tankard of spiced mead.  Three young\n"+
   "brats are fighting over a toy under the table, their bowls of hot stew\n"+
   "steaming and untouched.  A grey slate fireplace covers the entire south\n"+
   "wall of the inn,  and the bar is across the room to your north.  To the\n"+
   "northwest a gleeman sometimes performs for drinks and tips.  A dingy but\n"+
   "open doorway to the east leads to some stairs.\n";

items = ({
   "fireplace", "Grey slate embedded in red mortar covers the entire wall\n"+
                "from floor to cieling.  The slate is irregular and has fossil\n"+
                "leaves and insects etched in its rough surface from place to\n"+
                "place.  The slate has been set with great care by a master\n"+
                "craftsman, perhaps even an ogier",
   "stew",      "A thick concoction of carrots, biscuit root, veal and spuds",
   "mead",      "A fermented drink made from flavored honey, water, and yeast", 
   "bowls",     "Plain white in color and large enough for five ladles of soup",
   "bar",       "Solid and well built, it spans the entire north wall of the inn",
   "tankard",   "Tall and slender in shape, with a handle of clear glass",
   "gleeman",   "His back is toward you, but the cloak he wears makes you drool",
   "table",     "Several spans long and a third as wide, it stands on four legs\n"+
                "of sturdy hewn timber six snitches square.  Its top is thick\n"+
                "as well, and is stained a rich dark brown from the grease and\n"+
                "spilled drinks",
   "woman",     "Her long grey hair is pulled back into two braids which fall\n"+
                "from under an old brown sun hat she wears.  She is intent upon\n"+
                "watching the gleeman perform and does not seem to notice the\n"+
                "children are not eating their food",
   "shawl",     "A long patch of woven cloth that has fringe on each end",
   "brats",     "Parental disipline has been lost on these young holligans\n"+
                "and they are annoying the other patrons of the inn with\n"+
                "their constant fighting under the table",
   "toy",       "A stuffed old sock with button decorations and a corn husk\n"+
                "tied to it, making it resemble a miniature rodent",
   "wall",      "The south wall of the inns commonroom",
   "doorway",   "It is too dark to see it very well, but it appears to lead to\n"+
                "some stairs that access another story of the inn.  It might\n"+
                "have had a door attached at some time in the past, but now\n"+
                "only two bare hinges hang on the right jam.  Perhaps the door\n"+
                "was removed at some time",
   "chair",     "Plain but sturdy and made from the same timber as the tables,\n"+
                "they are able to support the heaviest of men with ease", 
   "stairs",    "They lead up to the guest rooms on the second story of the inn",     
});

dest_dir = ({
   "/players/fakir/inn/room14.c", "north",
   "/players/fakir/inn/room20.c", "east",
   "/players/fakir/inn/room12.c", "south",
   "/players/fakir/inn/room10.c", "west",
   "/players/fakir/inn/room9.c",  "northwest",
   "/players/fakir/inn/room11.c", "southwest",
});

}
