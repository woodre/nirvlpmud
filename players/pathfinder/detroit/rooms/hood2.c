/* players/pathfinder/detroit/rooms/hood2 */
 
inherit "room/room";
 
int i;
 
reset(arg) {
if(!present("gangbanger")) {
  for(i=0;i<2;i++) {
  move_object(clone_object("players/pathfinder/detroit/monsters/latincount"), this_object());
}
    }
   
 
if(!arg) {
set_light(1);
short_desc = "Bad Neighborhood";
long_desc = "\n"+
"  You are in a terribly run-down neighborhood.  There is grafitti\n"+
"everwhere.  You see a troubling amount of gang activity with every\n"+
"second you look.  You see a lot of houses around here, maybe you could\n"+
"'enter' them...\n";
dest_dir = ( {
"players/pathfinder/detroit/rooms/hood1", "south",
"players/pathfinder/detroit/rooms/hood3", "east",
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
init() {
  ::init();
  add_action("enter","enter");
       }
       
enter(){
  object tp;
  i = random(5) + 1;
  if(i == 5) {
    call_other(this_player(),"move_player","house#players/pathfinder/detroit/rooms/house5");
    return 1;
  } else if(i == 4) {
    call_other(this_player(),"move_player","house#players/pathfinder/detroit/rooms/house4");
    return 1;
  } else if(i == 3) {
    call_other(this_player(),"move_player","house#players/pathfinder/detroit/rooms/house3");
    return 1;
  } else if(i == 2) {
    call_other(this_player(),"move_player","house#players/pathfinder/detroit/rooms/house2");
    return 1;
  } else {
    call_other(this_player(),"move_player","house#players/pathfinder/detroit/rooms/house");
    return 1;
  }
}
 
 

