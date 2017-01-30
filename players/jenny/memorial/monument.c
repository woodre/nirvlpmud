inherit "/players/jenny/room";
#include "/players/jenny/define.h"
query_no_fight() { return 1; }
reset(arg) {
set_no_clean(1);
if(!present("mural"))  {
MOCO("/players/jenny/memorial/mural.c"),this_object()); }
    if(arg) return;
    set_light(1);
long_desc=
"You are standing in the center of the monument.  The beautiful\n"+
"marble floor is spotless.  The room is empty, which lets you \n"+
"focus on the large mural covering the walls.  Large stained\n"+      
"glass windows up near the ceiling let in a beautiful array of\n"+
"colored light.\n";
items = ({
"windows","Large stained glass windows with many pretty designs on them",
"floor","The black and white marble floor is so clean, you can see\n"+
                    "your reflection",
"walls","The walls of this domed monument hold an impressive mural",

});

dest_dir = ({
 "/players/jenny/memorial/field","out",
});
}
short() {
return BOLD+WHT+"A Monument to Dreamspeakr"+NORM; }
