inherit "/players/jenny/room";
#include "/players/jenny/define.h"
int x;
realm() { return "NT"; }
reset(arg) {
x = 0;
if(!present("cockroach"))  {
MOCO("/players/jenny/bundy/mobs/roach.c"),this_object()); 
MOCO("/players/jenny/bundy/mobs/roach.c"),this_object());
MOCO("/players/jenny/bundy/mobs/roach.c"),this_object());
MOCO("/players/jenny/bundy/mobs/roach.c"),this_object()); }
    if(arg) return;
    set_light(1);
set_search(""+BOLD+"You notice a magazine rack."+NORM+"\n");
set_smell(""+BOLD+"You gag at the awful smell."+NORM+"\n");
short_desc=(""+CYN+"Al Bundy's Bathroom"+NORM+"");
long_desc=
"This is Al's private bathroom.  Al built this to be a man's\n"+
"bathroom.  There is no sink, and no shower.  Al has no use\n"+
"for those things.  The only things in the room are a toilet\n"+
"and a magazine rack.\n";
items = ({
"toilet","This isn't just any toilet.  This is a mighty Ferguson!\n"+
"This has a man's flush!  Try flushing it",
"rack","Al keeps his magazines and newspaper here.  Maybe you could 'take magazine'",
});
dest_dir = ({
 "/players/jenny/bundy/rooms/hb2","garage",
});
}
init() { 
    ::init(); 
   this_player()->set_fight_area();
    add_action("secret","take");
add_action("toilet","flush");
}
secret(arg) {
if(!arg) { return 0; }
if(arg == "magazine") {
if(x) {write("Looks like someone beat you too it.\n");return 1; }
write("You pick up the magazine!\n"); 
say(TPN+" picks up a magazine.\n");
MOCO("/players/jenny/bundy/items/biguns.c"),TP);
x = 1;
return 1; }
}
toilet(arg) { 
if(!arg) { return 0; }
if(arg == "toilet") {
write(""+HIB+"VVVWWWOOOSSSSSHHHHHHHH!!!!!!!"+NORM+"\n");
say(TPN+" flushes the toilet.\n"+
""+HIB+"VVVWWWWWWOOOOOOOOSSSSSSSSSSSSHHHHHHHHHH!!!!!!!"+NORM+"\n");
tell_room("/players/jenny/bundy/rooms/hb2.c",""+HIB+"VVVWWWOOOSSSSSHHHHHHHH!!!!!!!"+NORM+"\n");
return 1; 
}
}
