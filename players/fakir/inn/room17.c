#define TP this_player()
#define TPN this_player()->query_name()
#define TPP this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Winespring Inn";
long_desc =
   "Racks of shelves line all four walls from floor to ceiling.  Each\n"+
   "shelf is filled with a different type of kitchen supply and is \n"+
   "organized by date of purchase.  The lower shelves are stocked with\n"+
   "the more common items, such as sugar, flour, and spices.  The top\n"+
   "shelf is stacked with extra plates, cups, mugs, bowls, and cloth\n"+
   "napkins and towels.  The room is spotless except for some flour\n"+
   "that has fallen near a crack in the floor.\n";

items = ({
   "racks",   "More a figure of speech, it is the upright braces holding the\n"+
              "shelves which make the whole unit appear to be a rack",
   "shelves", "Eight in all, vertically seperated from each other by a quarter\n"+
              "span or so.  They wrap around all four walls",
   "walls",   "All four walls are covered in shelving stacked with kitchen supplies",
   "floor",   "Colored stones with a flat rough surface set in a strange sort\n"+
              "of pattern",
   "ceiling", "It is dome shaped and of the same stone as the floor",
   "shelf",   "One snitch thick and about twenty snitches deep, it wraps\n"+
              "all the way around the four walls. There are eight of them\n"+
              "from floor to ceiling",
   "sugar",   "Canvas bags with a date and 'SUGAR' written across the front",
   "flour",   "Canvas bags with a date and 'FLOUR' written across the front.\n"+
              "One of the bags has tipped on its side and a small bit of flour\n"+
              "has spilled to the floor",
   "spices",  "Glass jars of various cooking spices. All the jars are labeled\n"+
              "as to the date purchased and what peddler sold it",
   "plates",  "Round dinner plates used to serve customers in the commonroom of the inn",
   "cups",    "Earthenware cups with a small handle, used for hot drinks",
   "mugs",    "Roughly twice the size of the cups, they are used for serving broth and\n"+
              "other thin soups.  They are not used often",
   "bowls",   "White porcelain bowls used for serving the thick soups and stews the inn\n"+
              "is famous for",
   "napkins", "White cloth napkins folded in fourths and stacked neatly in rows",
   "towels",  "Bar towels, folded and stacked neatly in rows",
   "crack",   "What looked like a crack is actually a very thin seam running through\n"+
              "the middle of one of the rocks in the floor",
   "seam",    "You might try and 'lift' the rock",
});

dest_dir = ({
   
   "/players/fakir/inn/room18.c", "south",
   
   
});

}
init() {
  ::init();
  add_action("lift","lift");
}
lift(arg)  {
  write("You lift the rock but find nothing today.\n");
  say  (TPN+" lifts the rock but finds nothing there.\n");
  return 1;
}
