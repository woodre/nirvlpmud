/* players/pathfinder/detroit/rooms/backroom */
 
inherit "room/room";
 
int i;
 
reset(arg) {
if(!present("fixer")) {
  move_object(clone_object("players/pathfinder/detroit/monsters/fixer"), this_object()); 
    }
 
if(!arg) {
set_light(1);
short_desc = "Fixer's Room";
long_desc = "\n"+
"  You follow the light to a back room where there is a single light\n"+
"hanging from the ceiling.  There is a man here looking over a multitude\n"+
"of weaponry.  Everything from a 9mm Beretta, to a M60 Machine Gun!\n"+
"He seems friendly enough to you as you enter the room.\n";
dest_dir = ( {
"players/pathfinder/detroit/rooms/house3", "leave",
});
items = ({
  "weapons", "A variety of weapons.",
        });
}
}
 
 
 
 

