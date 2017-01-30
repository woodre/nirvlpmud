inherit "/players/jenny/room";
#include "/players/jenny/define.h"
realm() { return "NT"; }
reset(arg) {
if(!present("marcy d'arcy"))  {
MOCO("/players/jenny/bundy/mobs/marcy.c"),this_object()); }
if(!present("jefferson d'arcy"))  {
MOCO("/players/jenny/bundy/mobs/jeff.c"),this_object()); }
    if(arg) return;
    set_light(1);
set_smell(""+BOLD+"It smells like Marcy has a nice dinner cooking."+NORM+"\n");
short_desc=(""+RED+"The D'Arcy's House"+NORM+"");
long_desc=
"This is the house where Jefferson and Marcy D'Arcy live.\n"+
"It's tastefully decorated, and much nicer than the house of\n"+
"their neighbors, the Bundy's.  The living room is carpeted, has\n"+
"a couch and a big screen television.  A spotless kitchen can\n"+
"be seen in one direction, and a staircase in the other.\n";
items = ({
"couch","There is an indentation from where Jefferson sits all day",
"television","Jefferson watches this while Marcy is at work",
"kitchen","After a hard day at work, Marcy cooks dinner here",
"staircase","Jefferson takes Marcy up these stairs when he lets her 'ride the Jefferson airplane'",
});
dest_dir = ({
 "/players/jenny/bundy/rooms/3b","out",
});
}
init() { 
    ::init(); 
   this_player()->set_fight_area();
}
