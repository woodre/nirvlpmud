inherit "/players/jenny/room";
#include "/players/jenny/define.h"
int replacements;
reset(arg) {
if(!present("jukebox"))  {
MOCO("/players/jenny/dukes/items/jukebox.c"),this_object()); }
if(!present("daisy duke"))  {
MOCO("/players/jenny/dukes/mobs/daisy.c"),this_object()); }
replacements = 1;
    if(arg) return;
    set_light(1);
set_smell(BOLD+"The bar smells like beer and fried chicken"+NORM);
short_desc=(BOLD+""+YEL+"The Boar's Nest"+NORM);
long_desc=
"The Boar's nest is one of the most popular, and one of the\n"+
"only bars and restaurants in Hazzard.  It is owned by Boss\n"+
"Hogg.  On Friday night, you will often catch people singing\n"+
"to pay off their speeding tickets.  There are plenty of\n"+
"tables and chairs, and many decorations on the walls.  Boss\n"+
"Hogg's private office is in the room to the east.\n";  
items = ({
"tables","People sit at these tables to enjoy their overpriced food and drinks",
"chairs","Simple wooden chairs",
"decorations","You see a bunch of decorative signs and pictures on the walls",
"walls","These white walls have decorations all over them.  It doesn't look too bad",
});
dest_dir = ({
 "/players/jenny/dukes/rooms/nest2","east",
 "/players/jenny/dukes/rooms/r10","out",
});
}
init() { 
    ::init();
add_action("scabs","search");
}
scabs(arg)  {
if(replacements == 1) {
write(BOLD+"You notice Coy Duke."+NORM+"\n");
if(!present("coy duke"))  {
MOCO("/players/jenny/dukes/mobs/coy.c"),this_object()); }
replacements = 2;
return 1;  }
if(replacements == 2) {
write(BOLD+"You notice Vance Duke."+NORM+"\n");
if(!present("vance duke"))  {
MOCO("/players/jenny/dukes/mobs/vance.c"),this_object()); }
replacements = 3;
return 1;  }
}
