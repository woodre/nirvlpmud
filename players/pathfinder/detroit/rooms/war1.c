/* players/pathfinder/detroit/rooms/war1 */
 
inherit "room/room";
 
int i;
 
reset(arg) {
if(!present("leader")) {
  move_object(clone_object("players/pathfinder/detroit/monsters/cripleader"),this_object());
  }
if(!present("recruit")) {
  for(i=0;i<8;i++) {
  move_object(clone_object("players/pathfinder/detroit/monsters/newcrip"),this_object());
}
    }
 
   
 
if(!arg) {
set_light(1);
short_desc = "War Zone";
long_desc = "\n"+
"  You shudder in amazement at what is going on around you.  It looks like\n"+
"a gang turf war, going on right in front of your face.  You get a better\n"+
"look at them as they step closer to you.  Hey, they are coming over to you\n"+
"with some type of leader in the middle.  You think all is fine until they\n"+
"all jump you at once, observed only by the leader.\n";
dest_dir = ( {
"players/pathfinder/detroit/rooms/hood1", "north",
"players/pathfinder/detroit/rooms/war2", "east",
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
 

