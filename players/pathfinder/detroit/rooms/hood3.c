/* players/pathfinder/detroit/rooms/hood3 */
 
inherit "room/room";
 
int i;
 
reset(arg) {
if(!present("gangbanger")) {
  for(i=0;i<2;i++) {
  move_object(clone_object("players/pathfinder/detroit/monsters/crip"), this_object());
}
    }
  
 
if(!arg) {
set_light(1);
short_desc = "Bad Neighborhood";
long_desc = "\n"+
"  You are in a neighborhood that can be better called a warzone than \n"+
"anything else.  There are gang signs painted everywhere riddled with\n"+
"countless bullet holes as this territory has been taken and retaken by\n"+
"different gangs and dozens of their ranks have fallen.  You hear the\n"+
"wailing of a police siren nearby and doesn't show any signs of fading\n"+
"in the near future.  You see no one except for the brave around these\n"+
"parts without a Smith and Wesson in their hands.  You notice a dimly\n"+
"lit alley(I wonder what could be in there).\n";
dest_dir = ( {
"players/pathfinder/detroit/rooms/hood4", "south",
"players/pathfinder/detroit/rooms/hood2", "west",
"players/pathfinder/detroit/rooms/alley", "alley",
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
 

