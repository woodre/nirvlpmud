/* players/pathfinder/detroit/rooms/hood4 */
 
inherit "room/room";
 
int i;
 
reset(arg) {
if(!present("gangbanger")) {
  for(i=0;i<2;i++) {
  move_object(clone_object("players/pathfinder/detroit/monsters/blood"), this_object());
}
    }
  
 
if(!arg) {
set_light(1);
short_desc = "Bad Neighborhood";
long_desc = "\n"+
"  You hear the police sirens in the distance now.  The gang signs and\n"+
"paraphenalia are still widely abundant on the buildings and road.  You\n"+
"think that no one in the world could live under these conditions but\n"+
"to your suprise there are still many people still quickly scurrying\n"+
"from place to place while avoiding the Bloods.  You can hear some sort\n"+
"of commotion to the south.  It kind of sounds like a gang war\n"+
"but maybe you should go check it out for yourself.\n";
dest_dir = ( {
"players/pathfinder/detroit/rooms/hood3", "north",
"players/pathfinder/detroit/rooms/war2", "south",
"players/pathfinder/detroit/rooms/hood1", "west",
});
items = ({
"grafitti", "They look like gang symbols.",
"police", "Virtually non-existant around these parts.",
"gang", "Many gangs around here have daily shoot-outs over territory.",
"warzone", "This place honestly looks like it could be placed in Germany after WWII",
"drug", "Lots of drugs are pushed around these parts.",
"house", "You get the faint impression that its a drug house.",
        });
}
}
 
