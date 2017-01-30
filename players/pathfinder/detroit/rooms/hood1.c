/* players/pathfinder/detroit/rooms/hood1 */
 
inherit "room/room";
 
int i;
 
reset(arg) {
if(!present("gangbanger")) {
  for(i=0;i<2;i++) {
  move_object(clone_object("players/pathfinder/detroit/monsters/gangbanger"), this_object());
}
    }
   
 
if(!arg) {
set_light(1);
short_desc = "Bad Neighborhood";
long_desc = "\n"+
"   You get off the main road and take a side street.  The neighborhood you\n"+
"are in looks like it was a warzone, or is this a warzone?  You notice very\n"+
"little activity from normal people except for the hurried rush to get to a\n"+
"place.  There are signs of gang activity everywhere.  From the all to\n"+
"often drug deal in plain sight to the gang paraphernalia laying in\n"+
"abundance all over the street to the grafitti sprayed everywhere.\n"+
"You see virtually no signs that the police are around except for the\n"+
"occassional wailing siren in the distance.  Not so much to your suprise you\n"+
"hear countless loud noises and people screaming to the south.\n";
dest_dir = ( {
"players/pathfinder/detroit/rooms/hood2", "north",
"players/pathfinder/detroit/rooms/war1", "south",
"players/pathfinder/detroit/rooms/entrance", "west",
"players/pathfinder/detroit/rooms/hood4", "east",
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
