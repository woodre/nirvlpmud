/* players/pathfinder/detroit/rooms/newbie1 */
 
inherit "room/room";
 
int i;
 
 
reset(arg) {
  if(!present("bully")) {
  move_object(clone_object("players/pathfinder/detroit/monsters/bully"), this_object());
  }
  if(!present("child")) {
  for(i=0;i<3;i++) {
  move_object(clone_object("players/pathfinder/detroit/monsters/child"), this_object()); 
                   }
                        }
  move_object(clone_object("players/pathfinder/detroit/monsters/bully"), this_object());
 
if(!arg) {
set_light(1);
short_desc = "Playground";
long_desc = "\n"+
"     You stand in the playground of one of Detroits public schools.  You\n"+
"children running around on their recess, climbing over jungle gyms and\n"+
"sliding down slides.  Everything that you see on the playground is grafitti\n"+
"covered.  You see many of the children pointing and laughing at you.  It\n"+
"starts to piss you off.  So much that you really want to kill these\n"+
"bastards.  The road back to Detroit is to the east, you see more playground\n"+
"to the south and west with more little children.  You can see the schoolyard\n"+
"bully around here, beating up on some of the less fortunate children.\n";
dest_dir = ( {
"players/pathfinder/detroit/rooms/newbie2", "north",
"players/pathfinder/detroit/rooms/newbie4", "east",
});
items = ({
  "slide", "A grafitti covered slide with kids sliding down it.",
  "playground", "an area with alot of kids with alot of energy.",
  "children", "Kids pointing and laughing at you.",
  "school", "A Detroit Public School.",
        });
}
}
 

