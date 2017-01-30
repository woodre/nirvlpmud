/* players/pathfinder/detroit/rooms/entrance */
/* changed by jenny to give recipical exits to Joe Louis Arena - april 2001 */
 
inherit "room/room";
 
int i;
 
 
reset(arg) {
if(!present("lady")) {
  for(i=0;i<2;i++) {
    move_object(clone_object("players/pathfinder/detroit/monsters/oldlady"),this_object());
   }
  }
 
if(!arg) {
set_light(1);
short_desc = "City of Detroit";
long_desc = "\n"+
"  You are standing more comfortably at a fairly busy street corner in the\n"+
"City of Detroit.  There are many people going about their legitimate\n"+
"everyday business all around you.  You notice several places that\n"+
"catch you attention.  To the east is a travel agency and has\n"+
"posters of different places plastered on its windows.\n"+
"and to the west looks like a bar.  To the north you see more of\n"+
"this glorious city, including Joe Louis Arena, and to the south you\n"+
"can see the bad side of this city.  A parking lot entrance is right\n"+
"in front of you.\n";
dest_dir = ( {
/*
"players/pathfinder/detroit/rooms/city2", "north",
"players/pathfinder/detroit/rooms/bar", "west",
*/
"players/pathfinder/detroit/rooms/agency", "east",
"players/pathfinder/detroit/rooms/entrance", "south",
});
items = ({
  "renaissance center", "a large tower on the waterfront.",
  "people", "Going about their everyday business.",
  "stores", "Open to the general public.  Doing good business.",
  "shops", "Open to the general public.  Doing good business.",
  "joe louis arena","A large hockey arena where the Detroit Red Wings play\n"+
                    "their home games",
  "arena","A large hockey arena where the Detroit Red Wings play\n"+
                    "their home games",
  "parking lot","A Joe Louis Arena parking lot.  You could enter it",
  "lot","A Joe Louis Arena parking lot.  You could enter it",
  "entrance","A Joe Louis Arena parking lot.  You could enter it",
        });
}
}
init() { 
    ::init(); 
   add_action("lot","enter");
}
lot(arg) {
if(arg == "lot" || arg == "parking lot" || arg == "entrance" || arg == "the parking lot") {
this_player()->move_player("into the parking lot#players/jenny/wings/rooms/parking.c");
return 1;}}
