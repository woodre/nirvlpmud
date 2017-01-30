/* players/pathfinder/detroit/rooms/backroom2 */
 
inherit "room/room";
 
int i;
 
reset(arg) {
if(!present("fixer")) {
  move_object(clone_object("players/pathfinder/detroit/monsters/tyrone"), this_object()); 
    }
 
if(!arg) {
set_light(1);
short_desc = "Dealing Room";
long_desc = "\n"+
"  You see a tall black man standing in the center of the room who looks\n"+
"like the most important figure in the room.  You can see him selling\n"+
"things to the people of the room who are leaving and entering.  He looks\n"+
"at you and says type 'list' to see whats I got, and 'buy #' to buy.\n";
dest_dir = ( {
"players/pathfinder/detroit/rooms/house", "leave",
});
items = ({
  "drugs", "An assortment of drugs.",
  "people", "Entering and exiting the room to get more dope.",
        });
}
}
 
 
 
 

