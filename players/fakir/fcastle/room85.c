inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "East Tower Battlement";
long_desc =
"   The stairway ends in a final roof top landing at the\n"+
"towers peak.  A short open battlement allows a view of\n"+
"all the castle walls and structure, as well as all the\n"+
"horizons at each point of the compass.\n";

items = ({
"horizons",   "Mountains, trees, some clouds, and a setting sun",
"peak",       "The topmost part of the tower, or roof",
"battlement", "Similar to a wall, it has merlons and embrasures\n"+
              "built into the topmost section",
"merlons",    "Square upright projections of the wall itself",
"embrasures", "The open space between the merlons", 
"tower",      "The east tower, living quarters to the Prince and Princess,\n"+
              "children to the King and Queen",
"walls",      "Solid stone and very ancient looking",
"landing",    "More of a floor here on the top of the tower",
"stairway",   "A solid stone stairway that ascends the inner tower wall",

});
dest_dir = ({
   "/players/fakir/fcastle/room48.c", "descend",
});
}


