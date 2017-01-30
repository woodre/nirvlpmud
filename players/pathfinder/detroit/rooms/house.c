/* players/pathfinder/detroit/rooms/house */
 
inherit "room/room";
 
int i;
 
reset(arg) {
/*
 if(!present("tyrone")) {
  move_object(clone_object("players/pathfinder/detroit/monsters/tyrone"), this_object());
}
*/
 
if(!arg) {
set_light(1);
short_desc = "Drug House";
long_desc = "\n"+
"  You enter the house.  Upon entering you are overwelmed by the pot smoke.\n"+
"You see a large man go into the back room where a bit of activity is.  You\n"+
"wonder how someone could run an operation like this without being brought\n"+
"down by the police...\n";
dest_dir = ( {
"players/pathfinder/detroit/rooms/backroom2","backroom",
"players/pathfinder/detroit/rooms/hood2", "leave",
});
items = ({
  "drugs", "There are various drugs laying all over the place.",
  "people", "They are in their own little world now that they are high.",
  "dealer", "Must be in the back room.",
  "house", "Old condemned house that hasn't been raided for drugs yet.",
        });
}
}
 
