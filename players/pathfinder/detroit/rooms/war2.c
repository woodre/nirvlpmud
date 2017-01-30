/* players/pathfinder/detroit/rooms/war2 */
 
inherit "room/room";
 
int i;
 
reset(arg) {
if(!present("leader")) {
  move_object(clone_object("players/pathfinder/detroit/monsters/bloodleader"),this_object());
  }
if(!present("recruit")) {
  for(i=0;i<8;i++) {
  move_object(clone_object("players/pathfinder/detroit/monsters/newblood"), this_object()); 
}
    }
   
 
if(!arg) {
set_light(1);
short_desc = "War Zone";
long_desc = "\n"+
"  From the first second you stepped into this godawful place you could\n"+
"tell something was wrong, but until now, you couldn't tell what it was.\n"+
"You get a sinking feeling something is gonna happen as you see a large\n"+
"group of gang members, probably Bloods, walking toward you.   When they\n"+
"get close enough you feel like, well a duck in a shooting gallery.\n";
 
dest_dir = ( {
"players/pathfinder/detroit/rooms/hood4", "north",
"players/pathfinder/detroit/rooms/war1", "west",
});
items = ({
"grafitti", "They look like gang symbols.",
"police", "Virtually non-existant around these parts.",
"gang", "Many gangs around here have daily shoot-outs over territory.",
"warzone", "This place honestly looks like it could be placed in Germany after WWII",
"drug", "Lots of drugs are pushed around these parts.",
        });
}
}
