/* players/pathfinder/detroit/rooms/house */
 
inherit "room/room";
 
int i;
 
reset(arg) {
if(!present("druggie")) {
  for(i=0;i<5;i++) {
  move_object(clone_object("players/pathfinder/detroit/monsters/druggie"), this_object()); 
}
    }
 
if(!arg) {
set_light(1);
short_desc = "Smoke Filled House";
long_desc = "\n"+
"  You cautiously enter the house.  Upon entering the house you see it is smoke\n"+
"filled.  You can see several people sitting down around you.  They glare\n"+
"at you and get out of their seats, they reach for something and point it\n"+
"at you...\n";
dest_dir = ( {
"players/pathfinder/detroit/rooms/hood2", "leave",
});
items = ({
  "smoke","It smells like crack.",
  "people", "They are in their own little world now that they are high.",
        });
}
}
 
 
 

