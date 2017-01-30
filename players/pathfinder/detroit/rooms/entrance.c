/* players/pathfinder/detroit/rooms/entrance */
 
inherit "room/room";
 
int i;
 
 
reset(arg) {
  if(!present("sign")) {
  move_object(clone_object("players/pathfinder/detroit/items/sign"),this_object());
   }
  if(!present("dispenser")) {
  move_object(clone_object("players/pathfinder/detroit/items/butdispenser"), this_object());
  }
 
if(!arg) {
set_light(1);
short_desc = "Road to Detroit";
long_desc = "\n"+
"   You are standing uneasily on a busy street corner on the outskirts of\n"+
"the city of Detroit.  There are numerous abandoned cars littering the sides\n"+
"of the road.  You can faintly make out the tall Renaissance Center in the\n"+
"smoggy distance.  You can see alot of activity to the north now that\n"+
"have finished the road.  To the west is a school playground for\n"+
"those players under 5th level and to the east is the south side of \n"+
"Detroit, one of the roughest, toughest neighborhoods in the US.\n"+
"Also, you notice a police station seemingly on the edge of the\n"+
"neighborhood.\n";
dest_dir = ( {
"players/pathfinder/detroit/rooms/city1", "north",
"players/pathfinder/detroit/rooms/newbie1", "west",
"players/pathfinder/detroit/rooms/hood1", "east",
"players/pathfinder/detroit/rooms/pstation", "station",
"room/forest5", "leave",
});
items = ({
  "cars", "abandoned cars riddled with bullet holes.",
  "playground", "an area with alot of kids with alot of energy",
  "renaissance center", "a large tower on the waterfront.",
  "sign","Maybe you should read it.",
        });
}
}
 

