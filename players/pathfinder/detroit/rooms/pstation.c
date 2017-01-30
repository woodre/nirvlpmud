/* players/pathfinder/detroit/rooms/pstation */
 
inherit "room/room";
 
int i;
 
realm() { return "NT"; }
 
reset(arg) {
if((!present("nevers")) && (!present("budsen"))) {
  move_object(clone_object("players/pathfinder/detroit/monsters/nevers"), this_object()); 
  move_object(clone_object("players/pathfinder/detroit/monsters/budsen"), this_object());
    }  
 
if(!arg) {
set_light(1);
short_desc = "13 Precinct";
long_desc = "\n"+
"  You are standing in the 13 Precinct police station.  You see two police\n"+
"officers you seem to remember from the news and then you think 'Malice\n"+
"Green' and it comes to you!  They are Officer Larry Nevers and Officer\n"+
"Walter Budsen.  But how did they get out?  You ponder that as you see\n"+
"the two officers throw something across the room.... could it be?  Is it?\n"+
"IT IS!  Its Malice Green's head and they are throwing it around the room\n"+
"like a softball!\n";
dest_dir = ( {
"players/pathfinder/detroit/rooms/entrance", "leave",
});
items = ({
  
        });
}
}
 
 
 

