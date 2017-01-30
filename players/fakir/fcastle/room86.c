inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "West Tower Battlement";
long_desc =
"   The stairway ends in a final roof top landing at the towers\n"+
"peak.  A short open battlement allows a view of all the castle\n"+
"walls and structure, as well as all the horizons at each point\n"+
"of the compass.  The view is breath-taking.\n";

items = ({
"horizons",   "Mountains, trees, some clouds, and a setting sun",
"peak",       "The topmost part of the tower, or roof",
"battlement", "Similar to a wall, it has merlons and embrasures\n"+
              "built into the topmost section",
"merlons",    "Square upright projections of the wall itself",
"embrasures", "The open space between the merlons", 
"tower",      "The west tower, living quarters to the King and Queed,\n"+
              "as well as important guests to the castle",
"walls",      "Solid stone and very ancient looking",
"landing",    "More of a floor here at the peak of the tower",
"stairway",   "A solid stone stairway that ascends the inner tower wall",

});
dest_dir = ({
   "/players/fakir/fcastle/room58.c", "descend",
});
}


