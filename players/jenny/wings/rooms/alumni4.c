inherit "/players/jenny/room";
#include "/players/jenny/define.h"
realm() { return "NT"; }
reset(arg) {
if(!present("gordie howe"))  {
MOCO("/players/jenny/wings/mobs/closed/ghowe.c"),TO); }
    if(arg) return;
    set_light(1);
     set_smell(BOLD+"The smell of cigar smoke permeates the air."+NORM);
long_desc=
"This large and elegant room is reserved for former Red Wing players.\n"+
"It is a place for them to get together and talk about the good ole days.\n"+      
"It has thick red carpet and cream colored walls, which are decorated\n"+
"with lots of pictures.  This section of the room has a large pool table\n"+
"and a rack of sticks on the wall.\n";
items = ({
"carpet","This is plush thick red carpet is very nice",
"walls","The cream colored walls have wood trim, and lots of pictures",
"wall","The cream colored wall has wood trim, lots of pictures, and a rack\n"+
           "full of pool sticks",
"pictures","Throughout the room are team photos of every Detroit Red\n"+
                  "Wings team",
"table","A very elegant pool table.  Its thick wooden legs have intricate carvings,\n"+
          "and the top is covered in blue felt",
"rack","A fancy wooden stick rack, decorated with carvings of the Red Wings logo.\n"+
           "It holds 10 sticks",
"sticks","Ten high quality pool sticks on a rack",
});

dest_dir = ({
 "/players/jenny/wings/rooms/alumni2","south",
 "/players/jenny/wings/rooms/alumni3","west",
});
}
short() {
return BOLD+RED+"Alumni Room"+NORM; }
init() { 
    ::init(); 
   this_player()->set_fight_area();
}
