inherit "/players/jenny/room";
#include "/players/jenny/define.h"
int door;
reset(arg) {
set_no_clean(1);
if(!present("oliver north"))  {
MOCO("/players/jenny/80s/mobs/north.c"),this_object()); }
    if(arg) return;
    set_light(1);
set_listen(BOLD+"The shredding machine produces a constant hum."+NORM);
long_desc=
"This is a small room, which looks like it is mainly used for storage.\n"+
"There is nothing fancy about it at all.  There are no windows, or\n"+
"decorations, and the walls are plain white.  A few boxes are scattered\n"+
"across the floor.  One whole wall is lined with metal filing cabinets.\n"+
"The only piece of furniture in the room is a chair, which sits next to \n"+
"shredding machine.\n";
short_desc=(HIW+BOLD+"Storage Room"+NORM);
items = ({
"walls","Plain white walls.  One wall is lined with filing cabinets",
"boxes","These boxes are filled with papers and documents",
"cabinets","These are grey metal filing cabinets.  They look like they\n"+
              "may hold some important papers",
"chair","A plain folding chair.  It is made out of wood",
"papers","These are important papers relating to Iran-Contra",
"documents","These are important documents relating to Iran-Contra",
"floor","A dark hardwood floor",
"shredding machine","This is a small machine, the purpose of which is to shred papers\n"+
"so they can never be read",
"machine","This is a small machine, the purpose of which is to shred papers\n"+
"so they can never be read",
});
dest_dir = ({
 "/players/jenny/80s/rooms/5","out",
});
}
